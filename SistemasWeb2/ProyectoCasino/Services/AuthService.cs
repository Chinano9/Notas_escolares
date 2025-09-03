using System;
using System.Collections.Generic;
using System.Security.Claims;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Authentication;
using Microsoft.AspNetCore.Authentication.Cookies;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.Logging;
using Npgsql;
using ProyectoCasino.Models;

namespace ProyectoCasino.Services
{
    public class AuthService
    {
        private readonly IConfiguration _configuration;
        private readonly ILogger<AuthService> _logger;
        private readonly string _connectionString;

        public AuthService(IConfiguration configuration, ILogger<AuthService> logger)
        {
            _configuration = configuration;
            _logger = logger;
            _connectionString = _configuration.GetConnectionString("DefaultConnection");
        }

        /// <summary>
        /// Valida las credenciales del usuario
        /// </summary>
        public async Task<(bool success, Usuario user)> ValidateUserAsync(string email, string password)
        {
            try
            {
                using var connection = new NpgsqlConnection(_connectionString);
                await connection.OpenAsync();

                // Consulta para obtener la información del usuario y verificar sus credenciales
                string query = @"
                    SELECT id, email, username, password, nombre, apellido,
                           fecha_nacimiento, saldo, fecha_registro
                    FROM users
                    WHERE email = @Email";

                using var command = new NpgsqlCommand(query, connection);
                command.Parameters.AddWithValue("@Email", email);

                using var reader = await command.ExecuteReaderAsync();

                if (await reader.ReadAsync())
                {
                    int id = reader.GetInt32(0);
                    string storedEmail = reader.GetString(1);
                    string nombreUsuario = reader.IsDBNull(2) ? string.Empty : reader.GetString(2);
                    string storedHash = reader.GetString(3);
                    string nombre = reader.IsDBNull(4) ? string.Empty : reader.GetString(4);
                    string apellido = reader.IsDBNull(5) ? string.Empty : reader.GetString(5);
                    DateTime? fechaNacimiento = reader.IsDBNull(6) ? null : (DateTime?)reader.GetDateTime(6);
                    decimal saldo = reader.IsDBNull(7) ? 0 : reader.GetDecimal(7);
                    DateTime fechaRegistro = reader.IsDBNull(8) ? DateTime.Now : reader.GetDateTime(8);

                    // Verificar la contraseña
                    bool isValid = VerifyPassword(password, storedHash);

                    if (isValid)
                    {
                        var user = new Usuario
                        {
                            Id = id,
                            Email = storedEmail,
                            NombreUsuario = nombreUsuario,
                            Nombre = nombre,
                            Apellido = apellido,
                            FechaNacimiento = fechaNacimiento,
                            Saldo = saldo,
                            FechaRegistro = fechaRegistro
                        };

                        return (true, user);
                    }
                }

                return (false, null);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error al validar usuario: {Message}", ex.Message);
                return (false, null);
            }
        }

        /// <summary>
        /// Registra un nuevo usuario en la base de datos
        /// </summary>
        public async Task<(bool success, string message)> RegisterUserAsync(string email, string password, string nombre, string apellido, DateTime? fechaNacimiento)
        {
            try
            {
                // Validar edad mínima (18 años)
                if (fechaNacimiento.HasValue)
                {
                    var age = DateTime.Today.Year - fechaNacimiento.Value.Year;
                    if (fechaNacimiento.Value.Date > DateTime.Today.AddYears(-age)) age--;

                    if (age < 18)
                    {
                        return (false, "Debes ser mayor de 18 años para registrarte.");
                    }
                }

                using var connection = new NpgsqlConnection(_connectionString);
                await connection.OpenAsync();

                // Verificar si el usuario ya existe
                string checkQuery = "SELECT COUNT(*) FROM usuarios WHERE email = @Email";
                using (var checkCommand = new NpgsqlCommand(checkQuery, connection))
                {
                    checkCommand.Parameters.AddWithValue("@Email", email);
                    long count = (long)await checkCommand.ExecuteScalarAsync();
                    if (count > 0)
                    {
                        return (false, "El email ya está registrado.");
                    }
                }

                // Generar hash de la contraseña
                string passwordHash = HashPassword(password);

                // Insertar el nuevo usuario
                string insertQuery = @"
                    INSERT INTO users (email, nombre_usuario, password_hash, nombre, apellido,
                                          fecha_nacimiento, fecha_registro)
                    VALUES (@Email, @NombreUsuario, @PasswordHash, @Nombre, @Apellido,
                            @FechaNacimiento, @FechaRegistro)
                    RETURNING id";

                using var command = new NpgsqlCommand(insertQuery, connection);

                command.Parameters.AddWithValue("@Email", email);
                command.Parameters.AddWithValue("@NombreUsuario", email); // Usando email como nombre de usuario
                command.Parameters.AddWithValue("@PasswordHash", passwordHash);
                command.Parameters.AddWithValue("@Nombre", nombre ?? (object)DBNull.Value);
                command.Parameters.AddWithValue("@Apellido", apellido ?? (object)DBNull.Value);
                command.Parameters.AddWithValue("@FechaNacimiento", fechaNacimiento ?? (object)DBNull.Value);
                command.Parameters.AddWithValue("@FechaRegistro", DateTime.Now);

                int newUserId = (int)await command.ExecuteScalarAsync();
                return (true, "Usuario registrado correctamente.");
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error al registrar usuario: {Message}", ex.Message);
                return (false, "Error al registrar el usuario: " + ex.Message);
            }
        }

        /// <summary>
        /// Inicia sesión del usuario mediante cookies
        /// </summary>
        public async Task SignInAsync(HttpContext httpContext, Usuario user, bool isPersistent = false)
        {
            var claims = new List<Claim>
            {
                new Claim(ClaimTypes.NameIdentifier, user.Id.ToString()),
                new Claim(ClaimTypes.Name, user.NombreUsuario ?? user.Email),
                new Claim(ClaimTypes.Email, user.Email),
                new Claim("Nombre", user.Nombre ?? string.Empty),
                new Claim("Apellido", user.Apellido ?? string.Empty),
                new Claim("Saldo", user.Saldo.ToString())
            };

            var claimsIdentity = new ClaimsIdentity(
                claims, CookieAuthenticationDefaults.AuthenticationScheme);

            var authProperties = new AuthenticationProperties
            {
                IsPersistent = isPersistent,
                ExpiresUtc = DateTimeOffset.UtcNow.AddHours(3) // Sesión de 3 horas
            };

            await httpContext.SignInAsync(
                CookieAuthenticationDefaults.AuthenticationScheme,
                new ClaimsPrincipal(claimsIdentity),
                authProperties);

            _logger.LogInformation("Usuario {Email} ha iniciado sesión", user.Email);
        }

        /// <summary>
        /// Cierra la sesión del usuario
        /// </summary>
        public async Task SignOutAsync(HttpContext httpContext)
        {
            await httpContext.SignOutAsync(CookieAuthenticationDefaults.AuthenticationScheme);
            _logger.LogInformation("Usuario ha cerrado sesión");
        }

        #region Métodos de ayuda para contraseñas

        /// <summary>
        /// Crea un hash de la contraseña utilizando SHA256
        /// </summary>
        private string HashPassword(string password)
        {
            using var sha256 = SHA256.Create();
            byte[] bytes = sha256.ComputeHash(Encoding.UTF8.GetBytes(password));

            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < bytes.Length; i++)
            {
                builder.Append(bytes[i].ToString("x2"));
            }
            return builder.ToString();
        }

        /// <summary>
        /// Verifica si una contraseña coincide con su hash
        /// </summary>
        private bool VerifyPassword(string password, string storedHash)
        {
            string passwordHash = HashPassword(password);
            return passwordHash.Equals(storedHash);
        }

        #endregion
    }
}

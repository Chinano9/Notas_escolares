using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace ProyectoCasino.Models
{
    [Table("users")]
    public class Usuario
    {
        [Key]
        [Column("id")]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public long Id { get; set; }

        [Required(ErrorMessage = "El nombre de usuario es obligatorio")]
        [Column("username")]
        public string NombreUsuario { get; set; }

        [Required(ErrorMessage = "La contraseña es obligatoria")]
        [Column("password")]
        public string Password { get; set; }

        [Column("role_id")]
        public long? RolId { get; set; }

        [Column("chips")]
        public long Fichas { get; set; } = 0;

        [Required(ErrorMessage = "La fecha de nacimiento es obligatoria")]
        [Column("fecha_de_nacimiento")]
        [DataType(DataType.Date)]
        public DateTime FechaNacimiento { get; set; }

        [Required(ErrorMessage = "El nombre es obligatorio")]
        [Column("name")]
        public string Nombre { get; set; }

        [Required(ErrorMessage = "El apellido es obligatorio")]
        [Column("lastname")]
        public string Apellido { get; set; }

        [Required(ErrorMessage = "El email es obligatorio")]
        [EmailAddress(ErrorMessage = "El formato del email no es válido")]
        [Column("email")]
        public string Email { get; set; }

        // Propiedades de navegación
        [ForeignKey("RolId")]
        public virtual Rol Rol { get; set; }

        public virtual ICollection<SesionJuego> SesionesJuego { get; set; }
        public virtual ICollection<Transaccion> Transacciones { get; set; }
        public virtual Empleado Empleado { get; set; }
    }
}

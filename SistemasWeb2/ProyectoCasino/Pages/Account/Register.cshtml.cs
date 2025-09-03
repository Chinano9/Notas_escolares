using System;
using System.ComponentModel.DataAnnotations;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Logging;
using ProyectoCasino.Services;
using ProyectoCasino.Models;

namespace ProyectoCasino.Pages.Account
{
    public class RegisterModel : PageModel
    {
        private readonly AuthService _authService;
        private readonly ILogger<RegisterModel> _logger;

        public RegisterModel(AuthService authService, ILogger<RegisterModel> logger)
        {
            _authService = authService;
            _logger = logger;
        }

        [BindProperty]
        public InputModel Input { get; set; }

        public string ReturnUrl { get; set; }

        [TempData]
        public string ErrorMessage { get; set; }

        public class InputModel
        {
            [Required(ErrorMessage = "El nombre es obligatorio")]
            [Display(Name = "Nombre")]
            public string FirstName { get; set; }

            [Required(ErrorMessage = "El apellido es obligatorio")]
            [Display(Name = "Apellido")]
            public string LastName { get; set; }

            [Required(ErrorMessage = "El email es obligatorio")]
            [EmailAddress(ErrorMessage = "El formato del email no es válido")]
            [Display(Name = "Email")]
            public string Email { get; set; }

            [Required(ErrorMessage = "La contraseña es obligatoria")]
            [StringLength(100, ErrorMessage = "La {0} debe tener al menos {2} y máximo {1} caracteres de longitud.", MinimumLength = 8)]
            [DataType(DataType.Password)]
            [Display(Name = "Contraseña")]
            public string Password { get; set; }

            [DataType(DataType.Password)]
            [Display(Name = "Confirmar contraseña")]
            [Compare("Password", ErrorMessage = "La contraseña y la confirmación no coinciden.")]
            public string ConfirmPassword { get; set; }

            [Required(ErrorMessage = "La fecha de nacimiento es obligatoria")]
            [DataType(DataType.Date)]
            [Display(Name = "Fecha de Nacimiento")]
            public DateTime DateOfBirth { get; set; }
        }

        public void OnGet(string returnUrl = null)
        {
            ReturnUrl = returnUrl ?? Url.Content("~/");
        }

        public async Task<IActionResult> OnPostAsync(string returnUrl = null)
        {
            returnUrl ??= Url.Content("~/");

            if (ModelState.IsValid)
            {
                // Registrar el usuario usando nuestro servicio personalizado
                var (success, message) = await _authService.RegisterUserAsync(
                    Input.Email,
                    Input.Password,
                    Input.FirstName,
                    Input.LastName,
                    Input.DateOfBirth);

                if (success)
                {
                    _logger.LogInformation("Usuario creado correctamente: {Email}", Input.Email);

                    // Validar credenciales del usuario recién creado
                    var (isValid, user) = await _authService.ValidateUserAsync(Input.Email, Input.Password);
                    if (isValid && user != null)
                    {
                        await _authService.SignInAsync(HttpContext, user);
                        return LocalRedirect(returnUrl);
                    }

                    return RedirectToPage("./Login");
                }
                else
                {
                    ModelState.AddModelError(string.Empty, message);
                }
            }

            // Si llegamos aquí, algo falló, volvemos a mostrar el formulario
            return Page();
        }
    }
}

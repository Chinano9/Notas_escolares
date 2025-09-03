using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Logging;
using ProyectoCasino.Services;
using ProyectoCasino.Models;

namespace ProyectoCasino.Pages.Account
{
    public class LoginModel : PageModel
    {
        private readonly AuthService _authService;
        private readonly ILogger<LoginModel> _logger;

        public LoginModel(AuthService authService, ILogger<LoginModel> logger)
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
            [Required(ErrorMessage = "El email es obligatorio")]
            [EmailAddress(ErrorMessage = "El formato del email no es válido")]
            public string Email { get; set; }

            [Required(ErrorMessage = "La contraseña es obligatoria")]
            [DataType(DataType.Password)]
            public string Password { get; set; }

            [Display(Name = "Recordarme")]
            public bool RememberMe { get; set; }
        }

        public void OnGet(string returnUrl = null)
        {
            if (!string.IsNullOrEmpty(ErrorMessage))
            {
                ModelState.AddModelError(string.Empty, ErrorMessage);
            }

            ReturnUrl = returnUrl ?? Url.Content("~/");
        }

        public async Task<IActionResult> OnPostAsync(string returnUrl = null)
        {
            returnUrl ??= Url.Content("~/");

            if (ModelState.IsValid)
            {
                // Validar credenciales usando nuestro servicio personalizado
                var (isValid, user) = await _authService.ValidateUserAsync(Input.Email, Input.Password);

                if (isValid && user != null)
                {
                    _logger.LogInformation("Usuario conectado: {Email}", Input.Email);
                    await _authService.SignInAsync(HttpContext, user, Input.RememberMe);
                    return LocalRedirect(returnUrl);
                }

                ModelState.AddModelError(string.Empty, "Email o contraseña incorrectos.");
                return Page();
            }

            // Si llegamos aquí, algo falló, redisplay form
            return Page();
        }
    }
}

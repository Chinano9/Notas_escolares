using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Logging;
using ProyectoCasino.Services;

namespace ProyectoCasino.Pages.Account
{
    public class LogoutModel : PageModel
    {
        private readonly AuthService _authService;
        private readonly ILogger<LogoutModel> _logger;

        public LogoutModel(AuthService authService, ILogger<LogoutModel> logger)
        {
            _authService = authService;
            _logger = logger;
        }

        public void OnGet()
        {
            // Esta página solo muestra la confirmación de cierre de sesión
        }

        public async Task<IActionResult> OnPostAsync()
        {
            // Cerrar la sesión del usuario
            await _authService.SignOutAsync(HttpContext);
            _logger.LogInformation("Usuario desconectado.");

            return RedirectToPage("/Index");
        }
    }
}

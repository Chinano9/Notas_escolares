using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using System.Collections.Generic;
using System.Linq;

namespace Actividad1.Pages
{
    public class IndexModel : PageModel
    {
        private readonly ILogger<IndexModel> _logger;

        public IndexModel(ILogger<IndexModel> logger)
        {
            _logger = logger;
            InitializeMenuItems();
        }

        // Modelos para los artículos del menú
        public class MenuItem
        {
            public string Name { get; set; }
            public string Category { get; set; }
            public List<MenuOption> Options { get; set; } = new List<MenuOption>();
            public bool HasVariants => Options.Count > 0;
            public decimal BasePrice => HasVariants ? Options.Min(o => o.Price) : 0;
        }

        public class MenuOption
        {
            public string Name { get; set; }
            public decimal Price { get; set; }
        }

        // Variables para el estado del pedido
        public List<MenuItem> MenuItems { get; set; } = new List<MenuItem>();
        public bool OrderCompleted { get; set; } = false;
        public decimal Subtotal { get; set; } = 0;
        public decimal Discount { get; set; } = 0;
        public decimal Total { get; set; } = 0;

        [BindProperty]
        public bool ApplyDiscount { get; set; } = false;

        // Variables para la selección de productos
        [BindProperty]
        public string SelectedFood { get; set; }
        [BindProperty]
        public string SelectedOption { get; set; }
        [BindProperty]
        public int Quantity { get; set; } = 1;

        // Lista para almacenar los productos seleccionados
        [BindProperty]
        public List<OrderDetail> OrderDetails { get; set; } = new List<OrderDetail>();

        public class OrderDetail
        {
            public string Food { get; set; }
            public string Option { get; set; }
            public int Quantity { get; set; }
            public decimal Price { get; set; }
            public decimal Total => Price * Quantity;
        }

        private void InitializeMenuItems()
        {
            MenuItems.Add(new MenuItem
            {
                Name = "Hamburguesa",
                Category = "Platos Principales",
                Options = new List<MenuOption>
                {
                    new MenuOption { Name = "Sola", Price = 80 },
                    new MenuOption { Name = "Combo", Price = 120 }
                }
            });

            MenuItems.Add(new MenuItem
            {
                Name = "Hotdog",
                Category = "Platos Principales",
                Options = new List<MenuOption>
                {
                    new MenuOption { Name = "Solo", Price = 50 },
                    new MenuOption { Name = "Combo", Price = 90 }
                }
            });

            MenuItems.Add(new MenuItem
            {
                Name = "Pizza",
                Category = "Platos Principales",
                Options = new List<MenuOption>
                {
                    new MenuOption { Name = "Individual", Price = 50 },
                    new MenuOption { Name = "Mediana", Price = 80 },
                    new MenuOption { Name = "Grande", Price = 120 }
                }
            });

            MenuItems.Add(new MenuItem
            {
                Name = "Papas",
                Category = "Complementos",
                Options = new List<MenuOption>
                {
                    new MenuOption { Name = "Chica", Price = 20 },
                    new MenuOption { Name = "Mediana", Price = 40 }
                }
            });

            MenuItems.Add(new MenuItem
            {
                Name = "Helado",
                Category = "Postres",
                Options = new List<MenuOption>
                {
                    new MenuOption { Name = "Sencillo", Price = 20 },
                    new MenuOption { Name = "Doble", Price = 30 }
                }
            });

            MenuItems.Add(new MenuItem
            {
                Name = "Sodas",
                Category = "Bebidas",
                Options = new List<MenuOption>
                {
                    new MenuOption { Name = "Regular", Price = 30 }
                }
            });

            MenuItems.Add(new MenuItem
            {
                Name = "Agua",
                Category = "Bebidas",
                Options = new List<MenuOption>
                {
                    new MenuOption { Name = "Regular", Price = 20 }
                }
            });
        }

        public void OnGet()
        {
            // Reset the order
            OrderDetails = new List<OrderDetail>();
            OrderCompleted = false;
            Subtotal = 0;
            Discount = 0;
            Total = 0;
            ApplyDiscount = false;

            _logger.LogInformation("Página cargada en OnGet");
        }

        public IActionResult OnPost()
        {
            _logger.LogInformation("Iniciando proceso de pedido con {count} items", OrderDetails?.Count ?? 0);

            // Si no hay productos seleccionados, redirigir a la página principal
            if (OrderDetails == null || OrderDetails.Count == 0)
            {
                _logger.LogWarning("Intento de finalizar pedido sin productos");
                return RedirectToPage();
            }

            // Calcular totales
            Subtotal = OrderDetails.Sum(item => item.Total);
            Discount = ApplyDiscount ? Math.Round(Subtotal * 0.1m, 2) : 0;
            Total = Subtotal - Discount;

            // Marcar el pedido como completado
            OrderCompleted = true;

            _logger.LogInformation($"Pedido completado exitosamente. Subtotal: {Subtotal}, Descuento: {Discount}, Total: {Total}");
            return Page();
        }

        public IActionResult OnPostAddToOrder()
        {
            // Inicializar la lista si es null
            if (OrderDetails == null)
            {
                OrderDetails = new List<OrderDetail>();
            }

            // Validar que se haya seleccionado comida, opción y cantidad
            if (!string.IsNullOrEmpty(SelectedFood) && !string.IsNullOrEmpty(SelectedOption) && Quantity > 0)
            {
                // Encontrar el precio correspondiente
                var menuItem = MenuItems.FirstOrDefault(m => m.Name == SelectedFood);
                if (menuItem != null)
                {
                    var option = menuItem.Options.FirstOrDefault(o => o.Name == SelectedOption);
                    if (option != null)
                    {
                        // Agregar al pedido
                        OrderDetails.Add(new OrderDetail
                        {
                            Food = SelectedFood,
                            Option = SelectedOption,
                            Quantity = Quantity,
                            Price = option.Price
                        });

                        _logger.LogInformation($"Agregado al pedido: {SelectedFood} ({SelectedOption}) - Cantidad: {Quantity}");
                    }
                }
            }

            // Recalcular el subtotal
            Subtotal = OrderDetails.Sum(item => item.Total);

            return Page();
        }

        public IActionResult OnPostRemoveItem(int index)
        {
            // Verificar que la lista y el índice sean válidos
            if (OrderDetails != null && index >= 0 && index < OrderDetails.Count)
            {
                var item = OrderDetails[index];
                _logger.LogInformation($"Eliminando item: {item.Food} ({item.Option})");
                OrderDetails.RemoveAt(index);

                // Recalcular el subtotal
                Subtotal = OrderDetails.Sum(item => item.Total);
            }
            else
            {
                _logger.LogWarning($"Intento de eliminar ítem con índice inválido: {index}");
            }

            return Page();
        }

        public IActionResult OnPostReset()
        {
            _logger.LogInformation("Reseteo del pedido solicitado");
            OrderDetails = new List<OrderDetail>();
            OrderCompleted = false;
            ApplyDiscount = false;
            Subtotal = 0;
            Discount = 0;
            Total = 0;
            return RedirectToPage();
        }

        // Métodos para agrupar artículos del menú por categoría
        public IEnumerable<string> GetCategories()
        {
            return MenuItems.Select(i => i.Category).Distinct();
        }

        public IEnumerable<MenuItem> GetItemsByCategory(string category)
        {
            return MenuItems.Where(i => i.Category == category);
        }

        // Método para obtener la cantidad total de artículos en el pedido
        public int GetTotalItems()
        {
            return OrderDetails.Sum(item => item.Quantity);
        }
    }
}

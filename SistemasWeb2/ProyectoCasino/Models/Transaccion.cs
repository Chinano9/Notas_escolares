using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace ProyectoCasino.Models
{
    [Table("transactions")]
    public class Transaccion
    {
        [Key]
        [Column("id")]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public long Id { get; set; }

        [Column("user_id")]
        public long? UsuarioId { get; set; }

        [Required(ErrorMessage = "El monto es obligatorio")]
        [Column("amount")]
        public decimal Monto { get; set; }

        [Column("transaction_type")]
        [Required(ErrorMessage = "El tipo de transacción es obligatorio")]
        public string TipoTransaccion { get; set; } // Valores posibles: "entry", "exit"

        [Column("created_at")]
        public DateTime FechaCreacion { get; set; }

        // Propiedad de navegación
        [ForeignKey("UsuarioId")]
        public virtual Usuario Usuario { get; set; }
    }
}

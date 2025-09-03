using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace ProyectoCasino.Models
{
    [Table("earnings")]
    public class Ganancia
    {
        [Key]
        [Column("id")]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public long Id { get; set; }

        [Column("game_id")]
        public long? JuegoId { get; set; }

        [Required(ErrorMessage = "El monto es obligatorio")]
        [Column("amount")]
        public decimal Monto { get; set; }

        [Column("recorded_at")]
        public DateTime FechaRegistro { get; set; }

        // Propiedad de navegación
        [ForeignKey("JuegoId")]
        public virtual Juego Juego { get; set; }
    }
}

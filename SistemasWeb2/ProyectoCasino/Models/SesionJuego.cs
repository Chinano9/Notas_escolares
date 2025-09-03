using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace ProyectoCasino.Models
{
    [Table("game_sessions")]
    public class SesionJuego
    {
        [Key]
        [Column("id")]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public long Id { get; set; }

        [Column("game_id")]
        public long JuegoId { get; set; }

        [Column("user_id")]
        public long UsuarioId { get; set; }

        [Column("start_time")]
        public DateTime FechaInicio { get; set; }

        [Column("end_time")]
        public DateTime? FechaFin { get; set; }

        [Column("money_spent")]
        public long DineroGastado { get; set; }

        // Propiedades de navegación
        [ForeignKey("JuegoId")]
        public virtual Juego Juego { get; set; }

        [ForeignKey("UsuarioId")]
        public virtual Usuario Usuario { get; set; }
    }
}

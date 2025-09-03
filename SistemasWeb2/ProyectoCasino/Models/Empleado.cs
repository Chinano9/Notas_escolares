using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace ProyectoCasino.Models
{
    [Table("employees")]
    public class Empleado
    {
        [Key]
        [Column("id")]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public long Id { get; set; }

        [Column("user_id")]
        public long? UsuarioId { get; set; }

        [Required(ErrorMessage = "La posición es obligatoria")]
        [Column("position")]
        public string Posicion { get; set; }

        // Propiedad de navegación
        [ForeignKey("UsuarioId")]
        public virtual Usuario Usuario { get; set; }
    }
}

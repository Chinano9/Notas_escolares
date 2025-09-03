using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace ProyectoCasino.Models
{
    [Table("games")]
    public class Juego
    {
        [Key]
        [Column("id")]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public long Id { get; set; }

        [Required(ErrorMessage = "El nombre del juego es obligatorio")]
        [Column("name")]
        public string Nombre { get; set; }

        [Column("description")]
        public string Descripcion { get; set; }

        // Propiedades de navegación
        public virtual ICollection<SesionJuego> SesionesJuego { get; set; }
        public virtual ICollection<Ganancia> Ganancias { get; set; }
    }
}

using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace ProyectoCasino.Models
{
    [Table("roles")]
    public class Rol
    {
        [Key]
        [Column("id")]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public long Id { get; set; }

        [Required(ErrorMessage = "El nombre del rol es obligatorio")]
        [Column("name")]
        public string Nombre { get; set; }

        // Navegación inversa - Colección de usuarios con este rol
        public virtual ICollection<Usuario> Usuarios { get; set; }
    }
}

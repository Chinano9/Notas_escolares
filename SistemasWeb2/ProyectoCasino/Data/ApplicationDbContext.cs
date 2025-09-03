using Microsoft.EntityFrameworkCore;
using ProyectoCasino.Models;

namespace ProyectoCasino.Data
{
    public class ApplicationDbContext : DbContext
    {
        public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options)
            : base(options)
        {
        }

        public DbSet<Usuario> Usuarios { get; set; }
        public DbSet<Rol> Roles { get; set; }
        public DbSet<Juego> Juegos { get; set; }
        public DbSet<SesionJuego> SesionesJuego { get; set; }
        public DbSet<Empleado> Empleados { get; set; }
        public DbSet<Ganancia> Ganancias { get; set; }
        public DbSet<Transaccion> Transacciones { get; set; }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);

            // Configurar las restricciones de tipo de transacción
            modelBuilder.Entity<Transaccion>()
                .Property(t => t.TipoTransaccion)
                .HasConversion<string>();

            // Establecer valores predeterminados
            modelBuilder.Entity<Usuario>()
                .Property(u => u.Fichas)
                .HasDefaultValue(0);

            modelBuilder.Entity<Ganancia>()
                .Property(g => g.FechaRegistro)
                .HasDefaultValueSql("now()");

            modelBuilder.Entity<SesionJuego>()
                .Property(s => s.FechaInicio)
                .HasDefaultValueSql("now()");

            modelBuilder.Entity<Transaccion>()
                .Property(t => t.FechaCreacion)
                .HasDefaultValueSql("now()");

            // Configurar las relaciones
            modelBuilder.Entity<Usuario>()
                .HasOne(u => u.Rol)
                .WithMany(r => r.Usuarios)
                .HasForeignKey(u => u.RolId);

            modelBuilder.Entity<Usuario>()
                .HasOne(u => u.Empleado)
                .WithOne(e => e.Usuario)
                .HasForeignKey<Empleado>(e => e.UsuarioId);

            modelBuilder.Entity<Usuario>()
                .HasMany(u => u.SesionesJuego)
                .WithOne(s => s.Usuario)
                .HasForeignKey(s => s.UsuarioId);

            modelBuilder.Entity<Usuario>()
                .HasMany(u => u.Transacciones)
                .WithOne(t => t.Usuario)
                .HasForeignKey(t => t.UsuarioId);

            modelBuilder.Entity<Juego>()
                .HasMany(j => j.SesionesJuego)
                .WithOne(s => s.Juego)
                .HasForeignKey(s => s.JuegoId);

            modelBuilder.Entity<Juego>()
                .HasMany(j => j.Ganancias)
                .WithOne(g => g.Juego)
                .HasForeignKey(g => g.JuegoId);
        }
    }
}

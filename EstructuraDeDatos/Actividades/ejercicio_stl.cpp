#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Para std::sort y std::find_if
#include <limits>    // Para la validación de entrada

// --- Clase Alumno (sin cambios significativos, solo const en getters) ---
class Alumno {
private:
    long codigo;
    std::string nombre;
    double nota;

public:
    Alumno(long c, std::string n, double no) : codigo(c), nombre(n), nota(no) {}

    long getCodigo() const { return codigo; }
    std::string getNombre() const { return nombre; }
    double getNota() const { return nota; }

    void setNombre(std::string n) { nombre = n; }
    void setNota(double no) { nota = no; }

    void mostrarDatos() const {
        std::cout << "  -> Codigo: " << codigo
                  << " | Nombre: " << nombre
                  << " | Nota: " << nota << std::endl;
    }
};

// --- Clase para gestionar el registro usando STL ---
class RegistroAlumnosSTL {
private:
    std::vector<Alumno> datos;

public:
    void ingresarDatos() {
        long codigo;
        std::string nombre;
        double nota;

        std::cout << "\n--- Ingresar Nuevo Alumno ---\n";
        std::cout << "Ingrese codigo: ";
        std::cin >> codigo;
        std::cout << "Ingrese nombre completo: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, nombre);
        std::cout << "Ingrese nota: ";
        std::cin >> nota;

        // Construye el objeto directamente en el vector para mayor eficiencia
        datos.emplace_back(codigo, nombre, nota);
        std::cout << "\n[+] Alumno agregado exitosamente.\n";
    }

    void mostrarDatos() const {
        std::cout << "\n=== Lista de Alumnos Registrados ===\n";
        if (datos.empty()) {
            std::cout << "No hay alumnos registrados.\n";
            return;
        }
        for (const auto& al : datos) {
            al.mostrarDatos();
        }
        std::cout << "====================================\n";
    }

    void buscarPorCodigo(long codigo) const {
        // Usamos std::find_if con una lambda para buscar al alumno
        auto it = std::find_if(datos.begin(), datos.end(),
            [codigo](const Alumno& al) {
                return al.getCodigo() == codigo;
            });

        if (it != datos.end()) {
            std::cout << "\n[+] Alumno encontrado:\n";
            it->mostrarDatos();
        } else {
            std::cout << "\n[!] Error: Codigo no encontrado.\n";
        }
    }

    void modificarDatos(long codigo) {
        auto it = std::find_if(datos.begin(), datos.end(),
            [codigo](const Alumno& al) {
                return al.getCodigo() == codigo;
            });

        if (it != datos.end()) {
            std::string nombre;
            double nota;
            std::cout << "\n--- Modificando Alumno con Codigo " << codigo << " ---\n";
            std::cout << "Ingrese el nuevo nombre: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, nombre);
            std::cout << "Ingrese la nueva nota: ";
            std::cin >> nota;

            it->setNombre(nombre);
            it->setNota(nota);
            std::cout << "\n[+] Datos actualizados correctamente.\n";
        } else {
            std::cout << "\n[!] Error: Codigo no encontrado.\n";
        }
    }

    void eliminarDatos(long codigo) {
        auto it = std::find_if(datos.begin(), datos.end(),
            [codigo](const Alumno& al) {
                return al.getCodigo() == codigo;
            });

        if (it != datos.end()) {
            datos.erase(it); // erase es eficiente en std::vector
            std::cout << "\n[-] Alumno eliminado exitosamente.\n";
        } else {
            std::cout << "\n[!] Error: Codigo no encontrado.\n";
        }
    }

    void ordenarPorCodigo() {
        // std::sort es muy eficiente (normalmente IntroSort, O(N log N))
        std::sort(datos.begin(), datos.end(),
            [](const Alumno& a, const Alumno& b) {
                return a.getCodigo() < b.getCodigo();
            });
        std::cout << "\n[*] Alumnos ordenados por codigo.\n";
    }
};

void mostrarMenuSTL() {
    std::cout << "\n======== MENU DE ALUMNOS (STL) ========\n";
    std::cout << "1. Ingresar alumno\n";
    std::cout << "2. Mostrar todos los alumnos\n";
    std::cout << "3. Buscar alumno por codigo\n";
    std::cout << "4. Modificar datos de alumno\n";
    std::cout << "5. Eliminar alumno\n";
    std::cout << "6. Ordenar alumnos por codigo\n";
    std::cout << "0. Salir\n";
    std::cout << "=========================================\n";
    std::cout << "Seleccione una opcion: ";
}

int main() {
    RegistroAlumnosSTL programa;
    int opcion;
    long codigo;

    do {
        mostrarMenuSTL();
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cout << "[!] Error: Entrada no valida. Intente de nuevo.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = -1;
            continue;
        }

        switch (opcion) {
            case 1: programa.ingresarDatos(); break;
            case 2: programa.mostrarDatos(); break;
            case 3:
                std::cout << "Ingrese el codigo a buscar: ";
                std::cin >> codigo;
                programa.buscarPorCodigo(codigo);
                break;
            case 4:
                std::cout << "Ingrese el codigo del alumno a modificar: ";
                std::cin >> codigo;
                programa.modificarDatos(codigo);
                break;
            case 5:
                std::cout << "Ingrese el codigo del alumno a eliminar: ";
                std::cin >> codigo;
                programa.eliminarDatos(codigo);
                break;
            case 6: programa.ordenarPorCodigo(); break;
            case 0: std::cout << "\nSaliendo del programa. ¡Hasta luego!\n"; break;
            default: std::cout << "\n[!] Opcion no valida. Por favor, intente de nuevo.\n"; break;
        }
    } while (opcion != 0);

    return 0;
}

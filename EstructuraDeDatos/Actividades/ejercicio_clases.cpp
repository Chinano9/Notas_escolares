#include <iostream>
#include <string>
#include <limits> // Necesario para la validación de entrada

// --- Clase para representar a un Alumno ---
class Alumno {
private:
    long codigo;
    std::string nombre;
    double nota;

public:
    // Constructor por defecto
    Alumno() : codigo(0), nombre(""), nota(0.0) {}

    // Getters (marcados como const porque no modifican el objeto)
    long getCodigo() const { return codigo; }
    std::string getNombre() const { return nombre; }
    double getNota() const { return nota; }

    // Setters
    void setCodigo(long c) { codigo = c; }
    void setNombre(std::string n) { nombre = n; }
    void setNota(double no) { nota = no; }

    void mostrarDatos() const {
        std::cout << "  -> Codigo: " << codigo
                  << " | Nombre: " << nombre
                  << " | Nota: " << nota << std::endl;
    }
};

// --- Clase para gestionar el registro de alumnos ---
class RegistroAlumnos {
private:
    static const int MAX_ALUMNOS = 100;
    Alumno datos[MAX_ALUMNOS];
    int numAlu;

    // Función privada para buscar el índice de un alumno por su código
    // Devuelve el índice si lo encuentra, o -1 si no.
    int _buscarIndice(long codigo) const {
        for (int i = 0; i < numAlu; i++) {
            if (datos[i].getCodigo() == codigo) {
                return i;
            }
        }
        return -1; // No encontrado
    }

public:
    RegistroAlumnos() : numAlu(0) {}

    void ingresarDatos() {
        if (numAlu >= MAX_ALUMNOS) {
            std::cout << "\n[!] Error: No hay espacio para mas alumnos.\n";
            return;
        }

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

        datos[numAlu].setCodigo(codigo);
        datos[numAlu].setNombre(nombre);
        datos[numAlu].setNota(nota);
        numAlu++;
        std::cout << "\n[+] Alumno agregado exitosamente.\n";
    }

    void mostrarDatos() const {
        std::cout << "\n=== Lista de Alumnos Registrados ===\n";
        if (numAlu == 0) {
            std::cout << "No hay alumnos registrados.\n";
            return;
        }
        for (int i = 0; i < numAlu; i++) {
            datos[i].mostrarDatos();
        }
        std::cout << "====================================\n";
    }

    void buscarPorCodigo(long codigo) const {
        int indice = _buscarIndice(codigo);
        if (indice != -1) {
            std::cout << "\n[+] Alumno encontrado:\n";
            datos[indice].mostrarDatos();
        } else {
            std::cout << "\n[!] Error: Codigo no encontrado.\n";
        }
    }

    void modificarDatos(long codigo) {
        int indice = _buscarIndice(codigo);
        if (indice != -1) {
            std::string nombre;
            double nota;

            std::cout << "\n--- Modificando Alumno con Codigo " << codigo << " ---\n";
            std::cout << "Ingrese el nuevo nombre: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, nombre);
            std::cout << "Ingrese la nueva nota: ";
            std::cin >> nota;

            datos[indice].setNombre(nombre);
            datos[indice].setNota(nota);
            std::cout << "\n[+] Datos actualizados correctamente.\n";
        } else {
            std::cout << "\n[!] Error: Codigo no encontrado.\n";
        }
    }

    void eliminarDatos(long codigo) {
        int indice = _buscarIndice(codigo);
        if (indice != -1) {
            // Desplazar los elementos para llenar el espacio
            for (int j = indice; j < numAlu - 1; j++) {
                datos[j] = datos[j + 1];
            }
            numAlu--;
            std::cout << "\n[-] Alumno eliminado exitosamente.\n";
        } else {
            std::cout << "\n[!] Error: Codigo no encontrado.\n";
        }
    }

    void ordenarPorCodigo() {
        // Algoritmo de ordenación Burbuja (simple para este ejemplo)
        for (int i = 0; i < numAlu - 1; i++) {
            for (int j = 0; j < numAlu - i - 1; j++) {
                if (datos[j].getCodigo() > datos[j + 1].getCodigo()) {
                    Alumno temp = datos[j];
                    datos[j] = datos[j + 1];
                    datos[j + 1] = temp;
                }
            }
        }
        std::cout << "\n[*] Alumnos ordenados por codigo.\n";
    }
};

void mostrarMenu() {
    std::cout << "\n======= MENU DE ALUMNOS (ARREGLO) =======\n";
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
    RegistroAlumnos programa;
    int opcion;
    long codigo;

    do {
        mostrarMenu();
        std::cin >> opcion;

        // Validación de entrada simple
        if (std::cin.fail()) {
            std::cout << "[!] Error: Entrada no valida. Intente de nuevo.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = -1; // Asigna una opción inválida para continuar el bucle
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

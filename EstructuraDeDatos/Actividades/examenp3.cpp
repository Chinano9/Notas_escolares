#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class Estudiante {
private:
    string nombre;
    double calificacion;

public:
    Estudiante(string n, double c) : nombre(n), calificacion(c) {}

    string getNombre() const { return nombre; }
    double getCalificacion() const { return calificacion; }


    void setNombre(string n) { nombre = n; }
    void setCalificacion(double c) { calificacion = c; }
};


bool compararPorCalificacionAscendente(const Estudiante& a, const Estudiante& b) {
    return a.getCalificacion() < b.getCalificacion();
}

bool compararPorCalificacionDescendente(const Estudiante& a, const Estudiante& b) {
    return a.getCalificacion() > b.getCalificacion();
}

bool compararPorNombre(const Estudiante& a, const Estudiante& b) {
    return a.getNombre() < b.getNombre();
}


void mostrarEstudiantes(const vector<Estudiante>& estudiantes) {
    cout << "\nLista de Estudiantes:" << endl;
    cout << setw(20) << left << "Nombre" << "Calificacion" << endl;
    cout << string(40, '-') << endl;

    for (const auto& estudiante : estudiantes) {
        cout << setw(20) << left << estudiante.getNombre()
             << fixed << setprecision(1) << estudiante.getCalificacion() << endl;
    }
}

int main() {
    vector<Estudiante> estudiantes;
    char continuar;

    do {

        string nombre;
        double calificacion;

        cout << "\nIngrese el nombre del estudiante: ";
        cin >> nombre;

        do {
            cout << "Ingrese la calificacion (0-10): ";
            cin >> calificacion;
            if (calificacion < 0 || calificacion > 10) {
                cout << "Calificacion invalida. Por favor ingrese un valor entre 0 y 10." << endl;
            }
        } while (calificacion < 0 || calificacion > 10);

        estudiantes.push_back(Estudiante(nombre, calificacion));

        if (estudiantes.size() < 5) {
            cout << "\nDebe ingresar al menos " << 5 - estudiantes.size()
                 << " estudiantes mas." << endl;
            continuar = 's';
        } else {
            cout << "\n¿Desea agregar otro estudiante? (s/n): ";
            cin >> continuar;
        }
    } while (tolower(continuar) == 's');


    int opcion;
    do {
        cout << "\nOpciones de ordenamiento:" << endl;
        cout << "1. Por calificacion (mayor a menor)" << endl;
        cout << "2. Por calificacion (menor a mayor)" << endl;
        cout << "3. Por nombre (orden alfabetico)" << endl;
        cout << "4. Agregar otro alumno" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                sort(estudiantes.begin(), estudiantes.end(), compararPorCalificacionDescendente);
                cout << "\nOrdenado por calificacion (mayor a menor) usando std::sort" << endl;
                mostrarEstudiantes(estudiantes);
                break;
            case 2:
                sort(estudiantes.begin(), estudiantes.end(), compararPorCalificacionAscendente);
                cout << "\nOrdenado por calificacion (menor a mayor) usando std::sort" << endl;
                mostrarEstudiantes(estudiantes);
                break;
            case 3:
                sort(estudiantes.begin(), estudiantes.end(), compararPorNombre);
                cout << "\nOrdenado por nombre usando std::sort" << endl;
                mostrarEstudiantes(estudiantes);
                break;
            case 4:
                {
                    string nombre;
                    double calificacion;

                    cout << "\nIngrese el nombre del estudiante: ";
                    cin >> nombre;

                    do {
                        cout << "Ingrese la calificacion (0-10): ";
                        cin >> calificacion;
                        if (calificacion < 0 || calificacion > 10) {
                            cout << "Calificacion invalida. Por favor ingrese un valor entre 0 y 10." << endl;
                        }
                    } while (calificacion < 0 || calificacion > 10);

                    estudiantes.push_back(Estudiante(nombre, calificacion));
                }
                break;
            case 5:
                cout << "\nPrograma terminado." << endl;
                break;
            default:
                cout << "\nOpcion invalida." << endl;
        }
    } while (opcion != 5);

    return 0;
}

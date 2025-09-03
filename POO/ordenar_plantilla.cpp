/*
Elabore un programa que al menos tenga una plantilla de clases, constructor y destructor elaborado por usted y que ordene un conjunto de N datos(hasta 20)
que ingresan por teclado de menor a mayor y que estos datos sean de tipo entero, double o char.

Repetir mientras el usuario lo desee.


*/

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

template <typename T>
class Ordenador {
private:
    vector<T> datos;
    int cantidad;

    void ordenarPorInsercion() {
        for (int i = 1; i < cantidad; ++i) {
            T clave = datos[i];
            int j = i - 1;
            
            while (j >= 0 && datos[j] > clave) {
                datos[j + 1] = datos[j];
                j = j - 1;
            }
            datos[j + 1] = clave;
        }
    }

public:
    
    Ordenador(int n) : cantidad(n) {
        datos.reserve(n);
    }

    
    ~Ordenador() {
        datos.clear();
        cout << "Memoria liberada para el ordenador de tipo " << typeid(T).name() << endl;
    }

    
    void ingresarDatos() {
        cout << "Ingrese " << cantidad << " datos de tipo " << typeid(T).name() << ":" << endl;
        for (int i = 0; i < cantidad; ++i) {
            T valor;
            cout << "Dato " << i + 1 << ": ";
            cin >> valor;
            datos.push_back(valor);
        }
    }

    
    void ordenar() {
        ordenarPorInsercion();
    }

    // Método para mostrar datos
    void mostrar() {
        cout << "Datos ordenados:" << endl;
        for (const auto& dato : datos) {
            cout << dato << " ";
        }
        cout << endl;
    }
};

int main() {
    char continuar;

    do {
        int tipo, n;
        
        cout << "\nSeleccione el tipo de datos a ordenar:" << endl;
        cout << "1. Entero (int)" << endl;
        cout << "2. Punto flotante (double)" << endl;
        cout << "3. Caracter (char)" << endl;
        cout << "Opcion: ";
        cin >> tipo;

        do {
            cout << "Ingrese la cantidad de datos a ordenar (1-20): ";
            cin >> n;
        } while (n < 1 || n > 20);

        switch (tipo) {
            case 1: {
                Ordenador<int> ordInt(n);
                ordInt.ingresarDatos();
                ordInt.ordenar();
                ordInt.mostrar();
                break;
            }
            case 2: {
                Ordenador<double> ordDouble(n);
                ordDouble.ingresarDatos();
                ordDouble.ordenar();
                ordDouble.mostrar();
                break;
            }
            case 3: {
                Ordenador<char> ordChar(n);
                ordChar.ingresarDatos();
                ordChar.ordenar();
                ordChar.mostrar();
                break;
            }
            default:
                cout << "Opcion no valida." << endl;
        }

        cout << "\nDesea ordenar otro conjunto de datos? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    cout << "Programa terminado." << endl;
    return 0;
}
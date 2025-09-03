/* Elaborar un programa que usando la libreria STL (USANDO SOLO VECTOR Y LIST) ingresen un conjunto de
 * 8 elementos y despues se ingresen uno a uno hasta 5 y se siguen hasta 2 para
 * finalmente mostrar la lista final
 */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    vector<int> numeros;
    list<int> listaFinal;
    int elemento;


    // Ingreso de los primeros 8 elementos al vector
    cout << "\nIngrese 8 elementos iniciales:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << "Elemento " << (i + 1) << ": ";
        cin >> elemento;
        numeros.push_back(elemento);
    }

    // Ingreso de hasta 5 elementos adicionales
    cout << "\nIngrese hasta 5 elementos adicionales (ingrese -999 para terminar antes):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Elemento adicional " << (i + 1) << ": ";
        cin >> elemento;

        if (elemento == -999) {
            break;
        }

        numeros.push_back(elemento);
    }

    // Ingreso de hasta 2 elementos finales
    cout << "\nIngrese hasta 2 elementos finales (ingrese -999 para terminar antes):" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "Elemento final " << (i + 1) << ": ";
        cin >> elemento;

        if (elemento == -999) {
            break;
        }

        numeros.push_back(elemento);
    }

    // Transferir los elementos del vector a la lista
    for (const auto& num : numeros) {
        listaFinal.push_back(num);
    }

    // Mostrar la lista final
    cout << "\nLista final de elementos:" << endl;
    int contador = 1;
    for (const auto& item : listaFinal) {
        cout << "Elemento " << contador << ": " << item << endl;
        contador++;
    }

    return 0;
}

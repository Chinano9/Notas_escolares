/**

Primer examen parcial sección Practica_2025b

Escriba un programa que genere una lista de 100 números aleatorios entre el 1000 y el 5000, elimine todos aquellos que aparecen repetidos, cuente cuantos quedaron, Esos números serán usados como claves de acceso asignadas a un grupo de empleados. Muestre: Lista inicial, lista sin las repeticiones, cuantos son, solo los últimos 10. Inserte a partir de la quinta posición los números 1964, 1968, 1972 y 1976, verifique que no estén repetidos y si es así elimine las repeticiones, muestre la lista final.
Debe usar para ello al menos una de las siguientes librerías STL:
<list>, <vector>

Desmenuzando el problema:
1. Generar 100 numeros aleatorios entre 1000 y 5000. (Estos numeros se pueden generar con el Marsene twiseter)
2. Almacenar esos números en un vector
3. Mostrar la lista inicial de numeros. (Se muestra directmente despues de almacenar los numeros para evitar confusiones despues)
4. Eliminar los números repetidos . (se puede usar unique() despues de ordenar o usar find() para verificar si ya existe el numero en la lista)
5. Contar cuántos números únicos quedaron. (Usar size () de la lista)
6. Mostrar solo los ultimos 10 números unicos. (Usar un iterador para recorrern la lista desde el final)
7. Insertar los números 1964, 1968, 1972 y 1976 a partir de la quinta posición
8. Verificar y eliminar cualuier repetición después de la inserción
9. Mostrar la lista final de números
 */

#include<list>
#include<vector>
#include<iostream>
#include<ctime>
#include<random>

using namespace std;

int main(){
    vector<int> numeros;
    list<int> listaFinal;
    int numero;

    // Generar 100 números aleatorios entre 1000 y 5000
    std::mt19937 rng(static_cast<unsigned int>(time(0))); // Semilla basada en el tiempo
    std::uniform_int_distribution<int> dist(1000, 5000);
    // Inicializacion del vector con 100 numeros aleatorios
    for (int i = 0; i < 100; i++) {
        numero = dist(rng);
        numeros.push_back(numero);
    }

    // Mostrar la lista inicial

    cout << "\nLista inicial de 100 numeros aleatorios:\n";
    for (const auto& num : numeros) {
        cout << num << " ";
    }
    cout<<endl;

    // Eliminar duplicados usando una lista
    for (const auto& num : numeros) {
        if (std::find(listaFinal.begin(), listaFinal.end(), num) == listaFinal.end()) {
            listaFinal.push_back(num);
        }
    }

    // Mostrar la lista sin repeticiones

    cout << "\nLista sin repeticiones:\n";
    for (const auto& num : listaFinal) {
        cout << num << " ";
    }
    cout<<endl;

    // Contar cuantos números quedaron
    int cantidad = listaFinal.size();
    cout << "\nCantidad de numeros sin repeticiones: " << cantidad << endl;

    // Mostrar solo los últimos 10 números
    cout << "\nUltimos 10 numeros sin repeticiones:\n";
    auto it = listaFinal.end();
    for (int i = 0; i < 10 && it != listaFinal.begin(); i++) {
        // Si la lista por alguna razon tiene menos de 10 elementos se evita el desbordamiento
        --it;
        cout << *it << " ";
    }
    cout << endl;

    // Insertar nuevos números a partir de la quinta posición
    int nuevosNumeros[4] = {1964, 1968, 1972, 1976};
    it = listaFinal.begin();

    advance(it, 4); // Esto es para iniciar el iterador desde la quinta posicion (0,1,2,3,4)

    for (const auto& num : nuevosNumeros) {
        if (std::find(listaFinal.begin(), listaFinal.end(), num) == listaFinal.end()) {
            listaFinal.insert(it, num);
        }
    }

    // Borrar duplicados

    listaFinal.unique();


    // Mostrar la lista final
    cout << "\nLista final despues de insertar nuevos numeros:\n";
    for (const auto& num : listaFinal) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

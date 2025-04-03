#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Ordenamiento {
private:
    std::vector<int> numeros;

    int particion(int izquierda, int derecha);
    void quicksort(int izquierda, int derecha);

public:
    Ordenamiento();
    ~Ordenamiento();
    void generarNumeros(int cantidad, int min, int max);
    void ordenar();
    void mostrarNumeros(const std::string& mensaje);
};

Ordenamiento::Ordenamiento() {
    std::srand(std::time(0));
}

Ordenamiento::~Ordenamiento() {}

void Ordenamiento::generarNumeros(int cantidad, int min, int max) {
    numeros.clear();
    for (int i = 0; i < cantidad; ++i) {
        numeros.push_back(std::rand() % (max - min + 1) + min);
    }
}

int Ordenamiento::particion(int izquierda, int derecha) {
    int pivote = numeros[derecha];
    int i = izquierda - 1;

    for (int j = izquierda; j < derecha; ++j) {
        if (numeros[j] >= pivote) { // Modificado para orden descendente
            ++i;
            std::swap(numeros[i], numeros[j]);
        }
    }
    std::swap(numeros[i + 1], numeros[derecha]);
    return i + 1;
}

void Ordenamiento::quicksort(int izquierda, int derecha) {
    if (izquierda < derecha) {
        int indicePivote = particion(izquierda, derecha);
        quicksort(izquierda, indicePivote - 1);
        quicksort(indicePivote + 1, derecha);
    }
}

void Ordenamiento::ordenar() {
    quicksort(0, numeros.size() - 1);
}

void Ordenamiento::mostrarNumeros(const std::string& mensaje) {
    std::cout << mensaje << std::endl;
    for (int num : numeros) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    Ordenamiento ordenamiento;
    char respuesta;

    do {
        ordenamiento.generarNumeros(100, 1000, 5000);
        ordenamiento.mostrarNumeros("Lista original:");
        ordenamiento.ordenar();
        ordenamiento.mostrarNumeros("Lista ordenada de mayor a menor:");

        std::cout << "¿Desea repetir? (s/n): ";
        std::cin >> respuesta;
    } while (respuesta == 's' || respuesta == 'S');

    return 0;
}

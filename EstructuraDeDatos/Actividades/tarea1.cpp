#include <iostream>

class MiVector {
private:
    int* datos;
    int capacidad;
    int tam; // tamaño actual

    // Duplica la capacidad del vector cuando está lleno
    void redimensionar() {
        std::cout << "\n--- Redimensionando de " << capacidad << " a " << capacidad * 2 << " ---\n";
        int nuevaCapacidad = (capacidad == 0) ? 1 : capacidad * 2;
        int* nuevo = new int[nuevaCapacidad];
        for (int i = 0; i < tam; i++) {
            nuevo[i] = datos[i];
        }
        delete[] datos;
        datos = nuevo;
        capacidad = nuevaCapacidad;
    }

public:
    // Constructor
    MiVector(int cap = 4) {
        capacidad = cap;
        tam = 0;
        datos = new int[capacidad];
    }

    // Destructor
    ~MiVector() {
        delete[] datos;
    }

    // Agrega un elemento al final
    void push_back(int valor) {
        if (tam == capacidad) {
            redimensionar();
        }
        datos[tam++] = valor;
    }

    int size() const {
        return tam;
    }

    // Sobrecarga de operador para acceso (lectura/escritura)
    int& operator[](int i) {
        return datos[i];
    }

    // Versión const para objetos constantes
    const int& operator[](int i) const {
        return datos[i];
    }
};

int main() {
    std::cout << "Creando un vector con capacidad inicial de 4...\n";
    MiVector v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    std::cout << "Vector actual: ";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\nEl vector está lleno. Agregando otro elemento para forzar la redimensión.\n";

    v.push_back(50); // Esto provocará la redimensión

    std::cout << "Vector final: ";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

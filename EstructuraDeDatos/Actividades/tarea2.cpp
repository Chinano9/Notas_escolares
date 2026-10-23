#include <iostream>

class MiArray {
private:
    int datos[3];
    static const int TAM_FIJO = 3;

public:
    // Constructor que inicializa el array
    MiArray(int a, int b, int c) {
        datos[0] = a;
        datos[1] = b;
        datos[2] = c;
    }

    // Operador para acceso de solo lectura
    int operator[](int i) const {
        return datos[i];
    }

    int size() const {
        return TAM_FIJO;
    }
};

int main() {
    MiArray a(15, 25, 35);
    std::cout << "Contenido del MiArray de tamaño fijo: ";
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

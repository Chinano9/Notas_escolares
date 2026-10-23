#include <iostream>
#include <iomanip>

class Vector3 {
private:
    double datos[3];
public:
    Vector3(double a = 0.0, double b = 0.0, double c = 0.0) {
        datos[0] = a;
        datos[1] = b;
        datos[2] = c;
    }

    // Operador para acceso de solo lectura
    double operator[](int i) const {
        return datos[i];
    }

    // El producto escalar es una operación entre dos vectores
    static double productoEscalar(const Vector3& v1, const Vector3& v2) {
        double resultado = 0.0;
        for (int i = 0; i < 3; i++) {
            resultado += v1[i] * v2[i];
        }
        return resultado;
    }

    // Función para mostrar el vector
    void mostrar() const {
        std::cout << "(" << datos[0] << ", " << datos[1] << ", " << datos[2] << ")";
    }
};

int main() {
    Vector3 v1(1.0, 2.0, 3.0);
    Vector3 v2(4.0, -5.0, 6.0);

    std::cout << "Calculando el producto escalar de dos vectores:\n";
    std::cout << "Vector v1: ";
    v1.mostrar();
    std::cout << "\nVector v2: ";
    v2.mostrar();

    double prod = Vector3::productoEscalar(v1, v2);

    std::cout << "\n\nEl producto escalar v1 . v2 es: " << prod << std::endl;
    // Cálculo: (1*4) + (2*-5) + (3*6) = 4 - 10 + 18 = 12

    return 0;
}

#include <iostream>
#include <iomanip> // Para formatear la salida

class MiVector {
private:
    double* datos;
    int tam;
public:
    MiVector(int n) : tam(n) {
        datos = new double[n];
    }
    ~MiVector() {
        delete[] datos;
    }
    double& operator[](int i) {
        return datos[i];
    }
    const double& operator[](int i) const {
        return datos[i];
    }
    int size() const {
        return tam;
    }
};

// Define la Ecuación Diferencial Ordinaria: dy/dt = f(t, y)
double f(double t, double y) {
    return y - t * t + 1; // Ejemplo: y' = y - t^2 + 1
}

int main() {
    // Condiciones iniciales y parámetros
    double t0 = 0.0, y0 = 0.5, h = 0.2;
    int pasos = 10;

    MiVector tiempo(pasos + 1);
    MiVector solucion(pasos + 1);

    // Asignar condiciones iniciales
    tiempo[0] = t0;
    solucion[0] = y0;

    std::cout << "--- Solución de EDO por Método de Euler ---\n";
    std::cout << "EDO: y' = y - t^2 + 1, con y(0) = 0.5 y paso h = " << h << "\n\n";
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Paso\tTiempo (t)\tSolución (y)\n";
    std::cout << "-------------------------------------\n";
    std::cout << 0 << "\t" << tiempo[0] << "\t\t" << solucion[0] << "\n";

    // Aplicar el método de Euler
    for (int i = 0; i < pasos; i++) {
        solucion[i + 1] = solucion[i] + h * f(tiempo[i], solucion[i]);
        tiempo[i + 1] = tiempo[i] + h;
        std::cout << i + 1 << "\t" << tiempo[i + 1] << "\t\t" << solucion[i + 1] << "\n";
    }

    return 0;
}

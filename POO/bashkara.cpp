// Dados 3 valores numericos para a, b, y c. Resuelve la ecuacion de segundo grado  considerando TODOS los posibles casos
// (para cualquier valor de a, b y c)

#include <iostream>
#include <cmath>
using namespace std;

class EcuacionCuadratica {
private:
    double a, b, c;
    enum TipoSolucion {
        DOS_REALES,
        UNA_REAL,
        COMPLEJAS,
        LINEAL_UNA,
        LINEAL_INCONSISTENTE,
        LINEAL_INFINITAS
    } tipo;
    double raiz1_real, raiz1_imag;
    double raiz2_real, raiz2_imag;

public:
    // Constructores sobrecargados
    EcuacionCuadratica() : a(0), b(0), c(0) {}
    EcuacionCuadratica(double a, double b, double c) : a(a), b(b), c(c) {}

    // Destructor
    ~EcuacionCuadratica() {
        cout << "Destruyendo ecuacion..." << endl;
    }

    // Método para resolver la ecuación
    void resolver() {
        if (a == 0) {
            // Caso ecuación lineal
            if (b != 0) {
                tipo = LINEAL_UNA;
                raiz1_real = -c / b;
            } else {
                if (c != 0) tipo = LINEAL_INCONSISTENTE;
                else tipo = LINEAL_INFINITAS;
            }
        } else {
            // Caso cuadrático
            double discriminante = b*b - 4*a*c;
            
            if (discriminante > 0) {
                tipo = DOS_REALES;
                raiz1_real = (-b + sqrt(discriminante)) / (2*a);
                raiz2_real = (-b - sqrt(discriminante)) / (2*a);
            } else if (discriminante == 0) {
                tipo = UNA_REAL;
                raiz1_real = -b / (2*a);
                raiz2_real = raiz1_real;
            } else {
                tipo = COMPLEJAS;
                double parteReal = -b / (2*a);
                double parteImag = sqrt(-discriminante) / (2*a);
                raiz1_real = raiz2_real = parteReal;
                raiz1_imag = parteImag;
                raiz2_imag = -parteImag;
            }
        }
    }

    // Método para mostrar resultados
    void mostrarSoluciones() {
        switch(tipo) {
            case DOS_REALES:
                cout << "Dos raices reales distintas:\n";
                cout << "x1 = " << raiz1_real << "\nx2 = " << raiz2_real << endl;
                break;
                
            case UNA_REAL:
                cout << "Una raiz real doble:\n";
                cout << "x = " << raiz1_real << endl;
                break;
                
            case COMPLEJAS:
                cout << "Raices complejas conjugadas:\n";
                cout << "x1 = " << raiz1_real << " + " << raiz1_imag << "i\n";
                cout << "x2 = " << raiz2_real << " - " << raiz1_imag << "i" << endl;
                break;
                
            case LINEAL_UNA:
                cout << "Solucion lineal:\n";
                cout << "x = " << raiz1_real << endl;
                break;
                
            case LINEAL_INCONSISTENTE:
                cout << "Ecuacion inconsistente. No tiene solucion." << endl;
                break;
                
            case LINEAL_INFINITAS:
                cout << "Ecuacion tiene infinitas soluciones." << endl;
                break;
        }
    }
};

int main() {
    double a, b, c;
    
    cout << "Resolucion de ecuacion cuadratica ax² + bx + c = 0\n";
    cout << "Ingrese los coeficientes a, b y c: ";
    cin >> a >> b >> c;

    EcuacionCuadratica ecuacion(a, b, c);
    ecuacion.resolver();
    ecuacion.mostrarSoluciones();

    return 0;
}

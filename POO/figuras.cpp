#include <iostream>
#include <cmath>
using namespace std;

enum TipoFigura { CIRCULO, RECTANGULO, TRIANGULO, HEXAGONO, TRAPECIO, CUADRADO };

class FiguraGeometrica {
private:
    TipoFigura tipo;
    double param1;
    double param2;
    double param3;

public:
    // Constructores sobrecargados
    FiguraGeometrica(double radio) : tipo(CIRCULO), param1(radio) {}
    FiguraGeometrica(double largo, double ancho) : tipo(RECTANGULO), param1(largo), param2(ancho) {}
    FiguraGeometrica(double base, double altura, int) : tipo(TRIANGULO), param1(base), param2(altura) {}
    FiguraGeometrica(double lado,double,double,double) : tipo(CUADRADO), param1(lado) {}
    FiguraGeometrica(double base1, double base2, double altura) : tipo(TRAPECIO), param1(base1), param2(base2), param3(altura) {}

    // Destructor
    ~FiguraGeometrica() {
        cout << "Figura destruida" << endl;
    }

    // Método para calcular área
    double calcularArea() {
        switch(tipo) {
            case CIRCULO:
                return M_PI * param1 * param1;
            case RECTANGULO:
                return param1 * param2;
            case TRIANGULO:
                return (param1 * param2) / 2;
            case CUADRADO:
                return param1 * param1;
            case TRAPECIO:
                return ((param1 + param2) / 2) * param3;
            default:
                return 0;
        }
    }
};

int main() {
    int opcion;
    double a, b, c;
    
    cout << "CALCULADORA DE AREAS" << endl;
    cout << "1. Circulo\n2. Rectangulo\n3. Triangulo\n4. Cuadrado\n5. Trapecio" << endl;
    cout << "Seleccione una figura (1-5): ";
    cin >> opcion;

    FiguraGeometrica* figura = nullptr;

    switch(opcion) {
        case 1:
            cout << "Ingrese el radio: ";
            cin >> a;
            figura = new FiguraGeometrica(a);
            break;
        case 2:
            cout << "Ingrese largo y ancho: ";
            cin >> a >> b;
            figura = new FiguraGeometrica(a, b);
            break;
        case 3:
            cout << "Ingrese base y altura: ";
            cin >> a >> b;
            figura = new FiguraGeometrica(a, b, 0);
            break;
        case 4:
            cout << "Ingrese lado: ";
            cin >> a;
            figura = new FiguraGeometrica(a, 0,0,0);
            break;
        case 5:
            cout << "Ingrese bases (2) y altura: ";
            cin >> a >> b >> c;
            figura = new FiguraGeometrica(a, b, c);
            break;
        default:
            cout << "Opcion invalida!" << endl;
            return 1;
    }

    cout << "Area calculada: " << figura->calcularArea() << endl;
    delete figura;

    return 0;
}

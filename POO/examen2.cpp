#include <iostream>

class Fraccion {
private:
    int numerador;
    int denominador;

    
public:
    // Constructor
    Fraccion(int num = 0, int den = 1) : numerador(num), denominador(den) {
    }

    // Destructor
    ~Fraccion() {

    }

    // Método para imprimir la fracción
    void imprimir() const {
        std::cout << this->numerador << "/" << this->denominador;
    }

    // Sobrecarga del operador / (división)
    Fraccion operator/(const Fraccion& otra) const {
        return Fraccion(this->numerador * otra.denominador, this->denominador * otra.numerador);
    }

    // Sobrecarga del operador * (multiplicación)
    Fraccion operator*(const Fraccion& otra) const {
        return Fraccion(this->numerador * otra.numerador, this->denominador * otra.denominador);
    }

    // Función amiga para la sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& os, const Fraccion& f);
};

// Sobrecarga del operador << para imprimir la fracción
std::ostream& operator<<(std::ostream& os, const Fraccion& f) {
    os << f.numerador << "/" << f.denominador;
    return os;
}

int main() {
    char repetir = 's';

    while (repetir == 's' || repetir == 'S') {
        int num1_num, num1_den, num2_num, num2_den;

        std::cout << "Ingrese el numerador de la primera fracción: ";
        std::cin >> num1_num;
        std::cout << "Ingrese el denominador de la primera fracción: ";
        std::cin >> num1_den;

        std::cout << "Ingrese el numerador de la segunda fracción: ";
        std::cin >> num2_num;
        std::cout << "Ingrese el denominador de la segunda fracción: ";
        std::cin >> num2_den;

        Fraccion num1(num1_num, num1_den);
        Fraccion num2(num2_num, num2_den);

        Fraccion resultado_division = num1 / num2;
        std::cout << "Resultado de la división: " << resultado_division << std::endl;

        Fraccion resultado_multiplicacion = num1 * num2;
        std::cout << "Resultado de la multiplicación: " << resultado_multiplicacion << std::endl;

        std::cout << "¿Desea realizar otra operación? (s/n): ";
        std::cin >> repetir;
    }

    std::cout << "Programa finalizado." << std::endl;

    return 0;
}
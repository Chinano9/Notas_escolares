#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include <map>

class ElementoArbol {
public:
    std::string dato;
    std::unique_ptr<ElementoArbol> ramaIzquierda;
    std::unique_ptr<ElementoArbol> ramaDerecha;

    ElementoArbol(const std::string& info) : dato(info) {}

    ElementoArbol(const std::string& info, std::unique_ptr<ElementoArbol> izq, std::unique_ptr<ElementoArbol> der)
        : dato(info), ramaIzquierda(std::move(izq)), ramaDerecha(std::move(der)) {}

    // Verifica si el nodo es uno de los operadores binarios básicos
    bool esOpe() const {
        return dato == "+" || dato == "-" || dato == "*" || dato == "/";
    }
};

class ProcesadorExpresion {
private:
    std::unique_ptr<ElementoArbol> nodoPrincipal;

    // Recorrido interno para notación infija (In-orden)
    void visitarInfix(const ElementoArbol* actual) const {
        if (!actual) return;

        if (actual->esOpe()) {
            std::cout << "( ";
        }
        visitarInfix(actual->ramaIzquierda.get());
        std::cout << actual->dato << " ";
        visitarInfix(actual->ramaDerecha.get());
        if (actual->esOpe()) {
            std::cout << ") ";
        }
    }

    void visitarPrefix(const ElementoArbol* actual) const {
        if (!actual) return;
        std::cout << actual->dato << " ";
        visitarPrefix(actual->ramaIzquierda.get());
        visitarPrefix(actual->ramaDerecha.get());
    }

    void visitarPostfix(const ElementoArbol* actual) const {
        if (!actual) return;
        visitarPostfix(actual->ramaIzquierda.get());
        visitarPostfix(actual->ramaDerecha.get());
        std::cout << actual->dato << " ";
    }

    double calcularValor(const ElementoArbol* actual) const {
        if (!actual) {
            throw std::runtime_error("Error de estructura: Rama de expresión vacía");
        }

        if (!actual->esOpe()) {
            return std::stod(actual->dato);
        }

        const double opA = calcularValor(actual->ramaIzquierda.get());
        const double opB = calcularValor(actual->ramaDerecha.get());

        if (actual->dato == "+") return opA + opB;
        if (actual->dato == "-") return opA - opB;
        if (actual->dato == "*") return opA * opB;
        if (actual->dato == "/") {
            if (opB == 0.0) {
                throw std::runtime_error("Error de cálculo: División por cero detectada");
            }
            return opA / opB;
        }

        throw std::runtime_error("Error de operador: Símbolo de operación desconocido");
    }

public:
    ProcesadorExpresion() {

        auto opNueve = std::make_unique<ElementoArbol>("9");
        auto opCuatro = std::make_unique<ElementoArbol>("4");
        auto subExpDer = std::make_unique<ElementoArbol>("-", std::move(opNueve), std::move(opCuatro));

        auto opTres = std::make_unique<ElementoArbol>("3");
        auto opCinco = std::make_unique<ElementoArbol>("5");
        auto subExpIzq = std::make_unique<ElementoArbol>("+", std::move(opTres), std::move(opCinco));

        nodoPrincipal = std::make_unique<ElementoArbol>("*", std::move(subExpIzq), std::move(subExpDer));
    }

    void mostrarInfijo() const {
        std::cout << "Representación Infija (In-orden): ";
        visitarInfix(nodoPrincipal.get());
        std::cout << "\n";
    }

    void mostrarPrefijo() const {
        std::cout << "Representación Prefija (Pre-orden): ";
        visitarPrefix(nodoPrincipal.get());
        std::cout << "\n";
    }

    void mostrarPostfijo() const {
        std::cout << "Representación Postfija (Post-orden): ";
        visitarPostfix(nodoPrincipal.get());
        std::cout << "\n";
    }

    double obtenerResultadoFinal() const {
        try {
            return calcularValor(nodoPrincipal.get());
        } catch (const std::runtime_error& err) {
            std::cerr << "Excepción capturada: " << err.what() << "\n";
            return -999.0; // Valor de error
        }
    }
};


int main() {
    ProcesadorExpresion miCalculadora;

    std::cout << ">>> Demostración del Procesador de Expresiones Binarias <<<\n";
    std::cout << "------------------------------------------------------------\n";

    miCalculadora.mostrarInfijo();
    miCalculadora.mostrarPrefijo();
    miCalculadora.mostrarPostfijo();

    std::cout << "------------------------------------------------------------\n";

    double resultadoNumerico = miCalculadora.obtenerResultadoFinal();
    std::cout << "El valor de la expresión es: " << resultadoNumerico << "\n";

    return 0;
}

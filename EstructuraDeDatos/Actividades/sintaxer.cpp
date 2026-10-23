#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <cctype>

class ValidadorEstructura {
private:
    std::map<char, char> mapeoSimbolos;

    bool esDelimitadorInicio(char c) const {
        return c == '(' || c == '[' || c == '{';
    }

    bool esDelimitadorFin(char c) const {
        return c == ')' || c == ']' || c == '}';
    }

public:

    ValidadorEstructura() {
        mapeoSimbolos[')'] = '(';
        mapeoSimbolos[']'] = '[';
        mapeoSimbolos['}'] = '{';
    }

    bool chequearCadena(const std::string& cadena) const {
        std::stack<char> pilaDeAperturas;
        char ultimoToken = '\0';

        for (int i = 0; i < cadena.length(); ++i) {
            char actual = cadena[i];

            if (std::isspace(actual)) {
                continue;
            }

            if (esDelimitadorFin(ultimoToken) && esDelimitadorInicio(actual)) {
                std::cout << "\n\t[FALLA] Multiplicacion implicita (Cierre-Apertura) en pos " << i
                          << ": '" << ultimoToken << actual << "'. Falta el '*'.\n";
                return false;
            }

            if (std::isalnum(ultimoToken) && esDelimitadorInicio(actual)) {
                std::cout << "\n\t[FALLA] Multiplicacion implicita (Operando-Apertura) en pos " << i
                          << ": '" << ultimoToken << actual << "'. Falta el '*'.\n";
                return false;
            }

            if (esDelimitadorFin(ultimoToken) && std::isalnum(actual)) {
                std::cout << "\n\t[FALLA] Multiplicacion implicita (Cierre-Operando) en pos " << i
                          << ": '" << ultimoToken << actual << "'. Falta el '*'.\n";
                return false;
            }

            if (esDelimitadorInicio(actual)) {
                pilaDeAperturas.push(actual);
            } else if (esDelimitadorFin(actual)) {
                if (pilaDeAperturas.empty()) {
                    std::cout << "\n\t[FALLA] Simbolo de cierre '" << actual << "' en pos "
                              << i << " sin un par de apertura en la pila.\n";
                    return false;
                }

                char esperado = mapeoSimbolos.at(actual);
                char encontrado = pilaDeAperturas.top();
                pilaDeAperturas.pop();

                if (esperado != encontrado) {
                    std::cout << "\n\t[FALLA] Simbolo de cierre '" << actual << "' en pos "
                              << i << " no coincide con el par de apertura '" << encontrado << "'.\n";
                    return false;
                }
            }

            ultimoToken = actual;
        }

        if (!pilaDeAperturas.empty()) {
            std::cout << "\n\t[FALLA] Simbolos de apertura sin cerrar. El ultimo es '"
                      << pilaDeAperturas.top() << "'.\n";
            return false;
        }

        return true;
    }
};

int main() {
    ValidadorEstructura validador;
    std::string entrada;

    std::cout << "\n <<< Herramienta de Analisis de Expresiones v3.0 >>>\n";
    std::cout << " (Verifica balanceo y reglas de multiplicacion implicita)\n";
    std::cout << "\n Ingrese la expresion para verificar: ";
    std::getline(std::cin, entrada);

    if (validador.chequearCadena(entrada)) {
        std::cout << "\n\t ===> EXITO: La expresion es sintacticamente correcta.\n";
    } else {
        std::cout << "\n\t ===> SINTAXIS INVALIDA.\n";
    }

    std::cout << "\nPresione Enter para finalizar...\n";
    std::cin.get();
    return 0;
}

#include <iostream>
#include <string>
#include <cctype>

class Frecuencia {
private:
    int datos[26];

public:
    Frecuencia() {
        for (int i = 0; i < 26; i++) {
            datos[i] = 0;
        }
    }

    // Cuenta las letras en un texto
    void contar(const std::string& texto) {
        for (char c : texto) {
            if (isalpha(c)) { // Verifica si es una letra
                c = tolower(c); // Convierte a minúscula
                datos[c - 'a']++;
            }
        }
    }

    void mostrar(const std::string& texto) const {
        std::cout << "--- Frecuencia de letras en \"" << texto << "\" ---\n";
        for (int i = 0; i < 26; i++) {
            if (datos[i] > 0) {
                std::cout << "Letra '" << char('a' + i) << "': " << datos[i] << " veces\n";
            }
        }
    }
};

int main() {
    Frecuencia f;
    std::string palabra = "Programacion en C++";
    f.contar(palabra);
    f.mostrar(palabra);
    return 0;
}

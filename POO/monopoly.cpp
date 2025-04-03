#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Dados {
private:
    int dado1;
    int dado2;
    int dado1_b;
    int dado2_b;
    bool segundaTirada;

public:
    // Constructor
    Dados() : dado1(0), dado2(0), dado1_b(0), dado2_b(0), segundaTirada(false) {
        srand(time(0)); // Inicializar la semilla para números aleatorios
    }

    // Destructor
    ~Dados() {
        cout << "Gracias por jugar!" << endl;
    }

    /**
    * Esta funcion simula el lanzamiento de unos dados 
    *
    * @author Fernando Ponce
    */
    void lanzarDados() {
        dado1 = rand() % 6 + 1;
        dado2 = rand() % 6 + 1;

        if (dado1 == dado2) {
            segundaTirada = true;
            dado1_b = rand() % 6 + 1;
            dado2_b = rand() % 6 + 1;
        } else {
            segundaTirada = false;
        }
    }

    // Función para mostrar los resultados
    void mostrarResultados() {
        cout << "Dado 1: " << this->dado1 << endl;
        cout << "Dado 2: " << this->dado2 << endl;
        cout << "Sumatoria: " << (this->dado1 + this->dado2) << endl;

        if (segundaTirada) {
            cout << "Dado 1_b: " << this->dado1_b << endl;
            cout << "Dado 2_b: " << this->dado2_b << endl;
            cout << "Sumatoria adicional: " << (this->dado1_b + this->dado2_b) << endl;
            cout << "Numero final de pasos: " << (this->dado1 + this->dado2 + this->dado1_b + this->dado2-b)<<endl;
        }
        cout << "Numero final de pasos: " << (this->dado1 + this->dado2)<<endl;
``
    }

    // Función friend para verificar si se realizó una segunda tirada
    friend bool huboSegundaTirada(const Dados& d);
};

// Función friend para verificar si se realizó una segunda tirada
bool huboSegundaTirada(const Dados& d) {
    return d.segundaTirada;
}

int main() {
    char continuar;

    do {
        Dados juego;
        juego.lanzarDados();
        juego.mostrarResultados();

        if (huboSegundaTirada(juego)) {
            cout << "Se realizó una segunda tirada debido a que los dados fueron iguales." << endl;
        }

        cout << "¿Desea lanzar los dados de nuevo? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    return 0;
}

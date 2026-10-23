#include <iostream>

// Una lista dinámica simple para la lista de adyacencia
class Lista {
private:
    int* datos;
    int tam, capacidad;

    void redimensionar() {
        int nuevaCap = (capacidad == 0) ? 1 : capacidad * 2;
        int* nuevo = new int[nuevaCap];
        for (int i = 0; i < tam; i++) nuevo[i] = datos[i];
        delete[] datos;
        datos = nuevo;
        capacidad = nuevaCap;
    }

public:
    Lista() : tam(0), capacidad(4) {
        datos = new int[capacidad];
    }

    ~Lista() {
        delete[] datos;
    }

    void push_back(int x) {
        if (tam == capacidad) redimensionar();
        datos[tam++] = x;
    }

    int size() const { return tam; }
    int operator[](int i) const { return datos[i]; }
};

// Clase para representar el Grafo
class Grafo {
private:
    Lista* nodosAdyacencia;
    int numNodos;

public:
    Grafo(int n) : numNodos(n) {
        nodosAdyacencia = new Lista[numNodos];
    }

    ~Grafo() {
        delete[] nodosAdyacencia;
    }

    // Agrega una arista (conexión) entre u y v
    void agregarArista(int u, int v) {
        if (u < numNodos && v < numNodos) {
            nodosAdyacencia[u].push_back(v);
            nodosAdyacencia[v].push_back(u); // Para grafo no dirigido
        }
    }

    void mostrar() const {
        std::cout << "--- Lista de Adyacencia del Grafo ---\n";
        for (int i = 0; i < numNodos; i++) {
            std::cout << "Nodo " << i << " conectado a: ";
            for (int j = 0; j < nodosAdyacencia[i].size(); j++) {
                std::cout << nodosAdyacencia[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    Grafo g(5);
    g.agregarArista(0, 1);
    g.agregarArista(0, 4);
    g.agregarArista(1, 2);
    g.agregarArista(1, 3);
    g.agregarArista(1, 4);
    g.agregarArista(2, 3);
    g.agregarArista(3, 4);

    g.mostrar();

    return 0;
}

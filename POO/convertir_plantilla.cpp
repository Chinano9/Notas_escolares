#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template <typename T>
class ColaCircular {
private:
    T Cola[10];
    int Frente, Final, Max;

public:
    ColaCircular() : Frente(-1), Final(-1), Max(9) {
        for (int i = 0; i <= Max; i++) {
            Cola[i] = T(); // Inicialización por defecto del tipo T
        }
    }

    bool estaLlena() const {
        return (Frente == 0 && Final == Max) || (Frente == Final + 1);
    }

    bool estaVacia() const {
        return Frente == -1;
    }

    void Push(T Elem) {
        if (estaLlena()) {
            cout << "Cola Llena" << endl;
            return;
        }
        if (estaVacia()) {
            Frente = Final = 0;
        } else if (Final == Max) {
            Final = 0;
        } else {
            Final++;
        }
        Cola[Final] = Elem;
    }

    void Pop() {
        if (estaVacia()) {
            cout << "Cola Vacia... Imposible Eliminar" << endl;
            return;
        }
        cout << "Eliminado el Dato: " << Cola[Frente] << endl;
        if (Frente == Final) {
            Frente = Final = -1;
        } else if (Frente == Max) {
            Frente = 0;
        } else {
            Frente++;
        }
    }

    void Recorrido() const {
        if (estaVacia()) {
            cout << "Cola Vacia..." << endl;
            return;
        }
        if (Frente <= Final) {
            for (int i = Frente; i <= Final; i++) {
                cout << Cola[i] << endl;
            }
        } else {
            for (int i = Frente; i <= Max; i++) {
                cout << Cola[i] << endl;
            }
            for (int i = 0; i <= Final; i++) {
                cout << Cola[i] << endl;
            }
        }
    }

    void Busqueda(T Elem) const {
        if (estaVacia()) {
            cout << "Cola Vacia..." << endl;
            return;
        }
        if (Frente <= Final) {
            for (int i = Frente; i <= Final; i++) {
                if (Cola[i] == Elem) {
                    cout << "Dato " << Cola[i] << " encontrado..." << endl;
                    return;
                }
            }
        } else {
            for (int i = Frente; i <= Max; i++) {
                if (Cola[i] == Elem) {
                    cout << "Dato " << Cola[i] << " encontrado..." << endl;
                    return;
                }
            }
            for (int i = 0; i <= Final; i++) {
                if (Cola[i] == Elem) {
                    cout << "Dato " << Cola[i] << " encontrado..." << endl;
                    return;
                }
            }
        }
        cout << "Dato no encontrado..." << endl;
    }

    void Borrar(T Elem) {
        if (estaVacia()) {
            cout << "Cola Vacia... Imposible Eliminar..." << endl;
            return;
        }

        int pos = -1;
        if (Frente <= Final) {
            for (int i = Frente; i <= Final; i++) {
                if (Cola[i] == Elem) {
                    pos = i;
                    break;
                }
            }
        } else {
            for (int i = Frente; i <= Max; i++) {
                if (Cola[i] == Elem) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) {
                for (int i = 0; i <= Final; i++) {
                    if (Cola[i] == Elem) {
                        pos = i;
                        break;
                    }
                }
            }
        }

        if (pos == -1) {
            cout << "Dato no Encontrado..." << endl;
            return;
        }

        cout << "Eliminado el Dato " << Cola[pos] << endl;
        
        if (Frente == Final) {
            Frente = Final = -1;
            return;
        }

        // Reorganizar los elementos
        if (Frente <= Final) {
            for (int i = pos; i < Final; i++) {
                Cola[i] = Cola[i+1];
            }
            Final--;
        } else {
            if (pos >= Frente) {
                for (int i = pos; i < Max; i++) {
                    Cola[i] = Cola[i+1];
                }
                Cola[Max] = Cola[0];
                for (int i = 0; i < Final; i++) {
                    Cola[i] = Cola[i+1];
                }
                Final--;
            } else {
                for (int i = pos; i < Final; i++) {
                    Cola[i] = Cola[i+1];
                }
                Final--;
            }
        }
    }
};

// Especialización para cadenas de caracteres
template <>
class ColaCircular<string> {
private:
    string Cola[10];
    int Frente, Final, Max;

public:
    ColaCircular() : Frente(-1), Final(-1), Max(9) {
        for (int i = 0; i <= Max; i++) {
            Cola[i] = "";
        }
    }

    bool estaLlena() const {
        return (Frente == 0 && Final == Max) || (Frente == Final + 1);
    }

    bool estaVacia() const {
        return Frente == -1;
    }

    void Push(string Elem) {
        if (estaLlena()) {
            cout << "Cola Llena" << endl;
            return;
        }
        if (estaVacia()) {
            Frente = Final = 0;
        } else if (Final == Max) {
            Final = 0;
        } else {
            Final++;
        }
        Cola[Final] = Elem;
    }

    void Pop() {
        if (estaVacia()) {
            cout << "Cola Vacia... Imposible Eliminar" << endl;
            return;
        }
        cout << "Eliminado el Dato: " << Cola[Frente] << endl;
        if (Frente == Final) {
            Frente = Final = -1;
        } else if (Frente == Max) {
            Frente = 0;
        } else {
            Frente++;
        }
    }

    void Recorrido() const {
        if (estaVacia()) {
            cout << "Cola Vacia..." << endl;
            return;
        }
        if (Frente <= Final) {
            for (int i = Frente; i <= Final; i++) {
                cout << Cola[i] << endl;
            }
        } else {
            for (int i = Frente; i <= Max; i++) {
                cout << Cola[i] << endl;
            }
            for (int i = 0; i <= Final; i++) {
                cout << Cola[i] << endl;
            }
        }
    }

    void Busqueda(string Elem) const {
        if (estaVacia()) {
            cout << "Cola Vacia..." << endl;
            return;
        }
        if (Frente <= Final) {
            for (int i = Frente; i <= Final; i++) {
                if (Cola[i] == Elem) {
                    cout << "Dato " << Cola[i] << " encontrado..." << endl;
                    return;
                }
            }
        } else {
            for (int i = Frente; i <= Max; i++) {
                if (Cola[i] == Elem) {
                    cout << "Dato " << Cola[i] << " encontrado..." << endl;
                    return;
                }
            }
            for (int i = 0; i <= Final; i++) {
                if (Cola[i] == Elem) {
                    cout << "Dato " << Cola[i] << " encontrado..." << endl;
                    return;
                }
            }
        }
        cout << "Dato no encontrado..." << endl;
    }

    void Borrar(string Elem) {
        if (estaVacia()) {
            cout << "Cola Vacia... Imposible Eliminar..." << endl;
            return;
        }

        int pos = -1;
        if (Frente <= Final) {
            for (int i = Frente; i <= Final; i++) {
                if (Cola[i] == Elem) {
                    pos = i;
                    break;
                }
            }
        } else {
            for (int i = Frente; i <= Max; i++) {
                if (Cola[i] == Elem) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) {
                for (int i = 0; i <= Final; i++) {
                    if (Cola[i] == Elem) {
                        pos = i;
                        break;
                    }
                }
            }
        }

        if (pos == -1) {
            cout << "Dato no Encontrado..." << endl;
            return;
        }

        cout << "Eliminado el Dato " << Cola[pos] << endl;
        
        if (Frente == Final) {
            Frente = Final = -1;
            return;
        }

        // Reorganizar los elementos
        if (Frente <= Final) {
            for (int i = pos; i < Final; i++) {
                Cola[i] = Cola[i+1];
            }
            Final--;
        } else {
            if (pos >= Frente) {
                for (int i = pos; i < Max; i++) {
                    Cola[i] = Cola[i+1];
                }
                Cola[Max] = Cola[0];
                for (int i = 0; i < Final; i++) {
                    Cola[i] = Cola[i+1];
                }
                Final--;
            } else {
                for (int i = pos; i < Final; i++) {
                    Cola[i] = Cola[i+1];
                }
                Final--;
            }
        }
    }
};

int main() {
    ColaCircular<int> colaEnteros;
    ColaCircular<string> colaStrings;
    
    int opcion, valorInt;
    string valorStr;
    
    while (true) {
        cout << "\nMenu Principal:\n";
        cout << "1) Recorrido\n";
        cout << "2) Busqueda\n";
        cout << "3) Push\n";
        cout << "4) Pop\n";
        cout << "5) Eliminar un Dato\n";
        cout << "6) Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout << "\nRecorrido de cola de enteros:\n";
                colaEnteros.Recorrido();
                cout << "\nRecorrido de cola de strings:\n";
                colaStrings.Recorrido();
                break;
            case 2:
                cout << "Buscar en (1) Enteros o (2) Strings? ";
                cin >> opcion;
                if (opcion == 1) {
                    cout << "Que numero deseas buscar? ";
                    cin >> valorInt;
                    colaEnteros.Busqueda(valorInt);
                } else {
                    cout << "Que string deseas buscar? ";
                    cin.ignore();
                    getline(cin, valorStr);
                    colaStrings.Busqueda(valorStr);
                }
                break;
            case 3:
                cout << "Insertar en (1) Enteros o (2) Strings? ";
                cin >> opcion;
                if (opcion == 1) {
                    cout << "Que numero quieres insertar? ";
                    cin >> valorInt;
                    colaEnteros.Push(valorInt);
                } else {
                    cout << "Que string quieres insertar? ";
                    cin.ignore();
                    getline(cin, valorStr);
                    colaStrings.Push(valorStr);
                }
                break;
            case 4:
                cout << "Eliminar de (1) Enteros o (2) Strings? ";
                cin >> opcion;
                if (opcion == 1) {
                    colaEnteros.Pop();
                } else {
                    colaStrings.Pop();
                }
                break;
            case 5:
                cout << "Eliminar de (1) Enteros o (2) Strings? ";
                cin >> opcion;
                if (opcion == 1) {
                    cout << "Que numero deseas eliminar? ";
                    cin >> valorInt;
                    colaEnteros.Borrar(valorInt);
                } else {
                    cout << "Que string deseas eliminar? ";
                    cin.ignore();
                    getline(cin, valorStr);
                    colaStrings.Borrar(valorStr);
                }
                break;
            case 6:
                cout << "Saliendo del programa...\n";
                return 0;
            default:
                cout << "Opcion no valida.\n";
        }
    }
    
    return 0;
}
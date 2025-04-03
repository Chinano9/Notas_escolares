#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int cantidad;
    string descripcion;

public:
    // Constructor
    Producto(string nombre, double precio, int cantidad, string descripcion)
        : nombre(nombre), precio(precio), cantidad(cantidad), descripcion(descripcion) {}

    // Destructor
    ~Producto() {
        cout << "Producto " << nombre << " eliminado." << endl;
    }

    // Getters
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }
    string getDescripcion() const { return descripcion; }

    // Setters
    void setCantidad(int cantidad) {
        this->cantidad = cantidad;
    }

    // Función amiga para sobrecargar el operador <<
    friend ostream& operator<<(ostream& os, const Producto& producto);
};

// Sobrecarga del operador << para imprimir un producto
ostream& operator<<(ostream& os, const Producto& producto) {
    os << "Nombre: " << producto.nombre << ", Precio: $" << producto.precio
       << ", Cantidad: " << producto.cantidad << ", Descripcion: " << producto.descripcion;
    return os;
}

class Tienda {
private:
    vector<Producto> inventario;

public:
    // Ingresar un nuevo producto al inventario
    void ingresarProducto() {
        string nombre, descripcion;
        double precio;
        int cantidad;

        cout << "Ingrese el nombre del producto: ";
        cin >> nombre;
        cout << "Ingrese el precio del producto: ";
        cin >> precio;
        cout << "Ingrese la cantidad del producto: ";
        cin >> cantidad;
        cin.ignore(); // Para ignorar el salto de línea después de la cantidad
        cout << "Ingrese la descripcion del producto: ";
        getline(cin, descripcion);

        Producto nuevoProducto(nombre, precio, cantidad, descripcion);
        inventario.push_back(nuevoProducto);
        cout << "Producto ingresado con exito!" << endl;
    }

    // Realizar una venta
    void realizarVenta() {
        string nombre;
        int cantidadVendida;

        cout << "Ingrese el nombre del producto a vender: ";
        cin >> nombre;
        cout << "Ingrese la cantidad a vender: ";
        cin >> cantidadVendida;

        for (Producto& producto : inventario) {
            if (producto.getNombre() == nombre) {
                if (producto.getCantidad() >= cantidadVendida) {
                    producto.setCantidad(producto.getCantidad() - cantidadVendida);
                    double totalPagar = cantidadVendida * producto.getPrecio();
                    cout << "Venta realizada. Total a pagar: $" << totalPagar << endl;
                } else {
                    cout << "No hay suficiente stock para realizar la venta." << endl;
                }
                return;
            }
        }
        cout << "Producto no encontrado." << endl;
    }

    // Mostrar el stock actual
    void mostrarStock() const {
        cout << "Stock actual:" << endl;
        for (const auto& producto : inventario) {
            cout << producto << endl;
        }
    }
};

int main() {
    Tienda tienda;
    char opcion;

    do {
        cout << "\nMenu:\n";
        cout << "1. Ingresar producto\n";
        cout << "2. Realizar venta\n";
        cout << "3. Mostrar stock\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                tienda.ingresarProducto();
                break;
            case '2':
                tienda.realizarVenta();
                break;
            case '3':
                tienda.mostrarStock();
                break;
            case '4':
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != '4');

    return 0;
}

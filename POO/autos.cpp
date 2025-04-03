#include <iostream>
#include <vector>
#include <string>

class Vehiculo {
private:
    std::string numeroSerie;
    std::string color;
    std::string marca;
    std::string modelo;

public:
    Vehiculo(const std::string& numeroSerie = "", const std::string& color = "", const std::string& marca = "", const std::string& modelo = "")
        : numeroSerie(numeroSerie), color(color), marca(marca), modelo(modelo) {}

    ~Vehiculo() {}

    friend std::ostream& operator<<(std::ostream& os, const Vehiculo& vehiculo) {
        os << "Numero de serie: " << vehiculo.numeroSerie << std::endl;
        os << "Color: " << vehiculo.color << std::endl;
        os << "Marca: " << vehiculo.marca << std::endl;
        os << "Modelo: " << vehiculo.modelo << std::endl;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Vehiculo& vehiculo) {
        std::cout << "Numero de serie: ";
        std::getline(is, vehiculo.numeroSerie);
        std::cout << "Color: ";
        std::getline(is, vehiculo.color);
        std::cout << "Marca: ";
        std::getline(is, vehiculo.marca);
        std::cout << "Modelo: ";
        std::getline(is, vehiculo.modelo);
        return is;
    }

    bool operator==(const Vehiculo& otro) const {
        return numeroSerie == otro.numeroSerie;
    }

    std::string getNumeroSerie() const { return numeroSerie; }
    void setNumeroSerie(const std::string& numeroSerie) { this->numeroSerie = numeroSerie; }
    std::string getColor() const { return color; }
    void setColor(const std::string& color) { this->color = color; }
    std::string getMarca() const { return marca; }
    void setMarca(const std::string& marca) { this->marca = marca; }
    std::string getModelo() const { return modelo; }
    void setModelo(const std::string& modelo) { this->modelo = modelo; }
};

class BaseDatosVehiculos {
private:
    std::vector<Vehiculo> vehiculos;

public:
    BaseDatosVehiculos() {}
    ~BaseDatosVehiculos() {}

    void agregarVehiculo(const Vehiculo& vehiculo) {
        vehiculos.push_back(vehiculo);
    }

    void mostrarVehiculos() const {
        for (const auto& vehiculo : vehiculos) {
            std::cout << vehiculo << std::endl;
        }
    }

    Vehiculo* buscarVehiculo(const std::string& numeroSerie) {
        for (auto& vehiculo : vehiculos) {
            if (vehiculo.getNumeroSerie() == numeroSerie) {
                return &vehiculo;
            }
        }
        return nullptr;
    }

    void eliminarVehiculo(const std::string& numeroSerie) {
        for (auto it = vehiculos.begin(); it != vehiculos.end(); ++it) {
            if (it->getNumeroSerie() == numeroSerie) {
                vehiculos.erase(it);
                return;
            }
        }
    }
};

int main() {
    BaseDatosVehiculos baseDatos;
    int opcion;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Agregar vehiculo\n";
        std::cout << "2. Mostrar vehiculos\n";
        std::cout << "3. Buscar vehiculo\n";
        std::cout << "4. Editar vehiculo\n";
        std::cout << "5. Eliminar vehiculo\n";
        std::cout << "0. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;
        std::cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
        case 1: {
            Vehiculo vehiculo;
            std::cin >> vehiculo;
            baseDatos.agregarVehiculo(vehiculo);
            break;
        }
        case 2:
            baseDatos.mostrarVehiculos();
            break;
        case 3: {
            std::string numeroSerie;
            std::cout << "Numero de serie a buscar: ";
            std::getline(std::cin, numeroSerie);
            Vehiculo* vehiculo = baseDatos.buscarVehiculo(numeroSerie);
            if (vehiculo) {
                std::cout << *vehiculo << std::endl;
            } else {
                std::cout << "Vehiculo no encontrado.\n";
            }
            break;
        }
        case 4: {
            std::string numeroSerie;
            std::cout << "Numero de serie del vehiculo a editar: ";
            std::getline(std::cin, numeroSerie);
            Vehiculo* vehiculo = baseDatos.buscarVehiculo(numeroSerie);
            if (vehiculo) {
                std::cin >> *vehiculo;
            } else {
                std::cout << "Vehiculo no encontrado.\n";
            }
            break;
        }
        case 5: {
            std::string numeroSerie;
            std::cout << "Numero de serie del vehiculo a eliminar: ";
            std::getline(std::cin, numeroSerie);
            baseDatos.eliminarVehiculo(numeroSerie);
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Opcion no valida.\n";
        }
    } while (opcion != 0);

    return 0;
}

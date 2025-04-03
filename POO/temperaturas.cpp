#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Clase Temperatura
class Temperatura {
private:
    double valor;        // Valor de la temperatura
    string tipo;         // Tipo de temperatura (C, F, K)
    int totalLecturas;   // Contador de lecturas
    double sumaTemperaturas; // Suma de todas las temperaturas en Celsius

public:
    // Constructor
    Temperatura() : totalLecturas(0), sumaTemperaturas(0) {}

    // Método para convertir temperaturas
    void convertirTemperatura(double valor, string tipo) {
        this->valor = valor;
        this->tipo = tipo;

        double celsius = 0, fahrenheit = 0, kelvin = 0;

        if (tipo == "C" || tipo == "c") {
            celsius = valor;
            fahrenheit = celsiusToFahrenheit(celsius);
            kelvin = celsiusToKelvin(celsius);
        } else if (tipo == "F" || tipo == "f") {
            fahrenheit = valor;
            celsius = fahrenheitToCelsius(fahrenheit);
            kelvin = fahrenheitToKelvin(fahrenheit);
        } else if (tipo == "K" || tipo == "k") {
            kelvin = valor;
            celsius = kelvinToCelsius(kelvin);
            fahrenheit = kelvinToFahrenheit(kelvin);
        } else {
            cout << "Tipo de temperatura no válido. Intente de nuevo." << endl;
            return;
        }

        // Mostrar las conversiones
        cout << fixed << setprecision(2);
        cout << "Celsius: " << celsius << " °C" << endl;
        cout << "Fahrenheit: " << fahrenheit << " °F" << endl;
        cout << "Kelvin: " << kelvin << " K" << endl;

        // Actualizar el contador y la suma de temperaturas
        totalLecturas++;
        sumaTemperaturas += celsius;
    }

    // Método para obtener el número total de lecturas
    int getTotalLecturas() const {
        return totalLecturas;
    }

    // Método para obtener el promedio de temperaturas en Celsius
    double getPromedioTemperaturas() const {
        if (totalLecturas > 0) {
            return sumaTemperaturas / totalLecturas;
        } else {
            return 0;
        }
    }

    ~Temperatura(){
        cout<<"Temperaturas borradas";
    }

private:
    // Funciones de conversión privadas
    double celsiusToFahrenheit(double celsius) {
        return (celsius * 9 / 5) + 32;
    }

    double celsiusToKelvin(double celsius) {
        return celsius + 273.15;
    }

    double fahrenheitToCelsius(double fahrenheit) {
        return (fahrenheit - 32) * 5 / 9;
    }

    double fahrenheitToKelvin(double fahrenheit) {
        return celsiusToKelvin(fahrenheitToCelsius(fahrenheit));
    }

    double kelvinToCelsius(double kelvin) {
        return kelvin - 273.15;
    }

    double kelvinToFahrenheit(double kelvin) {
        return celsiusToFahrenheit(kelvinToCelsius(kelvin));
    }
};

int main() {
    Temperatura temp; // Objeto de la clase Temperatura
    char continuar;

    do {
        double valor;
        string tipo;

        cout << "Ingrese el valor de la temperatura: ";
        cin >> valor;
        cout << "Ingrese el tipo de temperatura (C, F, K): ";
        cin >> tipo;

        // Convertir y mostrar la temperatura
        temp.convertirTemperatura(valor, tipo);

        cout << "¿Desea ingresar otra temperatura? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    // Mostrar el número de lecturas y el promedio
    cout << "Total de lecturas: " << temp.getTotalLecturas() << endl;
    cout << "Promedio de temperaturas en Celsius: " << temp.getPromedioTemperaturas() << " °C" << endl;

    return 0;
}

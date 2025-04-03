#include <iostream>
#include <iomanip>
using namespace std;

class Casa {
private:
    double tipoCambioEuro;
    double tipoCambioDolar;
    double tipoCambioLibra;
    double pesos;

public:
    // Constructor
    Casa() : tipoCambioEuro(25.37), tipoCambioDolar(20.60), tipoCambioLibra(27.22) {}

    // Constructor copia
    Casa(const Casa& otra) {
        tipoCambioEuro = otra.tipoCambioEuro;
        tipoCambioDolar = otra.tipoCambioDolar;
        tipoCambioLibra = otra.tipoCambioLibra;
    }

    // Destructor
    ~Casa() {
        cout << "Lol la casa desaparecio ya no existe en la faz de la tierra omgggggg :o" << endl;
    }

    void setPesos(double pesos){
        this->pesos = pesos;
    }

    // Métodos
    double convertirAEuros() {
        return pesos / tipoCambioEuro;
    }

    double convertirADolares() {
        return pesos / tipoCambioDolar;
    }

    double convertirALibras() {
        return pesos / tipoCambioLibra;
    }

    void desglosarBilletes(double cantidad) {
        int billetes[] = {100, 50, 20, 10, 5, 1};
        double monedas[] = {0.25, 0.1, 0.05, 0.01};

        cout << "Desglose de billetes y monedas:" << endl;

        for (int i = 0; i < sizeof(billetes); i++) {
            int numBilletes = cantidad / billetes[i];
            if (numBilletes > 0) {
                cout << numBilletes << " billete(s) de " << billetes[i] << " " << (billetes[i] == 1 ? "peso" : "pesos") << endl;
                cantidad -= numBilletes * billetes[i];
            }
        }

        for (int i = 0; i < sizeof(monedas); i++) {
            int numMonedas = cantidad / monedas[i];
            if (numMonedas > 0) {
                cout << numMonedas << " moneda(s) de " << monedas[i] << " pesos" << endl;
                cantidad -= numMonedas * monedas[i];
            }
        }
    }

    // Función amiga
    friend void mostrarTiposDeCambio(const Casa& casa);
};

// Función amiga para mostrar los tipos de cambio
void mostrarTiposDeCambio(const Casa& casa) {
    cout << "Tipos de cambio:" << endl;
    cout << "1 Euro = " << casa.tipoCambioEuro << " pesos" << endl;
    cout << "1 Dólar = " << casa.tipoCambioDolar << " pesos" << endl;
    cout << "1 Libra = " << casa.tipoCambioLibra << " pesos" << endl;
}

int main() {
    char continuar;
    do {
        Casa casa;
        mostrarTiposDeCambio(casa);

        double pesos;
        int opcion;
        cout << "Ingrese la cantidad en pesos: ";
        cin >> pesos;

        casa.setPesos(pesos);

        cout << "Seleccione la moneda a la que desea convertir:" << endl;
        cout << "1. Euros" << endl;
        cout << "2. Dólares" << endl;
        cout << "3. Libras" << endl;
        cin >> opcion;

        double cantidadConvertida;
        switch (opcion) {
            case 1:
                cantidadConvertida = casa.convertirAEuros();
                cout << pesos << " pesos equivalen a " << fixed << setprecision(2) << cantidadConvertida << " euros." << endl;
                break;
            case 2:
                cantidadConvertida = casa.convertirADolares();
                cout << pesos << " pesos equivalen a " << fixed << setprecision(2) << cantidadConvertida << " dólares." << endl;
                break;
            case 3:
                cantidadConvertida = casa.convertirALibras();
                cout << pesos << " pesos equivalen a " << fixed << setprecision(2) << cantidadConvertida << " libras." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
                continue;
        }

        casa.desglosarBilletes(cantidadConvertida);

        cout << "¿Desea realizar otra transacción? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    return 0;
}

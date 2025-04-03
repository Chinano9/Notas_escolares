#include <iostream>
#include <iomanip>
using namespace std;

class Horario {
private:
    int horas;
    int minutos;
    int segundos;

public:
    // Constructores
    Horario() : horas(0), minutos(0), segundos(0) {}
    Horario(int h, int m, int s) : horas(h), minutos(m), segundos(s) {}

    // Destructor
    ~Horario() {
        cout << "Destructor llamado para el horario: " << horas << ":" << minutos << ":" << segundos << endl;
    }

    // Métodos públicos
    void setHorario(int h, int m, int s) {
        horas = h;
        minutos = m;
        segundos = s;
    }

    void mostrarEstandar() const {
        cout << "Horario Estandar: " << setw(2) << setfill('0') << horas << ":"
             << setw(2) << setfill('0') << minutos << ":" << setw(2) << setfill('0') << segundos << endl;
    }

    void mostrarMilitar() const {
        cout << "Horario Militar: " << setw(2) << setfill('0') << horas << setw(2) << setfill('0') << minutos << endl;
    }

    // Sobrecarga de operadores para sumar y restar horarios
    Horario operator+(const Horario& otro) const {
        Horario resultado;
        resultado.segundos = segundos + otro.segundos;
        resultado.minutos = minutos + otro.minutos;
        resultado.horas = horas + otro.horas;

        if (resultado.segundos >= 60) {
            resultado.segundos -= 60;
            resultado.minutos++;
        }
        if (resultado.minutos >= 60) {
            resultado.minutos -= 60;
            resultado.horas++;
        }
        if (resultado.horas >= 24) {
            resultado.horas -= 24;
        }

        return resultado;
    }

    Horario operator-(const Horario& otro) const {
        Horario resultado;
        resultado.segundos = segundos - otro.segundos;
        resultado.minutos = minutos - otro.minutos;
        resultado.horas = horas - otro.horas;

        if (resultado.segundos < 0) {
            resultado.segundos += 60;
            resultado.minutos--;
        }
        if (resultado.minutos < 0) {
            resultado.minutos += 60;
            resultado.horas--;
        }
        if (resultado.horas < 0) {
            resultado.horas += 24;
        }

        return resultado;
    }
};

int main() {
    char continuar;
    do {
        int h1, m1, s1, h2, m2, s2;
        char operacion;

        cout << "Ingrese el primer horario (hh:mm:ss): ";
        cin >> h1 >> m1 >> s1;
        cout << "Ingrese el segundo horario (hh:mm:ss): ";
        cin >> h2 >> m2 >> s2;

        Horario horario1(h1, m1, s1);
        Horario horario2(h2, m2, s2);

        cout << "¿Desea sumar (+) o restar (-) los horarios? ";
        cin >> operacion;

        Horario resultado;
        if (operacion == '+') {
            resultado = horario1 + horario2;
        } else if (operacion == '-') {
            resultado = horario1 - horario2;
        } else {
            cout << "Operacion no valida." << endl;
            return 1;
        }

        resultado.mostrarEstandar();
        resultado.mostrarMilitar();

        cout << "¿Desea realizar otra operacion? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    return 0;
}

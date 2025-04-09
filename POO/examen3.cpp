#include <iostream>
#include <string>
using namespace std;
/*  
Elabore programa en C++ que tenga Herencia de clases con 
    ✅clases abstractas y clases concretas,
    y todas las clases tengan constructor y destructor, 
    
    ✅ miembros privados, 
    ✅ miembros protegidos, 
    ✅ miembros publicos, 
    
    ✅ sobrecarga de operadores y 
    ✅ puntero this. 
    Que debe cumplir con la siguiente imagen.
    ✅ Caballo y perro heredan de mamifero, 
    ✅ rana de anfibio, 
    ✅ reptil, anfibio y mamifero heredan de animal

    Muestre al menos 3 caracteristicas contenidas en cada una de las clases,  
    
    y que se repita mientras el usuario quiera.
*/

class Animal {
private:
short edad;
protected:
string nombre;
public:
    
    Animal(string nombre = "Animal", short edad = 0) : nombre(nombre), edad(edad) {
        cout << "Constructor Animal: " << this->nombre << endl;
    }
    
    virtual ~Animal() {
        cout << "Destructor Animal: " << this->nombre << endl;
    }

    // Método virtual para obtener información
    virtual void mostrarInformacion() {
        cout << "Nombre: " << this->nombre << ", Edad: " << this->edad << endl;
    }

    // Sobrecarga del operador =
    Animal& operator=(const Animal& otro) {
        this->nombre = otro.nombre;
        this->edad = otro.edad;
        return *this;
    }
};

class Mamifero : public Animal {
private:
    string tipoPelo;
protected:
    bool tieneGlandulasMamarias;
public:
    
    Mamifero(string nombre = "Mamifero", short edad = 0, string tipoPelo = "Desconocido", bool tieneGlandulasMamarias = true)
        : Animal(nombre, edad), tipoPelo(tipoPelo), tieneGlandulasMamarias(tieneGlandulasMamarias) {
        cout << "Constructor Mamifero: " << this->nombre << endl;
    }
    
    ~Mamifero() {
        cout << "Destructor Mamifero: " << this->nombre << endl;
    }

    void mostrarInformacion() override {
        Animal::mostrarInformacion();
        cout << "Tipo de Pelo: " << this->tipoPelo << ", Glandulas Mamarias: " << (this->tieneGlandulasMamarias ? "Si" : "No") << endl;
    }
};

class Reptil : public Animal {
private:
    string tipoEscamas;
protected:
    bool esVenenoso;
public:
    
    Reptil(string nombre = "Reptil", short edad = 0, string tipoEscamas = "Desconocido", bool esVenenoso = false)
        : Animal(nombre, edad), tipoEscamas(tipoEscamas), esVenenoso(esVenenoso) {
        cout << "Constructor Reptil: " << this->nombre << endl;
    }
    
    ~Reptil() {
        cout << "Destructor Reptil: " << this->nombre << endl;
    }

    void mostrarInformacion() override {
        Animal::mostrarInformacion();
        cout << "Tipo de Escamas: " << this->tipoEscamas << ", Venenoso: " << (this->esVenenoso ? "Si" : "No") << endl;
    }
};

class Anfibio : public Animal {
private:
    string habitat;
protected:
    bool necesitaAgua;
public:

    Anfibio(string nombre = "Anfibio", short edad = 0, string habitat = "Desconocido", bool necesitaAgua = true)
        : Animal(nombre, edad), habitat(habitat), necesitaAgua(necesitaAgua) {
        cout << "Constructor Anfibio: " << this->nombre << endl;
    }

    ~Anfibio() {
        cout << "Destructor Anfibio: " << this->nombre << endl;
    }

    void mostrarInformacion() override {
        Animal::mostrarInformacion();
        cout << "Habitat: " << this->habitat << ", Necesita Agua: " << (this->necesitaAgua ? "Si" : "No") << endl;
    }
};

class Rana : public Anfibio {
private:
    string color;
public:

    Rana(string nombre = "Rana", short edad = 0, string habitat = "Desconocido", bool necesitaAgua = true, string color = "Verde")
        : Anfibio(nombre, edad, habitat, necesitaAgua), color(color) {
        cout << "Constructor Rana: " << this->nombre << endl;
    }

    ~Rana() {
        cout << "Destructor Rana: " << this->nombre << endl;
    }

    void mostrarInformacion() override {
        Anfibio::mostrarInformacion();
        cout << "Color: " << this->color << endl;
    }
};

class Perro : public Mamifero {
private:
    string raza;
public:

    Perro(string nombre = "Perro", short edad = 0, string tipoPelo = "Corto", bool tieneGlandulasMamarias = true, string raza = "Desconocida")
        : Mamifero(nombre, edad, tipoPelo, tieneGlandulasMamarias), raza(raza) {
        cout << "Constructor Perro: " << this->nombre << endl;
    }

    ~Perro() {
        cout << "Destructor Perro: " << this->nombre << endl;
    }

    void mostrarInformacion() override {
        Mamifero::mostrarInformacion();
        cout << "Raza: " << this->raza << endl;
    }
};

class Caballo : public Mamifero {
private:
    string color;
public:

    Caballo(string nombre = "Caballo", short edad = 0, string tipoPelo = "Largo", bool tieneGlandulasMamarias = true, string color = "Cafe")
        : Mamifero(nombre, edad, tipoPelo, tieneGlandulasMamarias), color(color) {
        cout << "Constructor Caballo: " << this->nombre << endl;
    }

    ~Caballo() {
        cout << "Destructor Caballo: " << this->nombre << endl;
    }

    void mostrarInformacion() override {
        Mamifero::mostrarInformacion();
        cout << "Color: " << this->color << endl;
    }
};

int main() {
    char repetir = 's';

    while (repetir == 's' || repetir == 'S') {
        string nombre;
        short edad;
        cout << "Ingrese el nombre del animal: ";
        cin >> nombre;
        cout << "Ingrese la edad del animal: ";
        cin >> edad;
        Animal* animal = new Animal(nombre, edad);

        cout << "Ingrese el nombre del mamifero: ";
        cin >> nombre;
        cout << "Ingrese la edad del mamifero: ";
        cin >> edad;

        string pelo;
        cin>> pelo;


        Mamifero* mamifero = new Mamifero("MamiferoGenerico", 3, "Mediano", true);
        Reptil* reptil = new Reptil("ReptilGenerico", 2, "Dura", false);
        Anfibio* anfibio = new Anfibio("AnfibioGenerico", 1, "Mixto", true);
        Rana* rana = new Rana("RanaRenata", 1, "Pantano", true, "Verde");
        Perro* perro = new Perro("PerroPoncho", 4, "Corto", true, "Callejero");
        Caballo* caballo = new Caballo("CallaboJuan", 6, "Largo", true, "Cafe");

        // Mostrar información de los objetos
        animal->mostrarInformacion();
        mamifero->mostrarInformacion();
        reptil->mostrarInformacion();
        anfibio->mostrarInformacion();
        rana->mostrarInformacion();
        perro->mostrarInformacion();
        caballo->mostrarInformacion();

        // Liberar la memoria
        delete animal;
        delete mamifero;
        delete reptil;
        delete anfibio;
        delete rana;
        delete perro;
        delete caballo;

        cout << "¿Desea repetir el proceso? (s/n): ";
        cin >> repetir;
    }

    cout << "Programa finalizado." << endl;

    return 0;
}
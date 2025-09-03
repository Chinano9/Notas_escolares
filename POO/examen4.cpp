/*


Implemente un sistema de contactos universitarios en C++. El programa debe cumplir los siguientes requisitos técnicos:

    Utilizar clases para representar contactos.
    Implementar constructores, destructores, puntero this, y plantillas para funciones que manipulen datos genéricos.
    Cada contacto tendrá: Nombre, Apellido, Teléfono, Carrera, Matrícula y un contacto de referencia (amigo o compañero).
    Se podrán ingresar entre 3 y 5 contactos por teclado.
    El programa debe tener un menú que permita:
        a) Agregar nuevos contactos.
        b) Buscar un contacto por nombre o matrícula.
        c) Mostrar todos los contactos y sus referencias.

Permita al usuario ejecutar operaciones múltiples hasta que decida salir.
*/

#include<iostream>
#include<algorithm>
#include<string>


using namespace std;

class Contacto
{
private:
    string nombre;
    string apellido;
    string telefono;
    string carrera;
    string matricula;
    Contacto* referencia;
public:
    Contacto(string nombre, string apellido, string telefono, string carrera, string matricula)
    {
        this->nombre = nombre;
        this->apellido = apellido;
        this->telefono = telefono;
        this->carrera = carrera;
        this->matricula = matricula;
        referencia = nullptr;
    }

    ~Contacto()
    {
        delete referencia;
    }


    void setReferencia(Contacto* ref)
    {
       this->referencia = ref;
    }

    string getNombre()
    {
        return this->nombre;
    }
    string getMatricula()
    {
        return this->matricula;
    }
    string getTelefono()
    {
        return this->telefono;
    }
    string getCarrera()
    {
        return this->carrera;
    }
    string getApellido()
    {
        return this->apellido;
    }
    string getReferencia()
    {
        return this->referencia->nombre;
    }

    void mostrar()
    {
        cout<< "Nombre: " << this->nombre << endl;
        cout<< "Apellido: " << this->apellido << endl;
        cout<< "Telefono: " << this->telefono << endl;
        cout<< "Carrera: " << this->carrera << endl;
        cout<< "Matricula: " << this->matricula << endl;

        if (this->referencia != nullptr)
        {
            cout<< "Referencia: " << this->referencia->nombre << " " << this->referencia->apellido << endl;
        }
        else
        {
            cout<< "Sin referencia" << endl;
        }
    }
};

int main()
{
    Contacto* contactos[5];
    int numContactos = 0;
    int opcion;

    while (true)
    {
        cout<< "Menu:" << endl;
        cout<< "1. Agregar contacto" << endl;
        cout<< "2. Buscar contacto" << endl;
        cout<< "3. Mostrar contactos" << endl;
        cout<< "4. Salir" << endl;
        cout<< "Seleccione una opcion: ";
        cin>> opcion;

        switch (opcion)
        {
            case 1:
                if (numContactos < 5)
                {
                    string nombre, apellido, telefono, carrera, matricula;
                    cout<< "Ingrese nombre: ";
                    cin>> nombre;
                    cout<< "Ingrese apellido(s): ";
                    cin>> apellido;
                    cout<< "Ingrese telefono: ";
                    cin>> telefono;
                    cout<< "Ingrese carrera: ";
                    cin>> carrera;
                    cout<< "Ingrese matricula: ";
                    cin>> matricula;

                    Contacto* nuevoContacto = new Contacto(nombre, apellido, telefono, carrera, matricula);
                    contactos[numContactos++] = nuevoContacto;

                    // Asignar referencia si hay otro contacto
                    if (numContactos > 1)
                    {
                        string refNombre;
                        cout<< "Ingrese nombre o matricula de referencia: ";
                        cin>> refNombre;

                        for (int i = 0; i < numContactos - 1; i++)
                        {
                            if (contactos[i]->getNombre() == refNombre || contactos[i]->getMatricula() == refNombre)
                            {
                                // Asignar referencia al nuevo contacto
                                cout<< "Referencia encontrada: " << contactos[i]->getNombre() << endl;
                                cout<< "Referencia asignada." << endl;
                                nuevoContacto->setReferencia(contactos[i]);
                                break;
                            }else{
                                cout<< "Referencia no encontrada." << endl;
                            }
                        }
                    }
                }
                else
                {
                    cout<< "Limite de contactos alcanzado." << endl;
                }
                break;

            case 2:
                {// Es para evitar el error de scope de la variable busqueda
                    string busqueda;
                    cout<< "Ingrese nombre o matricula a buscar: ";
                    cin>> busqueda;

                    for (int i = 0; i < numContactos; i++)
                    {
                        if (contactos[i]->getNombre() == busqueda || contactos[i]->getMatricula() == busqueda)
                        {
                            contactos[i]->mostrar();
                            break;
                        }
                        if (i == numContactos - 1)
                        {
                            cout<< "Contacto no encontrado." << endl;
                        }
                    }
                    break;
                }

            case 3:
                for (int i = 0; i < numContactos; i++)
                {
                    contactos[i]->mostrar();
                }
                break;

            case 4:
                return 0;

            default:
                cout<< "Opcion no valida." << endl;
        }
    }

    return 0;
}
/**01 –Descripción del problema
Enunciado:
Desarrolle una solución  que  permita  almacenar  el  código,  nombre  y  la  nota  final  de  todos  los alumnos de un salón de clase teniendo en cuenta el Diagrama de Clase y la Gráfica de Estructura de Datos mostrados. También desarrolle todos los métodos necesarios para actualizar y controlar los datos almacenados. Utilice 2 clases para el desarrollo de la solución.
*/

#include <iostream>

class Alumno {
    private:
        int codigo;
        std::string nombre;
        float notaFinal;
    public:
        Alumno(int c, std::string n, float nf) : codigo(c), nombre(n), notaFinal(nf) {}
        int getCodigo() { return codigo; }
        void setCodigo(int c) { codigo = c; }
        std::string getNombre() { return nombre; }
        void setNombre(std::string n) { nombre = n; }
        float getNotaFinal() { return notaFinal; }
        void setNotaFinal(float nf) { notaFinal = nf; }
};

class PrgAlumno {
    private:
        std::vector<Alumno> * alumnos;
    public:
        PrgAlumno(int cap) : {
            alumnos = new Alumno[capacidad];
        }
        ~PrgAlumno() {
            delete[] alumnos;
        }
        void main(){

        }

        void menu(){
            int opcion;
            do {
                std::cout << "1. Agregar Alumno" << std::endl;
                std::cout << "2. Mostrar Alumnos" << std::endl;
                std::cout << "3. Salir" << std::endl;
                std::cout << "Seleccione una opción: ";
                std::cin >> opcion;

                int codigo;
                float notaFinal;
                std::string nombre;
                switch(opcion) {
                    case 1:
                        std::cout << "Ingrese código: ";
                        std::cin >> codigo;
                        std::cout << "Ingrese nombre: ";
                        std::cin >> nombre;
                        std::cout << "Ingrese nota final: ";
                        std::cin >> notaFinal;
                        ingresarDatos(codigo, nombre, notaFinal);
                        break;
                    case 2:
                        mostrarAlumnos();
                        break;
                    case 3:
                        std::cout << "Saliendo..." << std::endl;
                        break;
                    default:
                        std::cout << "Opción inválida." << std::endl;
                }
            } while(opcion != 3);
        }
        void ingresarDatos(int codigo, std::string nombre, float notaFinal) {
            if(cantidad < capacidad) {
                alumnos[cantidad] = Alumno(codigo, nombre, notaFinal);
                cantidad++;
            } else {
                std::cout << "Capacidad máxima alcanzada." << std::endl;
            }
        }

};

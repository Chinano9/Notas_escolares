#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <algorithm>

using namespace std;


/**
 * @brief Clase para representar una Materia.
 */
class Materia {
public:
    string codigo;
    string nombre;
    int semestre;
    string horario; // Ej: "Lun 10:00-12:00"

    Materia(string cod = "", string nom = "", int sem = 0, string hor = "")
        : codigo(cod), nombre(nom), semestre(sem), horario(hor) {}

    void mostrarInfo() const {
        cout << "   - Código: " << codigo << ", Nombre: " << nombre
             << ", Semestre: " << semestre << ", Horario: " << horario << endl;
    }
};

/**
 * @brief Clase para representar un Profesor.
 */
class Profesor {
public:
    string id;
    string nombre;
    string especialidad;
    vector<string> materias_impartidas;

    Profesor(string i = "",
                 string n = "",
                 string esp = "",
                 vector<string> mat = {})
            : id(i), nombre(n), especialidad(esp), materias_impartidas(mat) {}

    void mostrarInfo() const {
        cout << "   - ID: " << id << ", Nombre: " << nombre
             << ", Especialidad: " << especialidad << endl;
    }
};

/**
 * @brief Clase para representar un Estudiante.
 */
class Estudiante {
public:
    string id;
    string nombre;
    string grado;
    string email;
    map<string, double> calificaciones;

    Estudiante(string i = "", string n = "", string g = "", string e = "")
        : id(i), nombre(n), grado(g), email(e) {}

    void mostrarInfo() const {
        cout << "   - ID: " << id << ", Nombre: " << nombre
             << ", Grado: " << grado << ", Email: " << email << endl;
    }
};

// --- CLASE CONTENEDORA DEL SISTEMA ---

/**
 * @brief Clase principal del sistema de administración escolar.
 * Utiliza STL map para gestionar las colecciones de entidades.
 */
class Escuela {
private:
    // MAPS PRINCIPALES: La clave es el identificador único (ID/Código)
    map<string, Estudiante> estudiantes;
    map<string, Profesor> profesores;
    map<string, Materia> materias;
    // MAP para Inscripciones: Clave (Código Materia) -> Valor (Lista de ID de Estudiantes)
    map<string, vector<string>> inscripciones;

public:
    // --- FUNCIONALIDADES DE REGISTRO ---

    void agregarEstudiante(const Estudiante& e) {
        if (estudiantes.count(e.id)) {
            cout << "Error: Ya existe un estudiante con ID " << e.id << endl;
            return;
        }
        estudiantes[e.id] = e;
        cout << "Estudiante " << e.nombre << " registrado con éxito." << endl;
    }

    void agregarProfesor(const Profesor& p) {
        if (profesores.count(p.id)) {
            cout << "Error: Ya existe un profesor con ID " << p.id << endl;
            return;
        }
        profesores[p.id] = p;
        cout << "Profesor/a " << p.nombre << " registrado con éxito." << endl;
    }

    void agregarMateria(const Materia& m) {
        if (materias.count(m.codigo)) {
            cout << "Error: Ya existe una materia con código " << m.codigo << endl;
            return;
        }
        materias[m.codigo] = m;
        cout << "Materia " << m.nombre << " registrada con éxito." << endl;
    }

    // --- FUNCIONALIDADES ACADÉMICAS ---

    void inscribirEstudiante(const string& id_est, const string& cod_mat) {
        if (!estudiantes.count(id_est)) {
            cout << "Error: Estudiante con ID " << id_est << " no encontrado." << endl;
            return;
        }
        if (!materias.count(cod_mat)) {
            cout << "Error: Materia con código " << cod_mat << " no encontrada." << endl;
            return;
        }

        // 1. Agregar materia al registro de calificaciones del estudiante (inicialmente sin nota)
        estudiantes[id_est].calificaciones[cod_mat] = -1.0; // Usamos -1.0 para indicar sin calificar

        // 2. Agregar estudiante a la lista de inscritos de la materia
        // Si la materia existe en inscripciones, agrega. Si no, crea el vector y agrega.
        inscripciones[cod_mat].push_back(id_est);

        cout << "Estudiante " << estudiantes[id_est].nombre
             << " inscrito en " << materias[cod_mat].nombre << " con éxito." << endl;
    }

    void registrarCalificacion(const string& id_est, const string& cod_mat, double nota) {
        if (!estudiantes.count(id_est)) {
            cout << "Error: Estudiante con ID " << id_est << " no encontrado." << endl;
            return;
        }

        // Usamos la característica de busqueda por clave del map
        auto& notas_estudiante = estudiantes[id_est].calificaciones;

        if (!notas_estudiante.count(cod_mat)) {
            cout << "Error: Estudiante no está inscrito en la materia " << cod_mat << "." << endl;
            return;
        }

        if (nota < 0.0 || nota > 10.0) {
            cout << "Error: La calificación debe estar entre 0.0 y 10.0." << endl;
            return;
        }

        notas_estudiante[cod_mat] = nota;
        cout << "Calificación de " << nota << " registrada para "
             << estudiantes[id_est].nombre << " en " << materias[cod_mat].nombre << "." << endl;
    }

    // --- FUNCIONALIDADES DE REPORTE ---

    /**
     * @brief Muestra el historial académico de un estudiante (materias y calificaciones).
     */
    void mostrarHistorialAcademico(const string& id_est) const {
        auto it = estudiantes.find(id_est);
        if (it == estudiantes.end()) {
            cout << "Error: Estudiante con ID " << id_est << " no encontrado." << endl;
            return;
        }

        const Estudiante& e = it->second;
        cout << "\n--- Historial Académico de " << e.nombre << " (ID: " << e.id << ") ---" << endl;

        if (e.calificaciones.empty()) {
            cout << "El estudiante no tiene materias inscritas." << endl;
            return;
        }

        for (const auto& par : e.calificaciones) {
            const string& cod_mat = par.first;
            double calif = par.second;

            string nombre_mat = materias.count(cod_mat) ? materias.at(cod_mat).nombre : "Materia Desconocida";
            string str_calif = (calif >= 0.0) ? to_string(calif) : "Pendiente";

            cout << " - " << nombre_mat << " (" << cod_mat << "): " << str_calif << endl;
        }
        cout << "-----------------------------------------------------" << endl;
    }

    /**
     * @brief Muestra las materias que imparte un profesor y los estudiantes inscritos.
     */
    void mostrarCargaProfesor(const string& id_prof) const {
        auto it = profesores.find(id_prof);
        if (it == profesores.end()) {
            cout << "Error: Profesor con ID " << id_prof << " no encontrado." << endl;
            return;
        }

        const Profesor& p = it->second;
        cout << "\n--- Carga Académica de " << p.nombre << " (ID: " << p.id << ") ---" << endl;

        for (const string& cod_mat : p.materias_impartidas) {
            string nombre_mat = materias.count(cod_mat) ? materias.at(cod_mat).nombre : "Materia Desconocida";
            cout << "\n- Materia: " << nombre_mat << " (" << cod_mat << ")" << endl;

            auto it_insc = inscripciones.find(cod_mat);
            if (it_insc != inscripciones.end() && !it_insc->second.empty()) {
                cout << "  Estudiantes inscritos (" << it_insc->second.size() << "):" << endl;
                for (const string& id_est : it_insc->second) {
                    string nombre_est = estudiantes.count(id_est) ? estudiantes.at(id_est).nombre : "Nombre Desconocido";
                    cout << "    * " << nombre_est << " (ID: " << id_est << ")" << endl;
                }
            } else {
                cout << "  No hay estudiantes inscritos en esta materia." << endl;
            }
        }
        cout << "--------------------------------------------------------" << endl;
    }

    /**
     * @brief Genera un reporte del promedio general de una materia.
     */
    void generarReportePromedioMateria(const string& cod_mat) const {
        if (!materias.count(cod_mat)) {
            cout << "Error: Materia con código " << cod_mat << " no encontrada." << endl;
            return;
        }

        cout << "\n--- Reporte de Promedio para " << materias.at(cod_mat).nombre
             << " (" << cod_mat << ") ---" << endl;

        auto it_insc = inscripciones.find(cod_mat);
        if (it_insc == inscripciones.end() || it_insc->second.empty()) {
            cout << "No hay estudiantes inscritos o calificaciones en esta materia." << endl;
            return;
        }

        double suma_calificaciones = 0.0;
        int estudiantes_contados = 0;

        for (const string& id_est : it_insc->second) {
            auto it_est = estudiantes.find(id_est);
            if (it_est != estudiantes.end()) {
                // Buscamos la calificación en el map del estudiante
                auto it_calif = it_est->second.calificaciones.find(cod_mat);

                if (it_calif != it_est->second.calificaciones.end() && it_calif->second >= 0.0) {
                    suma_calificaciones += it_calif->second;
                    estudiantes_contados++;
                }
            }
        }

        if (estudiantes_contados > 0) {
            double promedio = suma_calificaciones / estudiantes_contados;
            cout << fixed << setprecision(2);
            cout << "Calificaciones registradas: " << estudiantes_contados << endl;
            cout << "Suma total de calificaciones: " << suma_calificaciones << endl;
            cout << "PROMEDIO GENERAL DE LA MATERIA: " << promedio << endl;
            cout << scientific << setprecision(6); // Resetear formato
        } else {
            cout << "Ningún estudiante inscrito tiene una calificación registrada aún." << endl;
        }
        cout << "---------------------------------------------------" << endl;
    }

    // --- POBLACIÓN DE DATOS INICIALES ---

    /**
     * @brief Carga los datos de prueba requeridos por el ejercicio (10 est, 4 prof, 16 mat).
     */
    void cargarDatosIniciales() {
        cout << "\n*** Cargando datos iniciales de prueba... ***" << endl;


        agregarEstudiante({"E001", "Ana Garcia", "10mo", "ana.g@alumnos.uacj.mx"});
        agregarEstudiante({"E002", "Luis Perez", "10mo", "luis.p@alumnos.uacj.mx"});
        agregarEstudiante({"E003", "Maria Lopez", "9no", "maria.l@alumnos.uacj.mx"});
        agregarEstudiante({"E004", "Juan Rodas", "9no", "juan.r@alumnos.uacj.mx"});
        agregarEstudiante({"E005", "Sofia Morales", "11vo", "sofia.m@alumnos.uacj.mx"});
        agregarEstudiante({"E006", "Carlos Soto", "11vo", "carlos.s@alumnos.uacj.mx"});
        agregarEstudiante({"E007", "Elena Castro", "10mo", "elena.c@alumnos.uacj.mx"});
        agregarEstudiante({"E008", "David Vega", "9no", "david.v@alumnos.uacj.mx"});
        agregarEstudiante({"E009", "Isabel Rico", "11vo", "isabel.r@alumnos.uacj.mx"});
        agregarEstudiante({"E010", "Pedro Salas", "10mo", "pedro.s@alumnos.uacj.mx"});
        agregarEstudiante({"E011", "Laura Montes", "9no", "laura.m@alumnos.uacj.mx"});

        agregarProfesor({"P101", "Dr. Alan Turing", "Programación", {}});
        agregarProfesor({"P102", "Ing. Ada Lovelace", "Matemáticas", {}});
        agregarProfesor({"P103", "Mtro. Nikola Tesla", "Física", {}});
        agregarProfesor({"P104", "Lic. Marie Curie", "Química", {}});


        agregarMateria({"MAT101", "Intro a C++", 1, "Lun/Mie 08:00-09:30"});
        agregarMateria({"MAT102", "Estructuras de Datos", 1, "Mar/Jue 08:00-09:30"});
        agregarMateria({"MAT103", "Bases de Datos", 2, "Lun/Mie 09:30-11:00"});
        agregarMateria({"MAT104", "Redes", 2, "Mar/Jue 09:30-11:00"});
        profesores["P101"].materias_impartidas = {"MAT101", "MAT102", "MAT103", "MAT104"};

        agregarMateria({"MAT201", "Álgebra Lineal", 1, "Vie 10:00-12:00"});
        agregarMateria({"MAT202", "Cálculo Integral", 2, "Lun/Mie 11:00-12:30"});
        agregarMateria({"MAT203", "Estadística", 3, "Mar/Jue 11:00-12:30"});
        agregarMateria({"MAT204", "Matemática Discreta", 4, "Vie 13:00-15:00"});
        profesores["P102"].materias_impartidas = {"MAT201", "MAT202", "MAT203", "MAT204"};

        agregarMateria({"MAT301", "Física Clásica", 1, "Lun 13:00-14:30"});
        agregarMateria({"MAT302", "Termodinámica", 2, "Mar 13:00-14:30"});
        agregarMateria({"MAT303", "Electromagnetismo", 3, "Mie 13:00-14:30"});
        agregarMateria({"MAT304", "Mecánica Cuántica", 4, "Jue 13:00-14:30"});
        profesores["P103"].materias_impartidas = {"MAT301", "MAT302", "MAT303", "MAT304"};


        agregarMateria({"MAT401", "Química General", 1, "Vie 16:00-17:30"});
        agregarMateria({"MAT402", "Química Orgánica", 2, "Lun 16:00-17:30"});
        agregarMateria({"MAT403", "Bioquímica", 3, "Mar 16:00-17:30"});
        agregarMateria({"MAT404", "Química Física", 4, "Mie 16:00-17:30"});
        profesores["P104"].materias_impartidas = {"MAT401", "MAT402", "MAT403", "MAT404"};

        // E001 (Ana) en 3 materias
        inscribirEstudiante("E001", "MAT101"); registrarCalificacion("E001", "MAT101", 9.5);
        inscribirEstudiante("E001", "MAT201"); registrarCalificacion("E001", "MAT201", 8.0);
        inscribirEstudiante("E001", "MAT301"); registrarCalificacion("E001", "MAT301", 7.5);

        // E002 (Luis) en 2 materias
        inscribirEstudiante("E002", "MAT101"); registrarCalificacion("E002", "MAT101", 6.0);
        inscribirEstudiante("E002", "MAT201"); registrarCalificacion("E002", "MAT201", 7.0);

        // E003 (Maria) en 2 materias
        inscribirEstudiante("E003", "MAT101"); registrarCalificacion("E003", "MAT101", 10.0);
        inscribirEstudiante("E003", "MAT401"); registrarCalificacion("E003", "MAT401", 9.0);

        // E004 (Juan) en 1 materia (pendiente)
        inscribirEstudiante("E004", "MAT101");

        // E005, E006, E007, E008, E009, E010, E011 en otras materias
        inscribirEstudiante("E005", "MAT304"); registrarCalificacion("E005", "MAT304", 8.5);
        inscribirEstudiante("E006", "MAT304"); registrarCalificacion("E006", "MAT304", 7.5);
        inscribirEstudiante("E007", "MAT202"); registrarCalificacion("E007", "MAT202", 6.5);
        inscribirEstudiante("E008", "MAT402"); registrarCalificacion("E008", "MAT402", 9.0);
        inscribirEstudiante("E009", "MAT203"); registrarCalificacion("E009", "MAT203", 8.0);
        inscribirEstudiante("E010", "MAT403"); registrarCalificacion("E010", "MAT403", 7.0);
        inscribirEstudiante("E011", "MAT401"); registrarCalificacion("E011", "MAT401", 8.0);

        cout << "\n*** Datos iniciales cargados. ¡Listo para la administración! ***\n" << endl;
    }

    // --- FUNCIONES DE UTILIDAD (MENU) ---
    const map<string, Estudiante>& getEstudiantes() const { return estudiantes; }
    const map<string, Profesor>& getProfesores() const { return profesores; }
    const map<string, Materia>& getMaterias() const { return materias; }
};

// --- INTERFAZ DE USUARIO (MENÚ) ---

void mostrarMenuPrincipal() {
    cout << "\n==============================================" << endl;
    cout << "          SISTEMA DE GESTIÓN ESCOLAR          " << endl;
    cout << "==============================================" << endl;
    cout << "1. Administración de Estudiantes y Docentes" << endl;
    cout << "2. Gestión Académica (Inscribir/Calificar)" << endl;
    cout << "3. Reportes y Consultas" << endl;
    cout << "0. Salir" << endl;
    cout << "==============================================" << endl;
    cout << "Seleccione una opción: ";
}

void mostrarMenuAdmin() {
    cout << "\n--- Menú de Administración ---" << endl;
    cout << "1. Registrar nuevo Estudiante" << endl;
    cout << "2. Registrar nuevo Profesor" << endl;
    cout << "3. Registrar nueva Materia" << endl;
    cout << "4. Listar Estudiantes (IDs)" << endl;
    cout << "5. Listar Profesores (IDs)" << endl;
    cout << "0. Volver al menú principal" << endl;
    cout << "Seleccione una opción: ";
}

void mostrarMenuAcademico() {
    cout << "\n--- Menú de Gestión Académica ---" << endl;
    cout << "1. Inscribir Estudiante en Materia" << endl;
    cout << "2. Registrar Calificación" << endl;
    cout << "0. Volver al menú principal" << endl;
    cout << "Seleccione una opción: ";
}

void mostrarMenuReportes() {
    cout << "\n--- Menú de Reportes ---" << endl;
    cout << "1. Historial Académico de un Estudiante" << endl;
    cout << "2. Materias impartidas por un Profesor y sus inscritos" << endl;
    cout << "3. Reporte de Promedio General por Materia" << endl;
    cout << "0. Volver al menú principal" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    Escuela sistema;
    sistema.cargarDatosIniciales();

    int opcion_principal, opcion_sub;
    string id, codigo, nombre, grado, email, especialidad;
    double nota;

    do {
        mostrarMenuPrincipal();
        cin >> opcion_principal;

        switch (opcion_principal) {
            case 1:
                do {
                    mostrarMenuAdmin();
                    cin >> opcion_sub;
                    cin.ignore();

                    switch (opcion_sub) {
                        case 1:
                            cout << "ID (E0XX): "; getline(cin, id);
                            cout << "Nombre: "; getline(cin, nombre);
                            cout << "Grado: "; getline(cin, grado);
                            cout << "Email: "; getline(cin, email);
                            sistema.agregarEstudiante({id, nombre, grado, email});
                            break;
                        case 2:
                            cout << "ID (PXXX): "; getline(cin, id);
                            cout << "Nombre: "; getline(cin, nombre);
                            cout << "Especialidad: "; getline(cin, especialidad);
                            sistema.agregarProfesor({id, nombre, especialidad});
                            break;
                        case 3:
                            cout << "Código (MATXXX): "; getline(cin, codigo);
                            cout << "Nombre: "; getline(cin, nombre);
                            cout << "Semestre: "; cin >> opcion_sub; cin.ignore();
                            cout << "Horario: "; getline(cin, grado); // Grado se usa como horario para evitar declarar otra variable
                            sistema.agregarMateria({codigo, nombre, opcion_sub, grado});
                            break;
                        case 4:
                            cout << "\n--- Lista de Estudiantes ---" << endl;
                            for (const auto& par : sistema.getEstudiantes()) {
                                par.second.mostrarInfo();
                            }
                            cout << "----------------------------" << endl;
                            break;
                        case 5:
                            cout << "\n--- Lista de Profesores ---" << endl;
                            for (const auto& par : sistema.getProfesores()) {
                                par.second.mostrarInfo();
                            }
                            cout << "---------------------------" << endl;
                            break;
                        case 0: break;
                        default: cout << "Opción inválida." << endl;
                    }
                } while (opcion_sub != 0);
                break;

            case 2: // Gestión Académica
                do {
                    mostrarMenuAcademico();
                    cin >> opcion_sub;
                    cin.ignore();

                    switch (opcion_sub) {
                        case 1:
                            cout << "ID del Estudiante: "; getline(cin, id);
                            cout << "Código de la Materia: "; getline(cin, codigo);
                            sistema.inscribirEstudiante(id, codigo);
                            break;
                        case 2:
                            cout << "ID del Estudiante: "; getline(cin, id);
                            cout << "Código de la Materia: "; getline(cin, codigo);
                            cout << "Calificación (0.0-10.0): "; cin >> nota; cin.ignore();
                            sistema.registrarCalificacion(id, codigo, nota);
                            break;
                        case 0: break;
                        default: cout << "Opción inválida." << endl;
                    }
                } while (opcion_sub != 0);
                break;

            case 3: // Reportes
                do {
                    mostrarMenuReportes();
                    cin >> opcion_sub;
                    cin.ignore();

                    switch (opcion_sub) {
                        case 1:
                            cout << "ID del Estudiante para historial: "; getline(cin, id);
                            sistema.mostrarHistorialAcademico(id);
                            break;
                        case 2:
                            cout << "ID del Profesor para carga: "; getline(cin, id);
                            sistema.mostrarCargaProfesor(id);
                            break;
                        case 3:
                            cout << "Código de la Materia para promedio: "; getline(cin, codigo);
                            sistema.generarReportePromedioMateria(codigo);
                            break;
                        case 0: break;
                        default: cout << "Opción inválida." << endl;
                    }
                } while (opcion_sub != 0);
                break;

            case 0:
                cout << "Saliendo del sistema. ¡Hasta pronto!" << endl;
                break;
            default:
                cout << "Opción principal inválida. Por favor, intente de nuevo." << endl;
        }

    } while (opcion_principal != 0);

    return 0;
}

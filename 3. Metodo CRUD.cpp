#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Estructura estudiante 
struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    float notas[4];
    float promedio;
    string resultado;
};

// Función para almacenar los datos de los estudiantes 
void ingresarEstudiante(Estudiante* estudiante) {
    cout << "Ingrese el ID del estudiante: ";
    cin >> estudiante->id;
    cout << "Ingrese los nombres del estudiante: ";
    cin.ignore();
    getline(cin, estudiante->nombres);
    cout << "Ingrese los apellidos del estudiante: ";
    getline(cin, estudiante->apellidos);
    cout << "Ingrese las notas del estudiante (nota1 nota2 nota3 nota4): ";
    for (int i = 0; i < 4; ++i) {
        cin >> estudiante->notas[i];
    }
    // promedio 
    float suma = 0;
    for (int i = 0; i < 4; ++i) {
        suma += estudiante->notas[i];
    }
    estudiante->promedio = suma / 4.0;
    // resultado
    estudiante->resultado = (estudiante->promedio > 60) ? "Aprobado" : "Reprobado";
}

// Función para guardar los datos de los estudiantes 
void guardarEstudianteEnArchivo(const Estudiante* estudiante) {
    ofstream archivo("notas.dat", ios::binary | ios::app);
    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<const char*>(estudiante), sizeof(Estudiante));
        archivo.close();
        cout << "Estudiante guardado exitosamente en el archivo." << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

// Función para leer todos los estudiantes almacenados 
void leerEstudiantesDelArchivo() {
    ifstream archivo("notas.dat", ios::binary);
    if (archivo.is_open()) {
        Estudiante estudiante;
        while (archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
            cout << "ID: " << estudiante.id << endl;
            cout << "Nombres: " << estudiante.nombres << endl;
            cout << "Apellidos: " << estudiante.apellidos << endl;
            cout << "Notas: ";
            for (int i = 0; i < 4; ++i) {
                cout << estudiante.notas[i] << " ";
            }
            cout << endl;
            cout << "Promedio: " << estudiante.promedio << endl;
            cout << "Resultado: " << estudiante.resultado << endl;
            cout << endl;
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

// Metodo CRUD 
int main() {
    int opcion;
    do {
        cout << "\nMENU:" << endl;
        cout << "1. Ingresar estudiante" << endl; //crear
        cout << "2. Mostrar todos los estudiantes" << endl; //leer
        cout << "0. Salir" << endl; // borrar
        cout << "Ingrese su opcion: "; // actualizar 
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Estudiante nuevoEstudiante;
                ingresarEstudiante(&nuevoEstudiante);
                guardarEstudianteEnArchivo(&nuevoEstudiante);
                break;
            }
            case 2: {
                leerEstudiantesDelArchivo();
                break;
            }
            case 0: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default: {
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
            }
        }
    } while (opcion != 0);

    return 0;
}


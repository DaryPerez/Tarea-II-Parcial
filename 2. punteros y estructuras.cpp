#include <iostream>
#include <string>

using namespace std;

// Struct para de la estructura Estudiante
struct Estudiante {
    int id;
    string nombre;
    string apellido;
    float notas[4];
    float promedio;
    bool aprobado;
};

// Función para ingresar los datos de los estudiantes
//Puntero de estructura Estudiante 
void ingresarEstudiante(Estudiante* estudiante) {
    cout << "Ingrese el ID del estudiante: ";
    cin >> estudiante->id;
    cout << "Ingrese el nombre del estudiante: ";
    cin >> estudiante->nombre;
    cout << "Ingrese el apellido del estudiante: ";
    cin >> estudiante->apellido;
    cout << "Ingrese las notas del estudiante (nota1 nota2 nota3 nota4): ";
    for (int i = 0; i < 4; ++i) {
        cin >> *(estudiante->notas + i);
    }
    // Calcular promedio
    estudiante->promedio = (estudiante->notas[0] + estudiante->notas[1] + estudiante->notas[2] + estudiante->notas[3]) / 4.0;
    // Determinar estado
    estudiante->aprobado = (estudiante->promedio > 60);
}

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    // arreglo de estudiante 
    Estudiante* estudiantes = new Estudiante[n];

    // Ingresar datos y calcular promedio y estado para cada estudiante
    for (int i = 0; i < n; ++i) {
        cout << "Ingrese los datos para el estudiante " << i+1 << ":" << endl;
        ingresarEstudiante(&estudiantes[i]);
    }

    // Para mostrar el resumen de los resultados
    cout << "\nResultados:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Estudiante " << i+1 << ":" << endl;
        cout << "ID: " << estudiantes[i].id << endl;
        cout << "Nombre: " << estudiantes[i].nombre << " " << estudiantes[i].apellido << endl;
        cout << "Promedio: " << estudiantes[i].promedio << endl;
        if (estudiantes[i].aprobado) {
            cout << "Estado: Aprobado" << endl;
        } else {
            cout << "Estado: Reprobado" << endl;
        }
        cout << endl;
    }

    delete[] estudiantes;

    return 0;
}


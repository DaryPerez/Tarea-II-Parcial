#include <iostream>
#include <string>

using namespace std;

// Struct para almacenar y guardar los datos de cada estudiante
struct Estudiante {
    int id;
    string nombre;
    string apellido;
    float notas[4];
    float promedio;
    bool aprobado;
};

// primera funcion para calcular el promedio 
void calcularPromedioYEstado(Estudiante& estudiante) {
    float suma = 0;
    for (int i = 0; i < 4; ++i) {
        suma += estudiante.notas[i];
    }
    estudiante.promedio = suma / 4.0;
    estudiante.aprobado = (estudiante.promedio > 60);
}

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    // Arreglo para almacenar los datos 
    Estudiante estudiantes[n];

    // Ingreso de datos y cálculo de promedio y estado para cada estudiante
    for (int i = 0; i < n; ++i) {
        cout << "Ingrese el ID del estudiante: ";
        cin >> estudiantes[i].id;
        cout << "Ingrese el nombre del estudiante: ";
        cin >> estudiantes[i].nombre;
        cout << "Ingrese el apellido del estudiante: ";
        cin >> estudiantes[i].apellido;
        cout << "Ingrese las notas del estudiante separando por espacios (nota1 nota2 nota3 nota4): ";
        for (int j = 0; j < 4; ++j) {
            cin >> estudiantes[i].notas[j];
        }
        calcularPromedioYEstado(estudiantes[i]);
    }

    // Mostrar resultados
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

    return 0;
}


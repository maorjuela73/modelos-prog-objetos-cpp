#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    // Constructor por defecto
    Persona() : nombre("Desconocido"), edad(0) {
        cout << "Constructor por defecto llamado." << endl;
    }

    // Constructor parametrizado
    Persona(const string& nombre, int edad) : nombre(nombre), edad(edad) {
        cout << "Constructor parametrizado llamado." << endl;
    }

    // Método para mostrar los datos
    void mostrarDatos() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }
};

int main() {
    Persona p1;                      // Llama al constructor por defecto
    Persona p2("Carlos", 25);        // Llama al constructor parametrizado

    p1.mostrarDatos();
    p2.mostrarDatos();

    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

class Archivo {
private:
    fstream archivo;

public:
    // Constructor que abre un archivo
    Archivo(const string& nombre) {
        archivo.open(nombre, ios::out);
        if (archivo.is_open()) {
            cout << "Archivo abierto: " << nombre << endl;
        } else {
            cout << "Error al abrir el archivo: " << nombre << endl;
        }
    }

    // Destructor que cierra el archivo
    ~Archivo() {
        if (archivo.is_open()) {
            archivo.close();
            cout << "Archivo cerrado." << endl;
        }
    }

    // Método para escribir en el archivo
    void escribir(const string& texto) {
        if (archivo.is_open()) {
            archivo << texto << endl;
        }
    }
};

int main() {
    {
        Archivo archivo("mi_archivo.txt");
        archivo.escribir("Este es un ejemplo de destructor.");
    } // El destructor se llama automáticamente aquí, cuando el objeto sale del alcance

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

struct Direccion {
    string calle;
    string ciudad;
    string pais;
    int codigo_postal;
};

int main() {
    Direccion direccion1 = {"Av. Principal", "Bogotá", "Colombia", 110111};

    cout << "Calle: " << direccion1.calle << endl;
    cout << "Ciudad: " << direccion1.ciudad << endl;
    cout << "País: " << direccion1.pais << endl;
    cout << "Código Postal: " << direccion1.codigo_postal << endl;

    return 0;
}

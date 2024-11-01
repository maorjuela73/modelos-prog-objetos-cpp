#include <iostream>
using namespace std;

struct Punto {
    int x;  // Coordenada x
    int y;  // Coordenada y

    void mostrar() const {
        cout << "Punto(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Punto p1;
    p1.x = 5;
    p1.y = 10;

    p1.mostrar();  // Muestra: Punto(5, 10)

    return 0;
}

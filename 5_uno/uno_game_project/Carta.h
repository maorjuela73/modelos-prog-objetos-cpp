#ifndef CARTA_H
#define CARTA_H

#include <string>

class Carta {
public:
    enum Color { ROJO, VERDE, AZUL, AMARILLO };
    
    Carta();
    Carta(Color color, int numero);
    Color obtenerColor() const;
    int obtenerNumero() const;
    std::string toString() const;

private:
    Color color;
    int numero; // número del 0 al 9
};

#endif
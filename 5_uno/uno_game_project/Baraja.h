#ifndef BARAJA_H
#define BARAJA_H

#include "Carta.h"
#include <vector>

class Baraja {
public:
    Baraja();
    void barajar();
    Carta robarCarta();
    bool estaVacia() const;

private:
    std::vector<Carta> cartas;
};

#endif
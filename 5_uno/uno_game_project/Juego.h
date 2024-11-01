#ifndef JUEGO_H
#define JUEGO_H

#include "Baraja.h"
#include "Jugador.h"

class Juego {
public:
    Juego();
    void iniciar();

private:
    Baraja baraja;
    Carta cartaSuperior;
    Jugador jugador1;
    Jugador jugador2;

    void turnoJugador(Jugador& jugadorActual);
};

#endif
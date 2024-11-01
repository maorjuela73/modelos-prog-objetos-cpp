#include "Juego.h"
#include <iostream>

Juego::Juego() : jugador1("Jugador 1"), jugador2("Jugador 2") {}

void Juego::iniciar() {
    baraja.barajar();

    // Repartir 7 cartas a cada jugador
    for (int i = 0; i < 7; ++i) {
        jugador1.recibirCarta(baraja.robarCarta());
        jugador2.recibirCarta(baraja.robarCarta());
    }

    // Sacar carta inicial
    cartaSuperior = baraja.robarCarta();
    std::cout << "Carta inicial: " << cartaSuperior.toString() << std::endl;

    // Comenzar el juego
    while (true) {
        turnoJugador(jugador1);
        if (!jugador1.tieneCartas()) {
            std::cout << jugador1.obtenerNombre() << " gana el juego!" << std::endl;
            break;
        }

        turnoJugador(jugador2);
        if (!jugador2.tieneCartas()) {
            std::cout << jugador2.obtenerNombre() << " gana el juego!" << std::endl;
            break;
        }
    }
}

void Juego::turnoJugador(Jugador& jugadorActual) {
    std::cout << "\nTurno de " << jugadorActual.obtenerNombre() << std::endl;
    std::cout << "Carta superior: " << cartaSuperior.toString() << std::endl;
    jugadorActual.mostrarMano();

    Carta cartaJugada;

    if (jugadorActual.jugarCarta(cartaSuperior, cartaJugada)) {
        cartaSuperior = cartaJugada;
        std::cout << jugadorActual.obtenerNombre() << " juega " << cartaJugada.toString() << std::endl;
    } else {
        if (!baraja.estaVacia()) {
            Carta cartaRobada = baraja.robarCarta();
            jugadorActual.recibirCarta(cartaRobada);
            std::cout << jugadorActual.obtenerNombre() << " no puede jugar y roba una carta.";
        } else {
            std::cout << "La baraja está vacía. " << jugadorActual.obtenerNombre() << " pasa el turno." << std::endl;
        }
    }
}
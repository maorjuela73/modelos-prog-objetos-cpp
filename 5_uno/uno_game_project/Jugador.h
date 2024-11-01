#ifndef JUGADOR_H
#define JUGADOR_H

#include "Carta.h"
#include <vector>
#include <string>

class Jugador {
public:
    Jugador(const std::string& nombre);
    void recibirCarta(const Carta& carta);
    bool jugarCarta(const Carta& cartaSuperior, Carta& cartaJugada);
    bool tieneCartas() const;
    std::string obtenerNombre() const;
    void mostrarMano() const;

private:
    std::string nombre;
    std::vector<Carta> mano;
};

#endif
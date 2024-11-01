#include "Jugador.h"
#include <iostream>

Jugador::Jugador(const std::string& nombre) : nombre(nombre) {}

void Jugador::recibirCarta(const Carta& carta) {
    mano.push_back(carta);
}

bool Jugador::jugarCarta(const Carta& cartaSuperior, Carta& cartaJugada) {
    for (auto it = mano.begin(); it != mano.end(); ++it) {
        if (it->obtenerColor() == cartaSuperior.obtenerColor() ||
            it->obtenerNumero() == cartaSuperior.obtenerNumero()) {
            cartaJugada = *it;
            mano.erase(it);
            return true;
        }
    }
    return false;
}

bool Jugador::tieneCartas() const {
    return !mano.empty();
}

std::string Jugador::obtenerNombre() const {
    return nombre;
}

void Jugador::mostrarMano() const {
    std::cout << "Mano de " << nombre << ": ";
    for (const auto& carta : mano) {
        std::cout << carta.toString() << " | ";
    }
    std::cout << std::endl;
}
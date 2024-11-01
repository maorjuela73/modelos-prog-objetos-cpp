#include "Baraja.h"
#include <algorithm>
#include <random>
#include <ctime>

Baraja::Baraja() {
    for (int color = Carta::ROJO; color <= Carta::AMARILLO; ++color) {
        for (int numero = 0; numero <= 9; ++numero) {
            cartas.push_back(Carta(static_cast<Carta::Color>(color), numero));
        }
    }
}

void Baraja::barajar() {
    std::random_device rd; // Generador de dispositivo aleatorio
    std::mt19937 g(rd());  // Generador Mersenne Twister inicializado con el dispositivo aleatorio
    std::shuffle(cartas.begin(), cartas.end(), g); // Usa std::shuffle en lugar de std::random_shuffle
}

Carta Baraja::robarCarta() {
    Carta carta = cartas.back();
    cartas.pop_back();
    return carta;
}

bool Baraja::estaVacia() const {
    return cartas.empty();
}

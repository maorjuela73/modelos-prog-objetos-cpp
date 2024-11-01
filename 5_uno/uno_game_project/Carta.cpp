#include "Carta.h"

Carta::Carta() : color(ROJO), numero(0) {}

Carta::Carta(Color color, int numero) : color(color), numero(numero) {}

Carta::Color Carta::obtenerColor() const {
    return color;
}

int Carta::obtenerNumero() const {
    return numero;
}

std::string Carta::toString() const {
    std::string colores[] = { "Rojo", "Verde", "Azul", "Amarillo" };
    return colores[color] + " " + std::to_string(numero);
}
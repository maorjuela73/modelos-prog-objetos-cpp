#include "Coche.h"
#include <iostream>

void Coche::LlenarCombustible(float cantidad) {
    combustible = cantidad;
}

void Coche::Acelerar() {
        velocidad ++; // Aumenta la velocidad
        combustible -= 5; // Reduce el combustible
}

void Coche::Frenar() {
    velocidad = 0; // Frena el coche
}

void Coche::SubirPasajeros(int cantidad) {
    pasajeros = cantidad;
}

void Coche::MostrarDatos() {
    std::cout << "Combustible: " << combustible << " litros" << std::endl;
    std::cout << "Velocidad: " << velocidad << " km/h" << std::endl;
    std::cout << "Pasajeros: " << pasajeros << std::endl;
}

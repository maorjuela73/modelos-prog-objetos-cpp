#pragma once
class Coche {
private:
    float combustible;
    float velocidad;
    int pasajeros;
public:
    void LlenarCombustible(float cantidad);
    void Acelerar();
    void Frenar();
    void SubirPasajeros(int cantidad);
    void MostrarDatos();
};

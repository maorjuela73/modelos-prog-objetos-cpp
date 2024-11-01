## Diseño de un Juego Simplificado de Cartas Uno en C++ Usando Programación Orientada a Objetos

El objetivo de este ejercicio es implementar un juego simplificado de cartas Uno utilizando los principios de programación orientada a objetos en C++. Este juego será para dos jugadores y seguirá reglas básicas del Uno.

---

### Descripción del Juego

- **Jugadores**: 2
- **Cartas**: Números del 0 al 9 en cuatro colores: rojo, verde, azul y amarillo.
- **Reglas**:
  - Cada jugador comienza con 7 cartas.
  - Se coloca una carta inicial en la pila de descarte.
  - Los jugadores se turnan para jugar una carta que coincida en color o número con la carta superior de la pila de descarte.
  - Si un jugador no puede jugar, roba una carta del mazo.
  - El primer jugador en quedarse sin cartas gana el juego.

---

### Clases Principales

1. **`Carta`**: Representa una carta del juego con atributos como color y número.
2. **`Baraja`**: Contiene un conjunto de cartas y métodos para barajar y repartir.
3. **`Jugador`**: Representa a un jugador con un nombre y una mano de cartas.
4. **`Juego`**: Controla el flujo del juego, mantiene la pila de descarte y el mazo de robo.

---

### Código Fuente

#### 1. Clase `Carta`

**Archivo:** `Carta.h`

```cpp
#ifndef CARTA_H
#define CARTA_H

#include <string>

class Carta {
public:
    enum Color { ROJO, VERDE, AZUL, AMARILLO };

    Carta(Color color, int numero);
    Color obtenerColor() const;
    int obtenerNumero() const;
    std::string toString() const;

private:
    Color color;
    int numero; // número del 0 al 9
};

#endif
```

**Archivo:** `Carta.cpp`

```cpp
#include "Carta.h"

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
```

#### 2. Clase `Baraja`

**Archivo:** `Baraja.h`

```cpp
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
```

**Archivo:** `Baraja.cpp`

```cpp
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
    std::srand(unsigned(std::time(0)));
    std::random_shuffle(cartas.begin(), cartas.end());
}

Carta Baraja::robarCarta() {
    Carta carta = cartas.back();
    cartas.pop_back();
    return carta;
}

bool Baraja::estaVacia() const {
    return cartas.empty();
}
```

#### 3. Clase `Jugador`

**Archivo:** `Jugador.h`

```cpp
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
```

**Archivo:** `Jugador.cpp`

```cpp
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
    std::cout << "Mano de " << nombre << ":\n";
    for (const auto& carta : mano) {
        std::cout << carta.toString() << "\n";
    }
}
```

#### 4. Clase `Juego`

**Archivo:** `Juego.h`

```cpp
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
```

**Archivo:** `Juego.cpp`

```cpp
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
    std::cout << "Carta inicial: " << cartaSuperior.toString() << "\n";

    // Comenzar el juego
    while (true) {
        turnoJugador(jugador1);
        if (!jugador1.tieneCartas()) {
            std::cout << jugador1.obtenerNombre() << " gana el juego!\n";
            break;
        }

        turnoJugador(jugador2);
        if (!jugador2.tieneCartas()) {
            std::cout << jugador2.obtenerNombre() << " gana el juego!\n";
            break;
        }
    }
}

void Juego::turnoJugador(Jugador& jugadorActual) {
    std::cout << "\nTurno de " << jugadorActual.obtenerNombre() << "\n";
    std::cout << "Carta superior: " << cartaSuperior.toString() << "\n";
    jugadorActual.mostrarMano();

    Carta cartaJugada;
    if (jugadorActual.jugarCarta(cartaSuperior, cartaJugada)) {
        cartaSuperior = cartaJugada;
        std::cout << jugadorActual.obtenerNombre() << " juega " << cartaJugada.toString() << "\n";
    } else {
        if (!baraja.estaVacia()) {
            Carta cartaRobada = baraja.robarCarta();
            jugadorActual.recibirCarta(cartaRobada);
            std::cout << jugadorActual.obtenerNombre() << " no puede jugar y roba una carta.\n";
        } else {
            std::cout << "La baraja está vacía. " << jugadorActual.obtenerNombre() << " pasa el turno.\n";
        }
    }
}
```

#### 5. Función Principal

**Archivo:** `main.cpp`

```cpp
#include "Juego.h"

int main() {
    Juego juego;
    juego.iniciar();
    return 0;
}
```

---

### Explicación del Código

- **`Carta`**: Esta clase representa cada carta del juego, con un color y un número. Incluye métodos para obtener el color y el número, y una función `toString` para representar la carta como una cadena.

- **`Baraja`**: Esta clase maneja el conjunto de cartas. Al inicializarse, crea todas las cartas posibles y proporciona métodos para barajar (`barajar`), robar una carta (`robarCarta`) y verificar si la baraja está vacía (`estaVacia`).

- **`Jugador`**: Representa a cada jugador en el juego. Cada jugador tiene un nombre y una mano de cartas. Puede recibir cartas (`recibirCarta`), intentar jugar una carta (`jugarCarta`), mostrar su mano (`mostrarMano`) y verificar si aún tiene cartas (`tieneCartas`).

- **`Juego`**: Controla el flujo del juego. Inicializa la baraja y reparte las cartas a los jugadores. Controla los turnos y determina cuándo termina el juego.

---

### Cómo Ejecutar el Programa

1. Compila el programa usando el siguiente comando:

   ```bash
   g++ main.cpp Carta.cpp Baraja.cpp Jugador.cpp Juego.cpp -o uno
   ```

2. Ejecuta el programa compilado:

   ```bash
   ./uno
   ```

---

**Ejercicio Propuesto:**

- Extiende el juego para incluir más jugadores.
- Implementa cartas especiales como "Reversa", "Salta" y "Toma dos".
- Mejora la interacción con el usuario permitiendo ingresar nombres de jugadores y elegir cartas a jugar manualmente.

Este ejercicio es ideal para practicar los conceptos de clases, objetos, encapsulamiento y control de flujo en C++. ¡Disfruta programando y mejorando el juego!
# Programación Orientada a Objetos en C++

Este repositorio contiene varios ejemplos prácticos para aprender y practicar los conceptos de la Programación Orientada a Objetos (POO) en C++. Cada carpeta incluye un ejemplo diferente, con su respectivo código fuente y, en algunos casos, archivos de apoyo.

## Estructura de los ejemplos

- **1_ejemplo_coche/**
  - Implementa una clase `Coche` con atributos y métodos básicos. Incluye un archivo principal para probar la funcionalidad de la clase.
- **2_ejemplo_persona/**
  - Ejemplo de una clase `Persona` que muestra cómo definir atributos y métodos relacionados con una persona.
- **3_constructores_destructores/**
  - Demuestra el uso de constructores y destructores en C++ mediante la clase definida en `Archivo.cpp`.
- **4_estructuras/**
  - Ejemplo de uso de estructuras en C++ con archivos como `Direccion.cpp` y `Punto.cpp`.
- **5_uno/uno_game_project/**
  - Proyecto más avanzado que simula el juego de cartas UNO. Incluye clases como `Baraja`, `Carta`, `Jugador` y `Juego`, mostrando la interacción entre objetos y el diseño modular.

## Requisitos previos

Para compilar y ejecutar los ejemplos necesitas tener instalado un compilador de C++. Los más comunes son:

- **Windows:**
  - [MinGW](http://www.mingw.org/) (GCC para Windows)
  - [Visual Studio Community](https://visualstudio.microsoft.com/es/vs/community/) (incluye MSVC)
- **macOS:**
  - [Xcode Command Line Tools](https://developer.apple.com/xcode/) (incluye `g++`)
    - Instalar con: `xcode-select --install`
- **Linux:**
  - GCC (instalar con: `sudo apt install build-essential` en Debian/Ubuntu)

## Cómo compilar y ejecutar los ejemplos

1. Abre una terminal o consola de comandos.
2. Navega a la carpeta del ejemplo que deseas compilar, por ejemplo:
   - `cd 1_ejemplo_coche`
3. Compila el archivo principal usando el compilador de C++:
   - **GCC/MinGW/g++:**
     - `g++ main.cpp Coche.cpp -o coche`
   - **MSVC (Windows):**
     - `cl main.cpp Coche.cpp`
4. Ejecuta el programa compilado:
   - **Windows:**
     - `coche.exe`
   - **macOS/Linux:**
     - `./coche`

Repite el proceso para cada ejemplo, cambiando los nombres de los archivos según corresponda.

## Notas adicionales
- Algunos ejemplos pueden requerir compilar varios archivos fuente juntos.
- Si tienes dudas sobre cómo compilar un ejemplo específico, revisa los nombres de los archivos `.cpp` y `.h` en la carpeta correspondiente.
- Puedes usar cualquier editor de texto o IDE compatible con C++ (Visual Studio Code, CLion, Code::Blocks, etc.).

## Contribuciones
Si deseas contribuir con más ejemplos o mejoras, siéntete libre de hacer un fork del repositorio y enviar un pull request. Apreciamos cualquier aporte que ayude a mejorar la calidad del contenido.

---
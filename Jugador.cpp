#include "Jugador.h"
#include "iostream"

Jugador::Jugador() {
    nombre = "";
    puntaje = 2;
}

void Jugador::definirNombre() {
    std::cout << "Ingrese el nombre del Jugador: ", std::getline(std::cin, nombre);
}

std::string Jugador::getNombre() {
    return nombre;
}

void Jugador::incrementarPuntaje() {
    puntaje += 1;
}

void Jugador::imprimirPuntajeFinal() {
    std::string final = "Partida Terminada!";
    std::string mensaje = "Jugador: " + nombre + ", Puntaje final: " + std::to_string(puntaje); + ".";

    std::cout << std::endl;
    imprimirMensaje(final);
    imprimirMensaje(mensaje);
}

void Jugador::imprimirMensaje(std::string mensaje) {
    std::cout << mensaje << std::endl;
}
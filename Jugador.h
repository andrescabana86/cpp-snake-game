#ifndef Included_Jugador_H
#define Included_Jugador_H

#include "iostream"

class Jugador {
private:
    int puntaje;
    std::string nombre;
    void imprimirMensaje(std::string);
public:
    Jugador();
    void definirNombre();
    std::string getNombre();
    void incrementarPuntaje();
    void imprimirPuntajeFinal();
};

#endif
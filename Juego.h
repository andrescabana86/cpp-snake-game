#ifndef Included_Juego_H
#define Included_Juego_H

#include "iostream"
#include "Coordenada.h"
#include "Jugador.h"
#include "Serpiente.h"

class Juego {
private:
    char** tablero;
    int n_tablero_con_bordes;
    bool sigue_jugando;
    static const char MANZANA;
    static const char PARED_TABLERO;
    Jugador jugador;
    Coordenada manzana;
    Serpiente serpiente;
    void iniciarJuego(int);
    void crearManzana();
    void actualizarTablero();
    void imprimirTablero();
    char capturarMovimiento();
    bool chocaConManzana(int, int);
    bool chocaConTablero(int, int);
    void moverSerpiente(char);
    void imprimirMensaje(std::string);
    void terminarJuego();
public:
    Juego();
    void imprimirPresentacion();
    void limpiarPrompt();
    void siguientePaso();
    bool sigueJugando();
    void imprimirResultado();
};

#endif
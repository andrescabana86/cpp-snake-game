#include <iostream>
#include "Juego.h"
#include "Serpiente.h"

const char Juego::MANZANA = '\262';
const char Juego::PARED_TABLERO = '#';

Juego::Juego() {
    iniciarJuego(10);
}

void Juego::iniciarJuego(int tam_tablero) {
    jugador.definirNombre();

    sigue_jugando = true;
    n_tablero_con_bordes = tam_tablero + 2; // suma 1 para los bordes del tablero
    serpiente = Serpiente(n_tablero_con_bordes);

    // puntero 2-D de caracteres
    tablero = new char*[n_tablero_con_bordes];
    for(int i=0; i<n_tablero_con_bordes; i++) {
        tablero[i] = new char[n_tablero_con_bordes];
    }

    crearManzana();
}

void Juego::crearManzana() {
    int rand_max = n_tablero_con_bordes - 2;
    int rand_min = n_tablero_con_bordes - rand_max;

    int x, y;
    do {
        x = Coordenada::random(rand_min, rand_max);
        y = Coordenada::random(rand_min, rand_max);
    } while (serpiente.revisarPosicion(x, y) > -1);

    manzana.setXY(x, y);
}

void Juego::imprimirPresentacion() {
    std::string bienvenida = "Bienvenido " + jugador.getNombre() + ", es hora de jugar a la viborita!";
    int tam_bienvenida = bienvenida.length();

    imprimirMensaje("");
    imprimirMensaje(std::string(tam_bienvenida, PARED_TABLERO));
    imprimirMensaje(bienvenida);
    imprimirMensaje(std::string(tam_bienvenida, PARED_TABLERO));
    imprimirMensaje("");
}

void Juego::actualizar() {
    actualizarTablero();
    imprimirTablero();
}

void Juego::actualizarTablero() {
    /*
     * ################
     * ################
     * #######?########
     * #######0#####?##
     * #######0########
     */
    for(int f=0; f<n_tablero_con_bordes; f++) {
        for (int c=0; c<n_tablero_con_bordes; c++) {
            int parte_serpiente = serpiente.revisarPosicion(f, c);
            if (parte_serpiente > -1) {
                if (parte_serpiente == 0) {
                    tablero[f][c] = Serpiente::CABEZA_SERPIENTE;
                } else {
                    tablero[f][c] = Serpiente::CUERPO_SERPIENTE;
                }
            } else if (f == manzana.getX() && c == manzana.getY()) {
                tablero[f][c] = MANZANA;
            } else {
                tablero[f][c] = PARED_TABLERO;
            }
        }
    }
}

void Juego::imprimirTablero() {
    for(int f=0; f<n_tablero_con_bordes; f++) {
        for (int c=0; c<n_tablero_con_bordes; c++) {
            if (f > 0 && c > 0 && f < (n_tablero_con_bordes-1) && c < (n_tablero_con_bordes-1)) {
                if (tablero[f][c] != PARED_TABLERO) {
                    std::cout << "  " << tablero[f][c]; // serpiente o manzana
                } else {
                    std::cout << "   "; // # => reemplaza por tres espacios
                }
                continue; // continuar el ciclo desde aqui
            }
            std::cout << "  " << tablero[f][c];
        }
        std::cout << std::endl;
    }
}

void Juego::limpiarPrompt() {
    int n;
    for (n = 0; n < 10; n++)
        printf( "\n\n\n\n\n\n\n\n\n\n" );
}

void Juego::moverSerpiente(char caracter) {
    // mover la serpiente y definir si come o no
    char direccion = toupper(caracter);
    Coordenada cabeza = serpiente.getPosicionCabeza();

    int x = cabeza.getX();
    int y = cabeza.getY();
    switch (direccion) {
        case 'A':
            y -= 1;
            break;
        case 'D':
            y += 1;
            break;
        case 'S':
            x += 1;
            break;
        case 'W':
            x -= 1;
            break;
    }


    if (serpiente.revisarPosicion(x, y) > -1) {
        limpiarPrompt();
        actualizarTablero();
        tablero[x][y] = Serpiente::CABEZA_MUERTA_SERPIENTE;
        imprimirTablero();
        terminarJuego();
        return;
    }

    serpiente.mover(x, y); // serpiente se mueve

    if (chocaConTablero(x, y)) {
        limpiarPrompt();
        actualizarTablero();
        tablero[x][y] = Serpiente::CABEZA_MUERTA_SERPIENTE;
        imprimirTablero();
        terminarJuego();
        return;
    }

    if (chocaConManzana(x, y)) {
        serpiente.comer(x, y);
        jugador.incrementarPuntaje();
        crearManzana();
    }
}

bool Juego::chocaConManzana(int x, int y) {
    if (x == manzana.getX() && y == manzana.getY()) {
        return true;
    }
    return false;
}

bool Juego::chocaConTablero(int x, int y) {
    if (x == 0 || x == (n_tablero_con_bordes-1)) {
        return true;
    }
    if (y == 0 || y == (n_tablero_con_bordes-1)) {
        return true;
    }
    return false;
}

bool Juego::sigueJugando() {
    return sigue_jugando;
}

void Juego::imprimirMensaje(std::string mensaje) {
    std::cout << mensaje << std::endl;
}

void Juego::imprimirResultado() {
    jugador.imprimirPuntajeFinal();
}

void Juego::terminarJuego() {
    sigue_jugando = false;
}
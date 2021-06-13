#include <stdlib.h>
#include "iostream"
#include "Coordenada.h"
#include "Serpiente.h"

const char Serpiente::CABEZA_SERPIENTE = '\262';
const char Serpiente::CUERPO_SERPIENTE = '0';
const char Serpiente::CABEZA_MUERTA_SERPIENTE = 'X';

Serpiente::Serpiente() {
    crearSerpiente(0);
}

Serpiente::Serpiente(int tablero) {
    crearSerpiente(tablero);
}

void Serpiente::crearSerpiente(int tablero) {
    tam_tablero = tablero - 2;
    tam_serpiente = 3;
    posicion = new Coordenada[(tam_tablero*tam_tablero)];

    int rand_max = tam_tablero - tam_serpiente;
    int rand_min = 1;

    int x = Coordenada::random(rand_min, rand_max);
    int y = Coordenada::random(rand_min, rand_max);

    for (int i=0; i<tam_serpiente; i++) {
        int yCoord = y+i;
        posicion[i].setXY(x,yCoord);
    }
}

int Serpiente::revisarPosicion(int x, int y) {
    for (int i=0; i<tam_serpiente; i++) {
        int xPos = posicion[i].getX();
        int yPos = posicion[i].getY();
        if (xPos == x && yPos == y) {
            return i;
        }
    }
    return -1;
}

Coordenada Serpiente::getPosicionCabeza() {
    return posicion[0];
}

void Serpiente::mover(int x, int y) {
    for (int i=tam_serpiente; i>0; i--) {
        posicion[i].setXY(posicion[i-1].getX(), posicion[i-1].getY());
    }
    posicion[0].setXY(x, y);
}

void Serpiente::comer(int x, int y) {
    tam_serpiente += 1;
}
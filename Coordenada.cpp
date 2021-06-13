#include <ctime>
#include <stdlib.h>
#include "Coordenada.h"

Coordenada::Coordenada() {
    x = -1;
    y = -1;
}

void Coordenada::setXY(int xCoord, int yCoord) {
    x = xCoord;
    y = yCoord;
}

int Coordenada::getX() {
    return x;
}

int Coordenada::getY() {
    return y;
}

int Coordenada::random(int min, int max) {
    static bool first = true;
    if (first) {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % (( max + 1 ) - min);
}
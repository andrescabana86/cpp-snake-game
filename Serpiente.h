#ifndef Included_Serpiente_H
#define Included_Serpiente_H

#include "Coordenada.h"
class Serpiente {
private:
    int tam_tablero;
    int tam_serpiente;
    Coordenada* posicion;
    void crearSerpiente(int);
public:
    static const char CABEZA_SERPIENTE;
    static const char CUERPO_SERPIENTE;
    static const char CABEZA_MUERTA_SERPIENTE;
    Serpiente();
    Serpiente(int);
    int revisarPosicion(int, int);
    Coordenada getPosicionCabeza();
    void mover(int, int);
    void comer(int, int);
};

#endif

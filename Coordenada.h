#ifndef Included_Coordenada_H
#define Included_Coordenada_H

class Coordenada {
private:
    int x;
    int y;
public:
    Coordenada();
    int getX();
    int getY();
    void setXY(int xCoord, int yCoord);
    static int random(int min, int max);
};

#endif


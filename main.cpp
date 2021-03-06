#include "Juego.h"

int main() {
    /**
     * 1. iniciar juego(), pedir el nombre del jugador, pedir el tamano del tablero
     * 2. hacer el tablero con el tamano
     * 3. generamos la serpiente de cuerpo 3, y su posicion inicial random
     * 4. generamos una manzana
     * 5. bucle que espera el input del usuario
        ... el usuario ingresa una letra
        ... mueve la serpiente dependiendo del input A,S,D,W a la direccion
        ... chequear que la serp no choque con la pared
        ... chequear que la serp no choque consigo misma
        ... chequear que comio manzana
     * 5. termina cuando la serpiente choca
     * 6. imprimir nombre y puntaje del usuario
     */

    Juego juego;

    do {
        juego.limpiarPrompt(); // genera espacio superior para limpiar la consola
        juego.imprimirPresentacion(); // banner
        juego.actualizar(); // paso a paso del juego

        char movimiento;
        do {
            std::cout << std::endl;
            std::cout << "Para moverse: A = izquierda, S = abajo, D = derecha, W = arriba" << std::endl;
            std::cout << "Ingrese movimiento: ", std::cin >> movimiento;
            movimiento = toupper(movimiento);
            std::cout << std::endl;
        } while((movimiento != 'A' && movimiento != 'S' && movimiento != 'D' && movimiento != 'W'));

        juego.moverSerpiente(movimiento);
    } while (juego.sigueJugando());

    juego.imprimirResultado();

    return 0;
}
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
    bool chocaConManzana(int, int);
    bool chocaConTablero(int, int);
    void imprimirMensaje(std::string);
    void terminarJuego();
public:
    Juego();
    void imprimirPresentacion();
    void limpiarPrompt();
    void actualizar();
    void moverSerpiente(char);
    bool sigueJugando();
    void imprimirResultado();
};

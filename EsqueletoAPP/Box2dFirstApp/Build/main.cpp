#include "Game.h"
#include <tchar.h>

int _tmain(int argc, _TCHAR* argv[]) {
    Game* Juego = new Game(800, 600, "Esqueleto de Aplicaci�n - MAVII");
    Juego->Loop();
    return 0;
}

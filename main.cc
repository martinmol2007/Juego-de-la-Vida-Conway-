#include <iostream>
#include <string>
#include "include/game.hh"

using namespace std;

const string SEPARADOR(63, '=');


void bienvenida_inicial() {
    cout << SEPARADOR << endl;
    cout << "Bienvendio al Juego de la Vida escrito en C++!" << endl;
    cout << "A continuacion, se iniciara el juego..." << endl;
    cout << SEPARADOR << endl;

    return;
}

int main() {
    Game juego;

    juego.inicializar_tablero();

    cout << "Juego inicializado" << endl;

    juego.imprimir_tablero();


    return 0;
}
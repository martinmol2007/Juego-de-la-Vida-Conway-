#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "include/game.hh"

using namespace std;

// NUMERO DE ITERACIONES QUE DEL JUEGO
const int ITERACIONES = 250;

const string SEPARADOR(63, '=');

void bienvenida_inicial() {
    cout << SEPARADOR << endl;
    cout << "Bienvendio al Juego de la Vida escrito en C++!" << endl;
    cout << "A continuacion, se iniciara el juego..." << endl;
    cout << SEPARADOR << endl;

    return;
}

int main() {
    // Crea el objeto juego
    Game juego;

    // Inicializa el tablero
    juego.inicializar_tablero();


    for(int i = 0; i < ITERACIONES; i++) {
        // Hace scroll hacia arriba (para que se vea como animacion)
        cout << "\033[2J\033[H";  

        // Imprime el tablero
        juego.imprimir_tablero();

        // Tiempo entre actualizacion de tablero
        this_thread::sleep_for(chrono::milliseconds(150));
        
        // Actualiza el tablero
        juego.actualizar_tablero();    
    }

    return 0;
}
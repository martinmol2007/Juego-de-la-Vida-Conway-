#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "include/game.hh"

using namespace std;

const string SEPARADOR(63, '=');
const int ITERACIONES = 250;

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

    
   
    

    for(int i = 0; i < ITERACIONES; i++) {
        cout << "\033[2J\033[H";  

        juego.imprimir_tablero();
        cout << endl;

        this_thread::sleep_for(chrono::milliseconds(150));
        
        juego.actualizar_tablero();    
    }

    return 0;
}
#include "../include/game.hh"

using namespace std;

Game::Game() {
    frame_count_ = 0;

    
    // Falta verificar los errores del usuario (numero negativo, letras,...)
    cout << "Cuantas filas quieres que tenga el tablero: ";
    cin >> FILAS;
    cout << "Cuantas columnas quieres que tenga el tablero: ";
    cin >> COLUMNAS;

    tablero_ = Matriz (FILAS, vector<bool>(COLUMNAS, false));
}

void Game::imprimir_tablero() const {
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            if(tablero_[i][j]) {
                cout << "X";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;

    return;
}

void Game::inicializar_tablero() {
    int VECES;
    cout << "Introduce el numero de celdas viva con el que quieres iniciar: ";
    cin >> VECES;

    for(int i = 0; i < VECES; i++) {
        
    }
}
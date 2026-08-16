#include "../include/game.hh"

using namespace std;

Game::Game() {
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

    return;
}

void Game::inicializar_tablero() {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dis_filas(0, FILAS-1);
    uniform_int_distribution<> dis_columnas(0, COLUMNAS-1);


    int VECES;
    cout << "Introduce el numero de celdas viva con el que quieres iniciar: ";
    cin >> VECES;


    for(int i = 0; i < VECES; i++) {
        int ran_fila = dis_filas(gen);
        int ran_columna = dis_columnas(gen);

        if(not tablero_[ran_fila][ran_columna]) {
            tablero_[ran_fila][ran_columna] = true;
        }
    }

    return;
}

int Game::contar_vecnios_vivos_interior(const Matriz& m, int i, int j) const {
    int cont = 0;
    if(m[i+1][j]) cont++;
    if(m[i+1][j+1]) cont++;
    if(m[i-1][j]) cont++;
    if(m[i-1][j-1]) cont++;
    if(m[i][j-1]) cont++;
    if(m[i][j+1]) cont++;
    if(m[i-1][j+1]) cont++;
    if(m[i+1][j-1]) cont++;

    return cont;
}

void Game::actualizar_tablero() {
    Matriz copia_ = tablero_;
    /*
    Normas:
    - Si está FALSE y tiene 3 vecinos TRUE → nace
    - Si está TRUE y tiene MÁS de 3 vecinos TRUE, o tiene 1 TRUE O MENOS → muere
    - Si está TRUE, vive si tiene 2 o 3 vecinos TRUE
    */

    for(int i = 1; i < FILAS-1; i++) {
        for(int j = 1; j < COLUMNAS-1; j++) {
            int cont = contar_vecnios_vivos_interior(tablero_, i, j);
            if(tablero_[i][j]) {
                if(cont > 3 or cont <= 1) copia_[i][j] = false;
                else copia_[i][j] = true;
            } else {
                if(cont == 3) copia_[i][j] = true;
            }
        }
    }


    tablero_ = copia_;
}
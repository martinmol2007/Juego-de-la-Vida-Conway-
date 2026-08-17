#include "../include/game.hh"

using namespace std;

Game::Game() {
    cout << "Cuantas filas quieres que tenga el tablero: ";

    int numero_filas;
    bool filas_ok = false;

    while(not filas_ok) {
        cin >> numero_filas;
        if(numero_filas >= 4) {
            FILAS = numero_filas;
            filas_ok = true;
        } else {
            cout << "Error, introduce el numero de filas que quieres: ";
        }
    }

    cout << "Cuantas columnas quieres que tenga el tablero: ";

    int numero_columnas;
    bool columnas_ok = false;

    while(not columnas_ok) {
        cin >> numero_columnas;
        if(numero_columnas >= 4) {
            COLUMNAS = numero_columnas;
            columnas_ok = true;
        } else {
            cout << "Error, introduce el numero de columnas que quieres: ";
        }
    }

    tablero_ = Matriz (FILAS, vector<bool>(COLUMNAS, false));
}

void Game::imprimir_tablero() const {
    // Si la celula esta viva, imprime X, si esta muerta, un espeacio
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
    // Generar un numero random dentro de los parametros de las FILAS y COLUMNAS
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dis_filas(0, FILAS-1);
    uniform_int_distribution<> dis_columnas(0, COLUMNAS-1);

    // Celdas vivas con las que quieers iniciar (puede que se repitan y haya menos de las puestas), ya que
    // se genera completamente aleatoriamente.
    int VECES;
    cout << "Introduce el numero de celdas viva con el que quieres iniciar: ";
    cin >> VECES;

    // Rellena el tablero
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
    // Cuanta los vecinos vivos (de las celdas centrales) 
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
    
    // Actualiza las celulas centrales
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

    // Actualiza todo el tablero
    tablero_ = copia_;
}
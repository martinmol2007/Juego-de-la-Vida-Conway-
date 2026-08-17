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
    // Si la célula está viva, imprime X, si está muerta, un espacio
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
    // Generar un número random dentro de los parámetros de las FILAS y COLUMNAS
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dis_filas(0, FILAS-1);
    uniform_int_distribution<> dis_columnas(0, COLUMNAS-1);

    // Celdas vivas con las que quieres iniciar (puede que se repitan y haya menos de las puestas), ya que
    // se genera completamente aleatoriamente.
    int VECES;
    cout << "Introduce el número de celdas vivas con el que quieres iniciar: ";
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

int Game::contar_vecinos_vivos_interior(const Matriz& m, int i, int j) const {
    // Cuenta los vecinos vivos (de las celdas centrales)
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

int Game::contar_vecinos_vivos_esquinas(const Matriz& m, int i, int j) const{
    int cont = 0;
    
    if(i == 0 && j == 0) {
        // Esquina Superior Izquierda
        if(m[0][1]) cont++;
        if(m[1][0]) cont++;
        if(m[1][1]) cont++;
    }
    else if(i == 0 && j == COLUMNAS-1) {
        // Esquina Superior Derecha
        if(m[0][COLUMNAS-2]) cont++;
        if(m[1][COLUMNAS-1]) cont++;
        if(m[1][COLUMNAS-2]) cont++;
    }
    else if(i == FILAS-1 && j == 0) {
        // Esquina Inferior Izquierda
        if(m[FILAS-2][0]) cont++;
        if(m[FILAS-1][1]) cont++;
        if(m[FILAS-2][1]) cont++;
    }
    else {
        // Esquina Inferior Derecha
        if(m[FILAS-1][COLUMNAS-2]) cont++;
        if(m[FILAS-2][COLUMNAS-1]) cont++;
        if(m[FILAS-2][COLUMNAS-2]) cont++;
    }

    return cont;
}

int Game::contar_vecinos_vivos_horizontal(const Matriz& m, int i, int j, bool arriba) const {
    int cont = 0;

    int DIRECCION;
    if(arriba) DIRECCION = 1;
    else DIRECCION = -1;

    if(m[i][j+1]) cont++;
    if(m[i][j-1]) cont++;
    if(m[i+DIRECCION][j]) cont++;
    if(m[i+DIRECCION][j+1]) cont++;
    if(m[i+DIRECCION][j-1]) cont++;

    return cont;
}

int Game::contar_vecinos_vivos_vertical(const Matriz& m, int i, int j, bool izquierda) const {
    int cont = 0;

    int DIRECCION;
    if(izquierda) DIRECCION = 1;
    else DIRECCION = -1;

    if(m[i-1][j]) cont++;
    if(m[i+1][j]) cont++;
    if(m[i][j+DIRECCION]) cont++;
    if(m[i-1][j+DIRECCION]) cont++;
    if(m[i+1][j+DIRECCION]) cont++;

    return cont;
}

void Game::actualizar_tablero_esquinas(Matriz& m, int i, int j, int cont, bool viva) {
    /*
    Si está FALSE y tiene 3 vecinos TRUE → nace
    Si está TRUE y tiene MÁS de 3 vecinos TRUE, o tiene 1 TRUE O MENOS → muere
    Si está TRUE, vive si tiene 2 o 3 vecinos TRUE
    */

    if(viva) {
        if(cont > 3 or cont <= 1) m[i][j] = false;
        else m[i][j] = true;
    } else {
        if(cont == 3) m[i][j] = true;
    }

    return;
}

void Game::actualizar_tablero() {
    Matriz copia_ = tablero_;
    
    // Actualiza las celulas centrales
    for(int i = 1; i < FILAS-1; i++) {
        for(int j = 1; j < COLUMNAS-1; j++) {
            int cont = contar_vecinos_vivos_interior(tablero_, i, j);
            if(tablero_[i][j]) {
                if(cont > 3 or cont <= 1) copia_[i][j] = false;
                else copia_[i][j] = true;
            } else {
                if(cont == 3) copia_[i][j] = true;
            }
        }
    }

    // Actualizar las esquinas
    int cont_esi = contar_vecinos_vivos_esquinas(tablero_, 0, 0);
    actualizar_tablero_esquinas(copia_, 0, 0, cont_esi, tablero_[0][0]);

    int cont_esd = contar_vecinos_vivos_esquinas(tablero_, 0, COLUMNAS-1);
    actualizar_tablero_esquinas(copia_, 0, COLUMNAS-1, cont_esd, tablero_[0][COLUMNAS-1]);

    int cont_eii = contar_vecinos_vivos_esquinas(tablero_, FILAS-1, 0);
    actualizar_tablero_esquinas(copia_, FILAS-1, 0, cont_eii, tablero_[FILAS-1][0]);

    int cont_eid = contar_vecinos_vivos_esquinas(tablero_, FILAS-1, COLUMNAS-1);
    actualizar_tablero_esquinas(copia_, FILAS-1, COLUMNAS-1, cont_eid, tablero_[FILAS-1][COLUMNAS-1]);

    // Actualizar Anillo Exterior Horizontal (Sin contar Esquinas)
    for(int j = 1; j < COLUMNAS-1; j++) {
        int cont = contar_vecinos_vivos_horizontal(tablero_, 0, j, true);
        if(tablero_[0][j]) {
            if(cont > 3 or cont <= 1) copia_[0][j] = false;
            else copia_[0][j] = true;
        } else {
            if(cont == 3) copia_[0][j] = true;
        }
    }

    for(int j = 1; j < COLUMNAS-1; j++) {
        int cont = contar_vecinos_vivos_horizontal(tablero_, FILAS-1, j, false);
        if(tablero_[FILAS-1][j]) {
            if(cont > 3 or cont <= 1) copia_[FILAS-1][j] = false;
            else copia_[FILAS-1][j] = true;
        } else {
            if(cont == 3) copia_[FILAS-1][j] = true;
        }
    }

    // Actualizar Anillo Exterior Vertical (Sin contar esquinas)
    for(int i = 1; i < FILAS-1; i++) {
        int cont = contar_vecinos_vivos_vertical(tablero_, i, 0, true);
        if(tablero_[i][0]) {
            if(cont > 3 or cont <= 1) copia_[i][0] = false;
            else copia_[i][0] = true;
        } else {
            if(cont == 3) copia_[i][0] = true;
        }
    }

    for(int i = 1; i < FILAS-1; i++) {
        int cont = contar_vecinos_vivos_vertical(tablero_, i, COLUMNAS-1, false);
        if(tablero_[i][COLUMNAS-1]) {
            if(cont > 3 or cont <= 1) copia_[i][COLUMNAS-1] = false;
            else copia_[i][COLUMNAS-1] = true;
        } else {
            if(cont == 3) copia_[i][COLUMNAS-1] = true;
        }
    }

    // Actualiza todo el tablero
    tablero_ = copia_;
}
#ifndef GAME_HH
#define GAME_HH

#include <iostream>
#include <vector>
#include <random>

typedef std::vector<std::vector<bool>> Matriz;

class Game {
    private:
    Matriz tablero_;
    int frame_count_;
    int FILAS, COLUMNAS;

    public:
    Game();

    int contar_vecnios_vivos_interior(const Matriz& m, int i, int j) const;

    void inicializar_tablero();
    void actualizar_tablero();
    void imprimir_tablero() const;
};

#endif
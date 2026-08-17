#ifndef GAME_HH
#define GAME_HH

#include <iostream>
#include <vector>
#include <random>

typedef std::vector<std::vector<bool>> Matriz;

class Game {
    private:
        Matriz tablero_;
        int FILAS, COLUMNAS;

    public:
        /**
         * @brief Constructor de Game
         * 
         */
        Game();

        /**
         * @brief Cuenta los vecinos del interior
         * 
         * @param m Matriz o tablero
         * @param i Fila
         * @param j Columna
         * @return int Vecinos vivos que tiene
         */
        int contar_vecnios_vivos_interior(const Matriz& m, int i, int j) const;

        /**
         * @brief Inicializa el tablero con celdas vivas aleatoriamente
         * 
         */
        void inicializar_tablero();

        /**
         * @brief Actualiza el tablero
         * 
         */
        void actualizar_tablero();

        /**
         * @brief Imprime el tablero por pantalla
         * 
         */
        void imprimir_tablero() const;
        
};

#endif
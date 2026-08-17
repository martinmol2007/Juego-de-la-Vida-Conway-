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

        /**
         * @brief Actualiza el tablero, solo las esquinas
         * 
         * @param m Matriz a actualizar
         * @param i Fila
         * @param j Columna
         * @param cont Contador de vecinos vivos
         * @param viva Si la celula actual esta viva
         */
        void actualizar_tablero_esquinas(Matriz& m, int i, int j, int cont, bool viva);
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
         * @brief Cuenta el numero de vecinos vivos en las esquinas
         * 
         * @param m Tablero a contar
         * @param i Fila
         * @param j Columna
         * @return int Numero de vecinos vivos
         */
        int contar_vecinos_vivos_esquinas(const Matriz& m, int i, int j) const;

        int contar_vecinos_vivos_horizontal(const Matriz& m, int i, int j, bool arriba) const;

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
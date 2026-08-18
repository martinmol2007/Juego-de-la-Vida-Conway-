# Juego de la Vida

Implementación en C++ del [**Juego de la Vida de Conway**](https://es.wikipedia.org/wiki/Juego_de_la_vida), un autómata celular ideado por el matemático británico John Horton Conway en 1970. No es un juego en el sentido tradicional: es una simulación de "cero jugadores", cuya evolución está determinada únicamente por su estado inicial.

## ¿En qué consiste?

El tablero es una cuadrícula de celdas, donde cada celda puede estar **viva** o **muerta**. En cada iteración (generación), el estado de todas las celdas se actualiza a la vez según cuántos vecinos vivos tiene (de los 8 que la rodean: arriba, abajo, izquierda, derecha y las 4 diagonales).

### Normas

- Si una celda está **muerta** (`FALSE`) y tiene exactamente **3** vecinos vivos → **nace**.
- Si una celda está **viva** (`TRUE`) y tiene **más de 3** vecinos vivos, o **1 o menos** → **muere**.
- Si una celda está **viva** y tiene **2 o 3** vecinos vivos → **sigue viva**.

Estas reglas son las originales del Juego de la Vida de Conway y pueden dar lugar a patrones estables, osciladores o estructuras que se desplazan por el tablero (como el famoso [*glider*](https://es.wikipedia.org/wiki/Planeador_(aut%C3%B3mata_celular))).

## Compilación y ejecución

El proyecto usa un `Makefile`:

```bash
make        # compila el proyecto (genera main.exe)
make run    # compila (si es necesario) y ejecuta el juego
make clean  # borra el binario generado
```

## Uso

Al ejecutar el programa, se pedirá:

1. **Número de filas** del tablero (mínimo 4).
2. **Número de columnas** del tablero (mínimo 4).
3. **Número de celdas vivas** con las que se quiere iniciar el tablero (se colocan en posiciones aleatorias; si se repite una posición ya viva, cuenta como una menos de las indicadas).

> ⚠️ No introducir letras cuando se pida el número de filas o columnas.

Tras esto, el juego se ejecutará automáticamente durante 100 iteraciones, mostrando el tablero por consola (`X` = celda viva, espacio (invisible) = celda muerta) con una pequeña pausa entre generación y generación para simular una animación.

> 💡 El número de iteraciones (generaciones) se puede cambiar editando el archivo `main.cc`, al principio del todo, donde pone: `const long long ITERACIONES = 100;`

## Fuentes

- [Juego de la vida - Wikipedia (ES)](https://es.wikipedia.org/wiki/Juego_de_la_vida)
- [Conway's Game of Life - Wikipedia (EN)](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)
- [LifeWiki - ConwayLife.com](https://conwaylife.com/wiki/Conway%27s_Game_of_Life)
- [Program for Conway's Game of Life - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/program-for-conways-game-of-life/)
- [Implementing Conway's Game of Life in C++ - Medium](https://medium.com/@theyordanos/implementing-conways-game-of-life-in-c-e80f4448cd89)

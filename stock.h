#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED
#define ARCHIVO "CarteleraDos.csv"
#define MAX_TEXTO 30
#define N 9
#include "sala.h"
void leer_cartelera();
void llenarArreglo(Pelicula *peliculas);
void crearPelicula(Pelicula *peliculas);
void listarPeli(Pelicula peliculas);
void listarCartelera(Pelicula *peliculas);
void liberarMemoria(Pelicula *peliculas);
#endif 

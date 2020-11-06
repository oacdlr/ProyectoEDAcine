#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED
#define ARCHIVO "Cartelera.csv"
#define MAX_TEXTO 30
#define N 6
#include "sala.h"
void leer_cartelera();
void llenarArreglo(Pelicula *peliculas);
void crearPelicula(Pelicula *peliculas);
void listarCartelera(Pelicula peliculas);
void liberarMemoria(Pelicula *peliculas);
#endif 

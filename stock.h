#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED
#define ARCHIVO "CarteleraDos.csv"
#define ARCHIVODOS "Dulces.csv"
#define MAX_TEXTO 30
#define N 9
# define NDOS 8
#include "sala.h"

void leer_cartelera();
void llenarArreglo(Pelicula *peliculas);
void crearPelicula(Pelicula *peliculas);
void listarPeli(Pelicula peliculas);
void listarCartelera(Pelicula *peliculas);
void liberarMemoria(Pelicula *peliculas);
////////////////////////////////////////
///////////////////////////////////////
void atenter_cliente();
void crearDulce(Producto *productos);
void llenarArregloD(Producto *productos);
void listarDulces(Producto *productos);
void listarDulce(Producto productos);
//funciones de dulceria
#endif

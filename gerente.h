#ifndef GERENTE_H_INCLUDED
#define GERENTE_H_INCLUDED
#include "sala.h"
#include "stock.h"

void peliFunciones(Pelicula *peliculas,int *horario,int *sal,int *pel); 
//funciones de estadistica
void peliVendida(Pelicula *peliculas);
void dulceVendido(Producto *productos,Mostrador *mostrador);
float gananciaDulce(Mostrador mostrador);
void gananciaDulceria(Mostrador *mostrador);
#endif

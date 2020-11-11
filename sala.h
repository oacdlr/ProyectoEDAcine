#ifndef SALA_H_INCLUDED
#define SALA_H_INCLUDED
#include "estructuras.h"
//structs pelicula,cliente,sala
typedef struct{
	char *nombre;
	int ventas;
	int edadminima;
	char *genero;
	char *idioma;
}Pelicula;
typedef struct{
	Cliente *asientos[16][16];
	Pelicula *actual;
}Sala;
//funciones
void asignarPeli(Sala *sala,Pelicula *pelicula);
void limparSala(Sala *sala);
Cliente *crearcliente(Cliente in);
void llenarDatos(Cliente *in);
void imprimirSala(Sala sala);
void compraasiento(Sala *sala);
void cancelarcompra(Sala *sala);
void mostrarCine(Sala *cine);  
void eleccionSala(int *horario,int *sal);
void limpiarCine(Sala *cine);
#endif

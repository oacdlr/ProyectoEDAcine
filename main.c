#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "sala.h"
#include "stock.h"
int main(int argc, char *argv[]) {
	//prueba de edicion en git
	Pelicula cartelera[5];
	Sala prueba;
	Cliente cliprueba;
	limpiarSala(&prueba);
	cartelera[0].nombre=(char *)calloc(20,sizeof(char));
	cartelera[0].nombre="PeliPrueba";
	cliprueba.cuenta=20.5;
	llenarDatos(&cliprueba);
	printf("%d %d",cliprueba.edad,cliprueba.genero);
	prueba.actual=&(cartelera[0]);
	printf("%.2f %s\n",cliprueba.cuenta,cartelera[0].nombre);
	prueba.asientos[2][3]=crearcliente(cliprueba);
	printf("%.2f %s\n",prueba.asientos[2][3]->cuenta,prueba.actual->nombre);
	prueba.asientos[2][4]=prueba.asientos[2][3];
	printf("funciona la asignacion de un asiento y relacion con otro \n");
	prueba.asientos[2][4]->cuenta=10.3;
	printf("%.2f %s\n",prueba.asientos[2][3]->cuenta,prueba.actual->nombre);
	printf("%.2f %s\n",prueba.asientos[2][4]->cuenta,prueba.actual->nombre);
//	imprimirSala(prueba);
	compraasiento(&prueba);
	imprimirSala(prueba);
	cancelarcompra(&prueba);
	imprimirSala(prueba);
	return 0;
}

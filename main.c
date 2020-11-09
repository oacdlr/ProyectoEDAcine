#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "sala.h"
#include "stock.h"
#include "gerente.h"
#include "estructuras.h"
int main() {

  atenter_cliente();




















	/*Producto pruebaprod;
	stackProds *stackpru;
	stackpru=pilaProducto(4);
	pruebaprod.nombre="papas";
	pruebaprod.venta=20.6;
	printf("%s %.2f",pruebaprod.nombre,pruebaprod.venta);
	pushPila(pruebaprod,stackpru);
	pruebaprod.nombre="palomitas";
	pruebaprod.venta=30.6;
	printf("%s %.2f",pruebaprod.nombre,pruebaprod.venta);
	pushPila(pruebaprod,stackpru);
	Producto aux=popPila(stackpru);
	printf("%s %.2f",aux.nombre,aux.venta);
	/*
	Sala cine[3][10];
	Sala prueba;
	Sala pr[2];
	Sala pru[2][3];
	Sala *prue;
	Cliente cliprueba;
    Pelicula *peliculas;
	peliculas = (Pelicula *)calloc(N, sizeof(Pelicula));
    llenarArreglo(peliculas);
    peliFunciones(cine,peliculas);
	asignarPeli(&cine[0][0],peliculas+8);
	asignarPeli(&prueba,peliculas);
  	asignarPeli(&pr[1],peliculas+1);
	prue=&cine;
	//asignarPeli(prue+1,peliculas+8);
	asignarPeli(&pru[1][1],peliculas+2);
	limpiarSala(&prueba);
//	printf("%d %d",&cine[0][0],prue);
	cliprueba.cuenta=20.5;
	prueba.asientos[2][3]=crearcliente(cliprueba);
	printf("pelicula en el cine %s\n",cine[0][0].actual->nombre);
	printf("%.2f %s\n",prueba.asientos[2][3]->cuenta,prueba.actual->nombre);
	printf("%.2f %s\n",prueba.asientos[2][3]->cuenta,pr[1].actual->nombre);
	printf("%.2f %s\n",prueba.asientos[2][3]->cuenta,pru[1][1].actual->nombre);
	prueba.asientos[2][4]=prueba.asientos[2][3];
	printf("funciona la asignacion de un asiento y relacion con otro \n");
	prueba.asientos[2][4]->cuenta=10.3;
	printf("%.2f %s\n",prueba.asientos[2][3]->cuenta,prueba.actual->nombre);
	printf("%.2f %s\n",prueba.asientos[2][4]->cuenta,prueba.actual->nombre);
	limpiarSala(&cine[0][0]);
	limpiarSala(&cine[0][1]);
//	printf("out");
	printf("%s",cine[0][0].actual->nombre);
	//printf("%s",cine[0][1].actual->nombre);
	/*
	printf("%s\n",pru[1][1].actual->nombre);
	compraasiento(&prueba);
	imprimirSala(prueba);
	cancelarcompra(&prueba);
	imprimirSala(prueba);
	printf("%d",prueba.actual->ventas);*/

	return 0;
}

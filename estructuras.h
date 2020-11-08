#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
#include "sala.h"
#define tmax 6
typedef struct{
	Producto *bandeja;
	int tope;
	int max;
}stackProds;

stackProds *crearPila(int n);
int pilaLLena(stackProds *pila);
void pushPila(Producto dato,stackProds *pila);
void listarPila(stackProds pila);
int pilaVacia(stackProds *pila);
Producto popPila(stackProds *pila);
void inicializarPila(stackProds *pila);
void liberaMamoria(stackProds *pila);
void pruebaes(); 

#endif

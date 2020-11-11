#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
#define tmax 6
typedef struct {
	char *nombre;
	float precio;
	float venta;
	float cantidad;
}Producto;

typedef struct{
	Producto *bandeja;
	int tope;
	int max;
}stackProds;
typedef struct{
	int edad;
	int genero;
	float cuenta;//suma de bandeja precio
	stackProds *bandeja;
}Cliente;
//funciones stack
stackProds *crearPila(int n);
int pilaLLena(stackProds *pila);
void pushPila(Producto dato,stackProds *pila);
void listarPila(stackProds *pila); 
int pilaVacia(stackProds *pila);
Producto popPila(stackProds *pila);
void inicializarPila(stackProds *pila);
void liberaMamoria(stackProds *pila);
void pruebaes(); //

//funciones queue


#endif

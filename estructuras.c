#include<stdio.h>
#include<stdlib.h>
#include "estructuras.h"

stackProds *crearPila(int n){
    stackProds *nuevaPila;
    //crear la pila y el arreglo de la pila
    nuevaPila = (stackProds *)malloc(1*sizeof(stackProds)); //CREA LA ESTRUCTURA PILA CON TODOS SUS ELEMENTOS
    nuevaPila->bandeja = (Producto *)calloc(n , sizeof(Producto));//CREANDO EL ARREGLO DE LA PILA(productos)
    //INICIALIZA VALORES
    nuevaPila->tope = -1;
    nuevaPila->max = n;
}
int pilaLLena(stackProds *pila){
    return !(pila->tope < pila->max-1);
}

void pushPila(Producto dato,stackProds *pila){
    pila->tope ++;
    pila->bandeja[pila->tope]=dato;
    printf("\nProducto = %s \n",pila->bandeja[pila->tope].nombre);
}
void listarPila(stackProds *pila){
    int i;
    for (i= pila->tope; i >= 0; i--)
        printf("\nProducto[%i] = %s ", i,pila->bandeja[i].nombre);
}
int pilaVacia(stackProds *pila){
    return (pila->tope == -1);
}
Producto popPila(stackProds *pila){
    Producto aux = pila->bandeja[pila->tope];
    pila->tope --;
    return aux;
}
void inicializarPila(stackProds *pila){
    pila->tope = -1;
}
void liberaMamoriaCola(stackProds *pila){
    free(pila->bandeja);
    free(pila);
    pila = NULL;
}
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
Cola *crearCola(int max) {
    Cola *nuevaCola;
    //crear la cola y el arreglo
    nuevaCola = (Cola *)malloc(sizeof(Cola));
    nuevaCola->arrCola = (Cliente *)calloc(max,sizeof(Cliente));
    //INICIALIZAR
    nuevaCola->max = max;
    nuevaCola->h = nuevaCola->t= -1;
    return nuevaCola;
}

int validarEspacio(Cola cola){
    if ((cola.h==0 && cola.t == cola.max-1) || (cola.t+1 == cola.h)){
        printf("no hay espacio");
    return 0;
	}
    return 1;
}

void insertar(Cola *cola,Cliente dato) {
    if (cola->h ==-1)
        cola->h= 0;//INICIO DE LA FILA

       if(cola->t == cola->max-1)
       cola->t = -1;

    cola->t++;
    //INSERTA EL DATO EN LA FILA
    cola->arrCola[cola->t]=dato;
}

void listar(Cola cola){
   int i;
   printf("\nCOLA:");
   if (!validarVacio(cola)){
       if (cola.h <= cola.t){
       for (i=cola.h; i<=cola.t ; i++)
       		listarPila(cola.arrCola[i].bandeja);
			//printf(" [%i]= %i\t",i, cola.arrCola[i]);
       }
	   else {
       		for (i=cola.h; i<cola.max; i++)
       			listarPila(cola.arrCola[i].bandeja);
           //printf("[%i]= %i", i, cola.arrCola[i]);
        	for(i=0; i<=cola.t; i++)
           		listarPila(cola.arrCola[i].bandeja);
		 	//  printf(" [%i]= %i\n", i, cola.arrCola[i]);}
   		}
   }
   else
        printf("  No hay datos...");
}
int validarVacio(Cola cola){
    return cola.h == -1;
}
Cliente popCola(Cola *cola){
    Cliente aux=cola->arrCola[cola->h];
    if (cola->h == cola->t)
    cola->h = cola->t = -1;
    else if (cola->h == cola->max-1)
    cola->h = 0;
    else
    cola->h++;
    return aux;
}

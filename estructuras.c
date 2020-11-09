#include<stdio.h>
#include<stdlib.h>
#include "estructuras.h"

stackProds *pilaProducto(int n){
    stackProds *nuevaPila;
    //crear la pila y el arreglo de la pila
    nuevaPila = (stackProds *)malloc(1*sizeof(stackProds)); //CREA LA ESTRUCTURA PILA CON TODOS SUS ELEMENTOS
    nuevaPila->bandeja = (Producto *)calloc(n , sizeof(Producto));//CREANDO EL ARREGLO DE LA PILA
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
}
void listarPila(stackProds *pila){
    int i;
    for (i= pila->tope; i >= 0; i--)
        printf("\npila[%i] = %s ", i,pila->bandeja->nombre); 
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
void liberaMamoria(stackProds *pila){
    free(pila->bandeja);
    free(pila);
    pila = NULL;
}
void pruebaes(){
	printf("estructuras included");
}

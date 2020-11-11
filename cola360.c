#include <stdio.h>
#include <stdlib.h>
#include "cola360.h"

Cola *crearCola(int max) {
    Cola *nuevaCola;
    //crear la cola y el arreglo
    nuevaCola = (Cola *)malloc(sizeof(Cola));
    nuevaCola->arrCola = (int *)calloc(max,sizeof(int));
    //INICIALIZAR
    nuevaCola->max = max;
    nuevaCola->h = nuevaCola->t= -1;
    return nuevaCola;
}

int validarEspacio(Cola cola){
    if ((cola.h==0 && cola.t == cola.max-1) || (cola.t+1 == cola.h)){
        printf("no hay espacio");
    return 0;}
    return 1;
}

void insertar(Cola *cola, int dato) {
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
            printf(" [%i]= %i\t",i, cola.arrCola[i]);
       }else {
       for (i=cola.h; i<cola.max; i++)
           printf("[%i]= %i", i, cola.arrCola[i]);
           for (i=0; i<=cola.t; i++)
           printf(" [%i]= %i\n", i, cola.arrCola[i]);}
   }
   else
        printf("  No hay datos...");
}
int validarVacio(Cola cola){
    return cola.h == -1;
}
int borrar(Cola *cola){
    int aux=cola->arrCola[cola->h];
    if (cola->h == cola->t)
    cola->h = cola->t = -1;
    else if (cola->h == cola->max-1)
    cola->h = 0;
    else
    cola->h++;
    return aux;
}



#include<stdio.h>
#include<stdlib.h>
#include "sala.h"
#include "stock.h"
#include "gerente.h"
void listarPeli(Pelicula peliculas){
    printf("\n===============================\n");
    printf("Pelicula: %s\n",peliculas.nombre);
    printf("Idioma: %s\n",peliculas.idioma);
    printf("Clasificacio: %s\n",peliculas.edadminima);
    printf("Genero: %s\n",peliculas.genero);
}
void listarCartelera(Pelicula *peliculas){
	int i;
	for(i=0;i<N;i++){
		printf("Pelicula %i",i+1);
		listarPeli(peliculas[i]);
	}
}
void crearPelicula(Pelicula *peliculas){
    peliculas->nombre =(char *)malloc(MAX_TEXTO*sizeof(char));
    peliculas->genero =(char *)malloc(MAX_TEXTO*sizeof(char));
    peliculas->idioma =(char *)malloc(MAX_TEXTO*sizeof(char));
    peliculas->edadminima =(char *)malloc(MAX_TEXTO*sizeof(char));
}

void llenarArreglo(Pelicula *peliculas){
    FILE *archivodos;
    char linea[1024], delimitador[] = ",\n",delimitadordos[]="\n";
    char *token;
    int indice,dato;

    archivodos = fopen( ARCHIVO, "rt" );
    if( archivodos == NULL ){
        printf( "Error (NO ABIERTO)\n" );
        return ;
    }
    indice = -1; //INICIALIZA EL INDICE DEL ARREGLO
    while(fgets(linea,1023, archivodos) != NULL){
        token = strtok(linea, delimitador);
        indice++;
        while (token != NULL)
            {
            crearPelicula(&peliculas[indice]);
            strcpy(peliculas[indice].nombre,token);
            token = strtok(NULL, delimitador);
            strcpy(peliculas[indice].idioma,token);
            token = strtok(NULL, delimitador);
            strcpy(peliculas[indice].edadminima,token);
            token = strtok(NULL, delimitador);
            strcpy(peliculas[indice].genero,token);
            token = strtok(NULL, delimitador);
        }
    }
}
void liberarMemoria(Pelicula *peliculas)
{
    free(peliculas->nombre);
    free(peliculas->idioma);
    free(peliculas->edadminima);
    free(peliculas->genero);

}
///////////////////////////////////////////////////Parte de la dulcer?a
///////////////////////////////////////////////////


void crearDulce(Producto *productos){
    productos->nombre =(char *)malloc(MAX_TEXTO*sizeof(char));
}

void llenarArregloD(Producto *productos)
{
    FILE *archivo;
    char linea[1024], delimitador[] = ",\n",delimitadordos[]="\n";
    char *token;
    int indice,dato;

    archivo = fopen( ARCHIVODOS, "rt" );
    if( archivo == NULL ){
        printf( "Error (NO ABIERTO)\n" );
        return ;
    }
    indice = -1;
    while(fgets(linea,1023, archivo) != NULL){
        token = strtok(linea, delimitador);
        indice++;
        while (token != NULL)
            {
            crearDulce(&productos[indice]);
            strcpy(productos[indice].nombre,token);
            token = strtok(NULL, delimitador);
            productos[indice].cantidad=atoi(token);
            token = strtok(NULL, delimitador);
            productos[indice].precio=atof(token);
            productos[indice].venta=productos[indice].precio*1.5;
            token = strtok(NULL, delimitador);
        }
    }




}

void listarDulces(Producto *productos){
	int i;
	printf("\n");
	for(i=0;i<NDOS;i++){
		printf("%i",i+1);
		listarDulce(productos[i]);
	}
}
void listarDulce(Producto productos){
    printf("%s ---------------%.2f\n",productos.nombre,productos.venta);
}

void atenter_cliente(Producto *productos){
    printf("\nHola, que deseas ordenar ??\n");
    printf("\nTenemos el siguiente cat?logo de dulces\n");
    listarDulces(productos);

}
void listarCliente(Cliente cliente)
{
    printf("\nCuenta: %0.2f  Edad: %d Genero: %d",cliente.cuenta,cliente.edad,cliente.genero);
}
void iniMostrador(Mostrador *mostrador,Producto *productos){
	int i;
	for(i=0;i<8;i++){
		(mostrador+i)->exhibido=(productos+i);
		(mostrador+i)->cantidad+=10;
		(productos+i)->cantidad-=10;	
		(mostrador+i)->ventotal=0;
	}
}
void reabastece(Mostrador *mostrador,Producto *productos, int i)
{
        if((productos->cantidad)>10)
        {
             (mostrador+i)->cantidad+=10;
             (productos+i)->cantidad-=10;
        }

        else
        {
            (mostrador+i)->cantidad+=(productos+i)->cantidad;
            (productos+i)->cantidad=0;
        }

}

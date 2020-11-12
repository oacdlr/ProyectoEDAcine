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
            //1o. se crea la memoria que falta para el cliente i-esimo
            crearPelicula(&peliculas[indice]);
            //2o. se copia en los elementois del cliente el token
            strcpy(peliculas[indice].nombre,token);
            token = strtok(NULL, delimitador);
            strcpy(peliculas[indice].idioma,token);
            token = strtok(NULL, delimitador);
            strcpy(peliculas[indice].edadminima,token);
            token = strtok(NULL, delimitador);
            strcpy(peliculas[indice].genero,token);
            //3o. se lee el ?ltimo token para verificar que termino de leer la linea
            //el valor del token ser? NULL por ello termina el ciclo while
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
    indice = -1; //INICIALIZA EL INDICE DEL ARREGLO
    while(fgets(linea,1023, archivo) != NULL){
        token = strtok(linea, delimitador);
        indice++;
        while (token != NULL)
            {
            //1o. se crea la memoria que falta para el cliente i-esimo
            crearDulce(&productos[indice]);
            //2o. se copia en los elementois del cliente el token
            strcpy(productos[indice].nombre,token);
            token = strtok(NULL, delimitador);
            productos[indice].cantidad=atoi(token);
            token = strtok(NULL, delimitador);
            productos[indice].precio=atof(token);
            //3o. se lee el ?ltimo token para verificar que termino de leer la linea
            //el valor del token ser? NULL por ello termina el ciclo while
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
    printf("%s ---------------%.2f\n",productos.nombre,productos.precio);
}

void atenter_cliente(Producto *productos){
    //Parte del main
     ////
    printf("\nHola, que deseas ordenar ??\n");
    printf("\nTenemos el siguiente cat?logo de dulces\n");
    listarDulces(productos);

}
Cliente *crearclienteD()
{
    int i;
    Cliente *c_uno;
    c_uno=(Cliente *)calloc(1,sizeof(Cliente));
    c_uno->bandeja=(stackProds *)malloc(NDOS*sizeof(stackProds));
    printf("Hola, Gusta decirnos su edad y genero?\n1)Si\t 2)No");
	scanf("%d",&i);
	if(i==1){
	printf("cual es su edad? ");
	scanf("%d",&c_uno->edad);
	printf("cual es su genero?\n 1)Masculino\t2)Femenino ");
	scanf("%d",&c_uno->genero);
	c_uno->cuenta=0;
	return c_uno;
	}
}
void listarCliente(Cliente cliente)
{
    printf("\nCuenta: %0.2f  Edad: %d Genero: %d",cliente.cuenta,cliente.edad,cliente.genero);
}


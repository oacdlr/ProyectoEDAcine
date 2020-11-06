#include<stdio.h>
#include<stdlib.h>
#include "stock.h"
void listarCartelera(Pelicula peliculas){
    printf("\n===============================\n");
    printf("Pelicula: %s\n",peliculas.nombre);
    printf("Idioma: %s\n",peliculas.idioma);
    printf("Clasificacio: %s\n",peliculas.edadminima);
    printf("Genero: %s\n",peliculas.genero);
}

void crearPelicula(Pelicula *peliculas){
    peliculas->nombre =(char *)malloc(MAX_TEXTO*sizeof(char));
    peliculas->genero =(char *)malloc(MAX_TEXTO*sizeof(char));
    peliculas->idioma =(char *)malloc(MAX_TEXTO*sizeof(char));
    peliculas->edadminima =(char *)malloc(MAX_TEXTO*sizeof(char));
}

void llenarArreglo(Pelicula *peliculas){
    FILE *archivo;
    char linea[1024], delimitador[] = ",\n",delimitadordos[]="\n";
    char *token;
    int indice,dato;

    archivo = fopen( ARCHIVO, "rt" );
    if( archivo == NULL ){
        printf( "Error (NO ABIERTO)\n" );
        return ;
    }
    token = strtok(linea, delimitadordos);
    indice = -1; //INICIALIZA EL INDICE DEL ARREGLO
    while(fgets(linea,1023, archivo) != NULL){
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
            //3o. se lee el último token para verificar que termino de leer la linea
            //el valor del token será NULL por ello termina el ciclo while
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


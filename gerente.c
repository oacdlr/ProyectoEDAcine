#include<stdio.h>
#include<stdlib.h>
#include "gerente.h"
#include "menu.h"
void peliFunciones(Pelicula *peliculas,int *horario,int *sal,int *pel){
	*horario=desplegarMenu("En que horario se reproducira?\n1)matutino\t2)vespertino\t3)nocturno ",3);
	*sal=desplegarMenu("En cual de las 10 salas se reproducira la pelicula?ingrese un numero del 1 al 10 ",10);
	if(desplegarMenu("Desea ver el catalogo de peliculas?\n1)si 2)no ",2)==1){
		listarCartelera(peliculas);
	}
	*pel=desplegarMenu("Cual Pelicula se reproducira? ",9); 
}


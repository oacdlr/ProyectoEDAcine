#include<stdio.h>
#include<stdlib.h>
#include "gerente.h"

void peliFunciones(Sala *cine,Pelicula *peliculas){
	int b=1;
	int horario,sal,car;
	Sala *point;
	point=&cine;
//	printf("%d %d %d",&cine,point,cine);
	printf("Buenos dias Gerente\nQue peliculas vamos a mostrar hoy?\n");
	while(b==1){
		horario=4;
		while(horario>3 || horario<1){
			printf("Para que horario asignara la pelicula?\n1)matutino\t2)vespertino\t3)nocturno");
			scanf("%d",&horario);
			if(horario<1 || horario>3)
				printf("Escoja un horario valido\n");
		}
		sal=-1;
		while(sal<1 || sal>10 ){
			printf("En cual de nuestras 10 salas reproduciremos la pelicula?Escoga un numero del 1 al 10 \n");
			scanf("%d",&sal);
			if(horario<1 || sal>10)
				printf("Escoja una sala valida\n");
		}
		printf("Desea ver el catalogo de peliculas?\n1)si 2)no");
		scanf("%d",&car);
		if(car==1){
			listarCartelera(peliculas);
		}
		car=-1;
		while(car<1 || car>10){
		printf("cual pelicula se reproducira en la sala? ");
		scanf("%d",&car);
		}
	//	printf("%d %d %d",horario-1,sal-1,(3*(horario-1)+sal-1));
		asignarPeli(point+(3*(horario-1)+sal-1),peliculas+car-1);
		/*
		Pelicula *out;
		Sala out2=*(cine+(3*(horario-1)+sal-1));
		out=out2.actual;
		printf("//%s ",out->nombre);
		printf("//%s ",out2.actual->nombre);
		*/
		printf("Desea seguir agendando peliculas?\ningrese 1 para si");
		scanf("%d",&b);
	}
}


#include<stdio.h>
#include<stdlib.h>
#include "sala.h"
void asignarPeli(Sala *sala,Pelicula *peli){
	sala->actual=peli;
	printf("se modifico y ahora es:%s\n",(sala->actual->nombre));
}
void limpiarSala(Sala *sala){
	int i,j;
	for(i=0;i<30;i++){
		for(j=0;j<30;j++){
			sala->asientos[i][j]=NULL;
		}
	}
}
Cliente *crearcliente(Cliente in){
	Cliente *newcl;
	newcl->cuenta=in.cuenta;
	newcl->edad=in.edad;
	newcl->genero=in.genero;
	return newcl;
}
void llenarDatos(Cliente *in){
	printf("cual es su edad? ");
	scanf("%d",&in->edad);
	printf("cual es su genero?\n 1)Masculino\t2)Femenino ");
	scanf("%d",&in->genero);
	in->cuenta=0;
}
void imprimirSala(Sala sala){
	int i,j;
	printf("imprimiendo Sala.....X ocupado O disponible\n  ");
	for(i=0;i<15;i++)
		printf("%d ",i+1);
	printf("\n");
	for(i=0;i<15;i++){
		printf("%d ",i+1);
		for(j=0;j<15;j++){
			if(sala.asientos[i][j]==NULL){
				printf("O ");
			}
			else
				printf("X ");
		}
		printf("\n");
	}
	
}
void compraasiento(Sala *sala){
	int bol;
	int i,x,y,x1,y1,b=0;
	Cliente cli;
	imprimirSala(*sala);
	printf("Gusta decirnos su edad y genero?\n1)Si\t 2)No");
	scanf("%d",&i);
	if(i==1){
		llenarDatos(&cli);
	}
	//pregunta de datos edad,genero, cuenta=0;
	printf("cuantos asientos van a ser?\n");
	scanf("%d",&bol);
	while(b==0){
	printf("fila del boleto 1 ");
	scanf("%d",&x);
	printf("columna del boleto 1 ");
	scanf("%d",&y);
	if(sala->asientos[x-1][y-1]==NULL)
		b=1;
	else{
		printf("Lugar ocupado,elija otro por favor \n");
	}
	}
	sala->asientos[x-1][y-1]=crearcliente(cli);
	for(i=1;i<bol;i++){
		b=0;
		while(b==0){
		printf("fila del boleto %d ",i+1);
		scanf("%d",&x1);
		printf("columna del boleto %d ",i+1);
		scanf("%d",&y1);	
		if(sala->asientos[x1-1][y1-1]==NULL)
			b=1;
		else 
			printf("Lugar ocupado,elija otro por favor \n");
		}
		sala->asientos[x1-1][y1-1]=sala->asientos[x-1][y-1];
	}
	sala->actual->ventas+=bol;
}

void cancelarcompra(Sala *sala){
	int bol,x,y,i,b;
	printf("cuantos asientos quiere cancelar?\n");
	scanf("%d",&bol);
	for(i=0;i<bol;i++){
		b=0;
		while(b==0){
		printf("fila del boleto %d ",i+1);
		scanf("%d",&x);
		printf("columna del boleto %d ",i+1);
		scanf("%d",&y);	
		if(sala->asientos[x-1][y-1]!=NULL)
			b=1;
		else
			printf("Ese asiento esta disponible,Elija el asiento a cancelar\n");
		}
		sala->asientos[x-1][y-1]=NULL;
	}
	sala->actual->ventas-=bol;
}

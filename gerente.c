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
void peliVendida(Pelicula *peliculas){
	int i,maxV=1,maxVi;
	for(i=0;i<9;i++){
		if((peliculas+i)->ventas>=maxV){
			maxV=(peliculas+i)->ventas;
			maxVi=i;
		}
	}
	printf("La pelicula mas vendida es %s con %d boletos vendidos\n",(peliculas+maxVi)->nombre,(peliculas+maxVi)->ventas);
}
void dulceVendido(Producto *productos,Mostrador *mostrador){
	int i,maxV=0,maxVi;
	for(i=0;i<9;i++){
		if((mostrador+i)->ventotal>=maxV){
			maxV=(mostrador+i)->ventotal;
			maxVi=i;
		}
	}
	printf("El producto mas vendido es %s con %d unidades vendidas\n",(productos+maxVi)->nombre,(mostrador+maxVi)->ventotal);
}
float gananciaDulce(Mostrador mostrador){
	float  ganancia,costo,neto;
	ganancia=(mostrador.ventotal*mostrador.exhibido->venta);
	costo=(mostrador.ventotal+mostrador.exhibido->cantidad)*mostrador.exhibido->precio;
	neto=ganancia-costo;
	printf("El costo de compra total del producto %s fue %.2f,Se vendieron %d unidades generando %.2f$ teniendo una ganancia de %.2f\n",mostrador.exhibido->nombre,costo,mostrador.ventotal,ganancia,neto);
	return neto;
}
void gananciaDulceria(Mostrador *mostrador){
	int i=0;
	float ganancia=0;
	for(i=0;i<8;i++){
		ganancia+=gananciaDulce(*(mostrador+i));
	}
	printf("La ganancia total de la dulceria fue %.2f\n",ganancia);
}
int ventasSala(Sala *sala){
	int i,j,c=0;
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			if(sala->asientos[i][j]!=NULL){
				c++;
			}
		}
	}
	return c;
}
int ventasHorario(int hor,Sala *sala){
	int i,c=0;
	for(i=0;i<10;i++){
		c+=ventasSala(sala+(10*hor)+i);
	}
	return c;
}
int ventasCine(Pelicula *peliculas){
	int i,ven=0;
	for(i=0;i<9;i++)
		ven+=(peliculas+i)->ventas;
	return ven;
}
void generoVendido(Pelicula *peliculas){
	int maxx=-1,ven;
	char *genero;
	char *genmax;
	int i,j;
	genero=(char *)calloc(20,sizeof(char));
	for(i=0;i<9;i++){
		genero=(peliculas+i)->genero;
		ven=0;
		for(j=i;j<9;j++){
			if(genero==(peliculas+j)->genero){
				ven+=(peliculas+j)->ventas;
			}
		}
		if(ven>maxx){
			maxx=ven;
			genmax=genero;
		}
	}
	printf("El genero mas vendido es %s con %d ventas\n",genmax,maxx);
}
void pelimenosVen(Pelicula *peliculas){
		int i,maxV=1000000000,maxVi;
	for(i=0;i<9;i++){
		if((peliculas+i)->ventas<=maxV){
			maxV=(peliculas+i)->ventas;
			maxVi=i;
		}
	}
	printf("La pelicula menos vendida es %s con %d boletos vendidos\n",(peliculas+maxVi)->nombre,(peliculas+maxVi)->ventas);
}
void dulcemenosVen(Producto *productos,Mostrador *mostrador){
		int i,maxV=10000000,maxVi;
	for(i=0;i<9;i++){
		if((mostrador+i)->ventotal<=maxV){
			maxV=(mostrador+i)->ventotal;
			maxVi=i;
		}
	}
	printf("El producto menos vendido es %s con %d unidades vendidas\n",(productos+maxVi)->nombre,(mostrador+maxVi)->ventotal);
}

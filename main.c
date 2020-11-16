#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "ctype.h"
#include "stock.h"
#include "estructuras.h"
#include "sala.h"
#include "gerente.h"
int main() {
	int horario,sal,pel,fproducto;
	Sala cine[3][10];
	//limpieza extra
	int i,j;
	for(i=0;i<3;i++){
			for(j=0;j<10;j++){
				limpiarCine(&cine[i][j]);
			}
	}
	//
	Pelicula *peliculas;
	Mostrador *mostrador;
	mostrador=(Mostrador *)calloc(NDOS,sizeof(Mostrador));
	peliculas = (Pelicula *)calloc(N, sizeof(Pelicula));
    llenarArreglo(peliculas);
    Producto *productos;
    productos = (Producto *)calloc(NDOS, sizeof(Producto));//
    llenarArregloD(productos);
	iniMostrador(mostrador,productos);
	stackProds *pila;
    pila = crearPila(NDOS);//NDOS es el numero de productos de la bandeja
    Cola *personas;

    personas= crearCola(15);
    Cliente *uncliente;
    //printf("--%d",productos[1].cantidad);
	//menu principal
	int opprin,opsec,opter;
	do{
		opprin=desplegarMenu("\n1)Menu Gerente\t2)Menu Taquilla\t3)Menu Dulceria\t4)salir",4);
		switch(opprin){
			case 1:
				do{
					opsec=desplegarMenu("\n1)Asignar Funciones a salas\n2)Estadisticas del Cine\n3)salir",3);
					switch(opsec){
						case 1:
							printf("Buenos dias Gerente,que peliculas vamos a mostrar hoy?");
							do{
								peliFunciones(peliculas,&horario,&sal,&pel);
								asignarPeli(&cine[horario-1][sal-1],peliculas+pel-1);
								limpiarSala(&cine[horario-1][sal-1]);
							}while(desplegarMenu("Desea seguir agendando?\n1)si  2)no",2)==1);
							break;
						case 2:
							printf("Que estadistica desea ver?\n");
							opter=desplegarMenu("1)Pelicula mas vendida\n2)Dulce mas vendido\3)Pelicula menos vendida\n4)Dulce menos vendido\n5)ganancia de un dulce\n6)Ganancia total de la dulceria\n7)Ventas en una sala\n8)Ventas en un horario\n9)Ventas totales\n10)Genero mas vendido",10);
							switch(opter){
								case 1:
									peliVendida(peliculas);
									break;
								case 2:
									dulceVendido(productos,mostrador);
									break;
								case 3:
									pelimenosVen(peliculas);
									break;
								case 4:
									dulcemenosVen(productos,mostrador);
									break;
								case 5:
									printf("Que dulce desea saber la ganancia?");
									scanf("%d",&i);
									gananciaDulce(mostrador[i]);
									break;
								case 6:
									gananciaDulceria(mostrador);
									break;
								case 7:
									printf("de que sala desea saber las ventas?");
									printf("En que horario?");
									scanf("%d",&i);
									printf("En que sala?");
									scanf("%d",&j);
									ventasSala(&cine[i-1][j-1]);
									break;
								case 8:
									printf("De que horario desea saber las ventas?");
									scanf("%d",&i);
									ventasHorario(i-1,cine);
									break;
								case 9:
									ventasCine(peliculas);
									break;
								case 10:
									generoVendido(peliculas);
									break;
								
							}
							break;
					}
				}while(opsec!=3);
				break;
			case 2:
				do{
					opsec=desplegarMenu("\n1)Compra de boleto\t2)Cancelacion de boleto\t3)salir",3);
					switch(opsec){
						case 1:
							mostrarCine(cine);
							do{
							eleccionSala(&horario,&sal);
							}while(cine[horario-1][sal-1].actual==NULL);
							compraasiento(&cine[horario-1][sal-1]);
							//se compro asiento
							imprimirSala(cine[horario-1][sal-1]);
							break;
						case 2:
							mostrarCine(cine);
							do{
							eleccionSala(&horario,&sal);
							}while(cine[horario-1][sal-1].actual==NULL);
							cancelarcompra(&cine[horario-1][sal-1]);
							break;
					}
				}while(opsec!=3);
				break;
			case 3:
				do{
					opsec=desplegarMenu("\n1)Encolar Cliente\t2)Atender Cliente\t3)salir",3);
					switch(opsec){
					case 1:
						uncliente=crearclienteD();
						uncliente->bandeja=crearPila(8);
    					listarDulces(productos);
					    printf("\nHola, cuantos producto deseas pedir??\n");
					    scanf("%d",&j);
					    for(i=0;i<j;i++){
				        	printf("\nProducto %d\n",i+1);
				        	scanf("%d",&fproducto);
				        	pushPila(productos[fproducto-1],uncliente->bandeja);
        					uncliente->cuenta+=(productos+fproducto-1)->venta;
					        printf("Su cuenta actual es:%.2f\n",uncliente->cuenta);
    					}
    					listarPila(uncliente->bandeja);
    					insertar(personas,*uncliente);
					    listar(*personas);
						break;
					case 2:
						i=0;
						listar(*personas);
						while(!validarVacio(*personas)&&i==0&&!pilaVacia(personas->arrCola[personas->h].bandeja)){
							Producto a;
							a=popPila(personas->arrCola[personas->h].bandeja);
							printf("%s ",a.nombre);
							for(j=0;j<8;j++){
								if(productos[j].nombre==a.nombre){
									if(mostrador[j].cantidad>=1){
										printf("\nSirviendo su %s\n",a.nombre);
										mostrador[j].cantidad--;
										mostrador[j].ventotal++;
										//printf("in");
									}
									else{
										i=1;
										//printf("out");
										reabastece(mostrador,productos,j);
										pushPila(a,personas->arrCola[personas->h].bandeja);
										insertar(personas,popCola(personas));
										printf("\nSin existencias exhibidad vuelva a la cola por favor\n");
									}
								}
							}
							if(!validarVacio(*personas)&&pilaVacia(personas->arrCola[personas->h].bandeja)){
								printf("Gracias por su compra\n");
								i=1;
								popCola(personas);
							}
							listar(*personas);
						}
						break;
					}
				}while(opsec!=3);
				break;
		}
	}while(opprin!=4);
	printf("%d",cine[0][0].asientos[0][0]->genero);
	//generoclientesven(cine);
	//espacio para pruebas


	return 0;
}


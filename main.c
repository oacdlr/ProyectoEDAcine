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
    stackProds *pila;
    pila = crearPila(NDOS);//NDOS es el numero de productos de la bandeja
    Cola *personas;

    personas= crearCola(15);
    Producto *productos;
    productos = (Producto *)calloc(NDOS, sizeof(Producto));//
    llenarArregloD(productos);
	iniMostrador(mostrador,productos);
    Cliente *uncliente;
	//menu principal
	int opprin,opsec;
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
							printf("in estad");
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
						inicializarPila(pila);
    					listarDulces(productos);
					    printf("\nHola, cuantos producto deseas pedir??\n");
					    scanf("%d",&j);
					    for(i=0;i<j;i++){
				        	printf("\nProducto %d\n",i+1);
				        	scanf("%d",&fproducto);
				        	pushPila(productos[fproducto-1],pila);
        					uncliente->cuenta+=(productos+fproducto-1)->venta;
					        printf("Su cuenta actual es:%.2f\n",uncliente->cuenta);
    					}
    					uncliente->bandeja=pila;
    					listarPila(uncliente->bandeja);
    					insertar(personas,*uncliente);
					    listar(*personas);
						break;
					case 2:
						i=0;
						while(i==0&&!pilaVacia(personas->arrCola[personas->h].bandeja)){
							Producto a;
							a=popPila(personas->arrCola[personas->h].bandeja);
							//printf("%s ",a.nombre);
							for(j=0;j<8;j++){
								if(productos[j].nombre==a.nombre){
									if(mostrador[j].cantidad>=1){
										mostrador[j].cantidad--;
										//printf("in");
									}
									else{
										i=1;
										//printf("out");
										reabastece(mostrador,productos,j);
										pushPila(a,personas->arrCola[personas->h].bandeja);
										insertar(personas,popCola(personas));
									}
								}
							}
							if(pilaVacia(personas->arrCola[personas->h].bandeja))
								i=1;
								popCola(personas);
						}
						listar(*personas);
						break;
					}
				}while(opsec!=3);
				break;
		}
	}while(opprin!=4);
	//*/
	/*
	//espacio para pruebas
	Producto pruebaprod;
	stackProds *stackpru;
	stackpru=pilaProducto(4);
	pruebaprod.nombre="papas";
	pruebaprod.venta=20.6;
	printf("%s %.2f",pruebaprod.nombre,pruebaprod.venta);
	pushPila(pruebaprod,stackpru);
	pruebaprod.nombre="palomitas";
	pruebaprod.venta=30.6;
	printf("%s %.2f",pruebaprod.nombre,pruebaprod.venta);
	pushPila(pruebaprod,stackpru);
	listarPila(stackpru);
	Producto aux=popPila(stackpru);
	printf("%s %.2f",aux.nombre,aux.venta);
	Sala prueba;
	Sala pr[2];
	Sala pru[2][3];
	Sala *prue;
	Cliente cliprueba;
    peliFunciones(peliculas,&horario,&sal,&pel);
	printf("%d %d",horario,sal);
	asignarPeli(&cine[horario-1][sal-1],peliculas+pel-1);
    printf("%s",cine[horario-1][sal-1].actual->nombre);
	/*
	asignarPeli(&cine[0][0],peliculas+8);
	asignarPeli(&prueba,peliculas);
  	asignarPeli(&pr[1],peliculas+1);
	prue=&cine;
	//asignarPeli(prue+1,peliculas+8);
	asignarPeli(&pru[1][1],peliculas+2);
	limpiarSala(&prueba);
//	printf("%d %d",&cine[0][0],prue);
	cliprueba.cuenta=20.5;
	prueba.asientos[2][3]=crearcliente(cliprueba);
	printf("pelicula en el cine %s\n",cine[0][0].actual->nombre);
	printf("%.2f %s\n",prueba.asientos[2][3]->cuenta,prueba.actual->nombre);
	printf("%.2f %s\n",prueba.asientos[2][3]->cuenta,pr[1].actual->nombre);
	printf("%.2f %s\n",prueba.asientos[2][3]->cuenta,pru[1][1].actual->nombre);
	prueba.asientos[2][4]=prueba.asientos[2][3];
	printf("funciona la asignacion de un asiento y relacion con otro \n");
	prueba.asientos[2][4]->cuenta=10.3;
	printf("%.2f %s\n",prueba.asientos[2][3]->cuenta,prueba.actual->nombre);
	printf("%.2f %s\n",prueba.asientos[2][4]->cuenta,prueba.actual->nombre);
	limpiarSala(&cine[0][0]);
	limpiarSala(&cine[0][1]);
//	printf("out");
	printf("%s",cine[0][0].actual->nombre);
	//printf("%s",cine[0][1].actual->nombre);
	/*
	printf("%s\n",pru[1][1].actual->nombre);
	compraasiento(&prueba);
	imprimirSala(prueba);
	cancelarcompra(&prueba);
	imprimirSala(prueba);
	printf("%d",prueba.actual->ventas);
	*/

	return 0;
}


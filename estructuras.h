#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
#define tmax 6
typedef struct {
	char *nombre;
	float precio;
	float venta;
	int cantidad;
}Producto;

typedef struct{
	Producto *bandej;
	int tope;
	int max;
}stackProds;
typedef struct{
	int edad;
	int genero;
	float cuenta;//suma de bandeja precio
	stackProds *bandeja;
}Cliente;
typedef struct{
	Producto *exhibido;
	int cantidad;
	int ventotal;
}Mostrador;

typedef struct {
    int max; // tama?o de la cola
    int h;
    int t;
    Cliente *arrCola; //arreglo cola
} Cola;
//funciones stack
stackProds *crearPila(int n);
int pilaLLena(stackProds *pila);
void pushPila(Producto dato,stackProds *pila);
void listarPila(stackProds *pila);
int pilaVacia(stackProds *pila);
Producto popPila(stackProds *pila);
void inicializarPila(stackProds *pila);
void liberaMamoria(stackProds *pila); //

//OPERACIONES DEL TAD COLA
void insertar(Cola *cola, Cliente dato) ;
Cliente popCola(Cola *cola);
Cola *crearCola(int max);
int validarEspacio(Cola cola);
int validarVacio(Cola cola);
void listar(Cola cola);
void liberarMemoriaCola (Cola cola);

//funciones queue


#endif

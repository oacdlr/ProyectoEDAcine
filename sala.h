#ifndef SALA_H_INCLUDED
#define SALA_H_INCLUDED
//structs pelicula,cliente,sala
typedef struct {
	char *nombre;
	float compra;
	float venta;
}Producto;

typedef struct{
	char *nombre;
	int ventas;
	int edadminima;
	char *genero;
	char *idioma;
}Pelicula;
typedef struct{
	int edad;
	int genero;
	float cuenta;//suma de bandeja precio
	//pila<comida> bandeja
}Cliente;
typedef struct{
	Cliente *asientos[16][16];
	Pelicula *actual;
}Sala;
//funciones
void asignarPeli(Sala *sala,Pelicula *pelicula);
void limparSala(Sala *sala);
Cliente *crearcliente(Cliente in);
void llenarDatos(Cliente *in);
void imprimirSala(Sala sala);
void compraasiento(Sala *sala);
void cancelarcompra(Sala *sala);
void mostrarCine(Sala *cine);  
void eleccionSala(int *horario,int *sal);
#endif

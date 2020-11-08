#ifndef SALA_H_INCLUDED
#define SALA_H_INCLUDED
//structs pelicula,cliente,sala
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
	float cuenta;//despues para el vip
}Cliente;
typedef struct{
	Cliente *asientos[30][30];
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
#endif

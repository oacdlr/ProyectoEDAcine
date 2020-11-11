#ifndef COLA360_H_INCLUDED
#define COLA360_H_INCLUDED
typedef struct {
    int max; // tama�o de la cola
    int h;
    int t;
    int *arrCola; //arreglo cola
} Cola;

//OPERACIONES DEL TAD COLA
void insertar(Cola *cola, int dato) ;
int borrar(Cola *cola);

//OPERACIONES AUXILIARES
Cola *crearCola(int max);
int validarEspacio(Cola cola);
int validarVacio(Cola cola);
void listar(Cola cola);
void liberarMemoria (Cola cola);

#endif // COLA360_H_INCLUDED

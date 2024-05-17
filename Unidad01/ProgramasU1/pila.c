#include <stdio.h>
#include <stdlib.h>
struct NodoLista
{
	int valor;
	struct NodoLista *ptrSiguiente;
};
//PROTOTIPO
struct NodoLista* insertar( struct NodoLista *posInicial, int valor);
void imprimirLista(struct NodoLista *posInicial);

int main(int argc, char const *argv[])
{
	struct NodoLista *refInicial=NULL;//*refInicial ES EL CONTENEDOR, DENTRO ESTA NULL
	refInicial=insertar(refInicial, 6);
	refInicial=insertar(refInicial, 8);
	refInicial=insertar(refInicial, 1);
	imprimirLista(refInicial);
	return 0;
}
struct NodoLista* insertar( struct NodoLista *posInicial, int valor)
{
	//VERIFICAR SI LA PILA ESTA VACIA
	if(posInicial==NULL)
	{//SI ESTA VACIA SE AGREGA EL PRIMER NODO
		//1) TENER LISTO DONDE SE VA A GUARDARE
		struct NodoLista *posNuevo = malloc( sizeof(struct NodoLista ) );
		posNuevo ->valor=valor;
		posNuevo->ptrSiguiente = NULL;
		posInicial=posNuevo;
	}
	else
	{//CUANDO NO TIENE, BUSCAMOS EL ULTIMO ELEMENTO DE LA LISTA PARA AGRGAR EL NUEVO NODO
		//printf("Hola\n");
		struct NodoLista *posActual=posInicial;
		while(posActual->ptrSiguiente != NULL)
		{
			posActual = posActual->ptrSiguiente;
		}
		 // CREAR Y AGREGAR EL NUEVO NODO AL LA LISTA
        struct NodoLista *posNuevo = malloc(sizeof(struct NodoLista));
        posNuevo->valor = valor;
        posNuevo->ptrSiguiente = NULL;
        // ASIGNAMOS EL NUEVO NODO AL ULTIMO NODO DE LA LISTA
        return posInicial;
	}
}
//TODO TERMINAR EL WHILE Y AGREGAR UN ELEMENTO MÁS
void imprimirLista(struct NodoLista *posInicial) {
    struct NodoLista *actual = posInicial;
    while (actual != NULL) {
        printf("%d ", actual->valor);
        actual = actual->ptrSiguiente;
    }
    printf("\n");
}
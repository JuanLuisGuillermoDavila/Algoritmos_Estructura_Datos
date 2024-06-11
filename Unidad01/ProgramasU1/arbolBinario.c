#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//ESTRUCTURAS
struct arbol
{
	int valor;
	struct arbol *ptrIzq;
	struct arbol *ptrDer;
};
//FUNCIONES PROTOTIPO
struct arbol* create(struct arbol *ptrInicial, int valor);
void preOrden(struct arbol *ptrArbol);
void inOrden(struct arbol *ptrArbol);
void posOrden(struct arbol *ptrArbol);
//MAIN
int main(int argc, char const *argv[])
{
	struct arbol* box=NULL;
	int valor;
	srand(time(NULL));
	printf("DATOS DEL ARBOL:\n");
	for (int i = 0; i <= 10; ++i)
	{
		valor=rand()%15;
		printf("%d ",valor);
		box = create(box,valor);
	}
    printf("\n\nEl recorrido en pre orden es:\n");
    preOrden(box);
    printf("\n\nEl recorrido in orden es:\n");
    inOrden(box);
    printf("\n\nEl recorrido en pos orden es:\n");
    posOrden(box);
	return 0;
}//END MAIN

//FUNCIONES
struct arbol*create(struct arbol *ptrInicial, int valor)
{

	if(ptrInicial==NULL)
	{
		struct arbol *nuevoNodo =malloc(sizeof(struct arbol));
		if(nuevoNodo!=NULL)
		{
			nuevoNodo->valor= valor;
			nuevoNodo->ptrIzq=NULL;
			nuevoNodo->ptrDer=NULL;
			return nuevoNodo;
		}//END IF
	}//END IF
	else
	{
		if(valor < ptrInicial->valor)
		{
			ptrInicial->ptrIzq =create(ptrInicial->ptrIzq,valor);
		}
		else if(valor > ptrInicial->valor)
		{
			ptrInicial->ptrDer = create(ptrInicial->ptrDer,valor);
		}
		else
		{
			printf("<- dup ");
		}
	}
	return ptrInicial;	
}
void preOrden(struct arbol *ptrArbol)
{
	if(ptrArbol!=NULL)
	{
		printf(" %d ", ptrArbol->valor);
		preOrden(ptrArbol->ptrIzq);
		preOrden(ptrArbol->ptrDer);
	}
}
void inOrden(struct arbol *ptrArbol)
{
	if(ptrArbol!=NULL)
	{
		inOrden(ptrArbol->ptrIzq);
		printf(" %d ", ptrArbol->valor);
		inOrden(ptrArbol->ptrDer);
	}
}
void posOrden(struct arbol *ptrArbol)
{
	if(ptrArbol!=NULL)
	{
		posOrden(ptrArbol->ptrIzq);
		posOrden(ptrArbol->ptrDer);
		printf(" %d ", ptrArbol->valor);
	}
}
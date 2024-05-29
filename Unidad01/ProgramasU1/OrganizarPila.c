#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//ESTRUCTURA
struct nodoLista
{
	int valor;
	struct nodoLista *aux;
};
//FUNCIONES PROTOTIPO
struct nodoLista* create(struct nodoLista *ptrInicial);
void read(struct nodoLista *ptrInicial);
void order(struct nodoLista *ptrInicial, int n);
int main(int argc, char const *argv[])
{
	int n=8;
	srand(time(NULL)); //Generamos número aleatorio en base al tiempo
	struct nodoLista *box=NULL;//*box ES EL CONTENEDOR
	for (int i = 0; i < n; ++i)
	{
		box=create(box);
	}
	read(box);
	order(box,n);
	read(box);
	return 0;
}
//FUNCIONES
struct nodoLista* create(struct nodoLista *ptrInicial)
{
	//CREAMOS EL NUEVO NODO
	struct nodoLista *auxNuevo =malloc(sizeof(struct nodoLista));
	auxNuevo->valor= rand()%10+1;
	auxNuevo->aux=NULL;
	//VERIFICAMOS SI LA LISTA ESTA VACIA
	if (ptrInicial==NULL)
	{
		//COMO LA PILA ESTA VACIA, AGREGAMOS EL PRIMER ELEMENTO
		ptrInicial=auxNuevo;
	}else
	{
		//COMO LA PILA YA NO ESTA VACIA, AGREGAMOS LOS NUEVOS ELEMENTOS
		struct nodoLista *boxActual =ptrInicial;
		while(boxActual->aux!=NULL)
		{//RECORREMOS LA PILA PARA LLEGAR A LA CIMA
			boxActual=boxActual->aux;
		}
		//AGREGAMOS EL NUEVO ELEMENTO A LA CIMA DE LA PILA
		boxActual->aux=auxNuevo;
	}
	return ptrInicial;
}
void read(struct nodoLista *ptrInicial)
{
	if(ptrInicial==NULL)
	{
		printf("LA PILA ESTA VACIA !\n");
	}else
	{
		printf("DATOS DE LA PILA:\n");
		while (ptrInicial!=NULL)
		{
			printf("%d\t",ptrInicial->valor);
			ptrInicial=ptrInicial->aux;
		}
		
	}
}
void order(struct nodoLista *ptrInicial, int n)
{
	int tmp=0;
	for(int i=0; i<n; i++)
    {
    	struct nodoLista *boxActual =ptrInicial;
		struct nodoLista *boxSigiente = boxActual->aux;
    	for (int j = 0; j < n-1; ++j)
    	{
    		if(boxActual->valor>boxSigiente->valor)
    		{
    			tmp=boxSigiente->valor;
    			boxSigiente->valor=boxActual->valor;
    			boxActual->valor=tmp;
    		}
    		boxActual=boxActual->aux;
    		boxSigiente=boxActual->aux;

    	}
    }
    printf("\nPILA ORDENADA! \n");
}
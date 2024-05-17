/*TODO: CREARE UN CRUD(Create, Read, Update, Delete) UTILIZANDO UNA ESTRUCTURA QUE CONTENGA UN VALOR (INT) Y QUE ESTE AUTO REFERENCIADA,
TODO ESTO ATRAVEZ DE UNA PILA
*/
#include <stdio.h>
#include <stdlib.h>
//ESTRUCTURA
struct nodoLista
{
	int valor;
	struct nodoLista *aux;
};
//FUNCIONES PROTOTIPO
struct nodoLista* create(struct nodoLista *ptrInicial, int valor);
void read(struct nodoLista *ptrInicial);
void update(struct nodoLista *ptrInicial, int valor, int valorUp);
struct nodoLista* delete(struct nodoLista *ptrInicial);
//MAIN
int main(){
	int OPC, v,vU, x=1;
	struct nodoLista *box=NULL;//*box ES EL CONTENEDOR
	while(x==1)
	{
		printf("PILA:\n1) Agregar \t 2)Imprimir \t 3) Actualizar \t 4) Eliminar \t 5) Salir\nOPC: ");
		scanf(" %d",&OPC);
	switch (OPC)
		{
		case 1:
			printf("VALOR A INGRESAR A LA PILA: ");
			scanf(" %d", &v);
			box=create(box, v);
			printf("AGREGADO A LA PILA !\n");
			break;
		case 2:
			read(box);
			break;
		case 3:
			if(box==NULL)
			{
				printf("LA PILA ESTA VACIA !\n");
				break;
			}else
			{
							read(box);
				printf("QUE VALOR DE LA PILA DESEA ACTUALIZAR: ");
				scanf(" %d",&v);
				printf("INGRESE EL NUEVO VALOR: ");
				scanf(" %d",&vU);
				update(box,v,vU);
				read(box);
				break;
			}
		case 4:
			box=delete(box);
			break;
		case 5:
			printf("ADIOS..........");
			x=0;
			break;
		
		default:
		printf("OPCION NO VALIDA\n");
			break;
		}
	}
	return 0;
}
//FUNCIONES
struct nodoLista* create(struct nodoLista *ptrInicial, int valor)
{
	//CREAMOS EL NUEVO NODO
	struct nodoLista *auxNuevo =malloc(sizeof(struct nodoLista));
	auxNuevo->valor= valor;
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
void update(struct nodoLista *ptrInicial, int valor, int valorUp)
{
	while (ptrInicial->valor!=valor)
	{
		ptrInicial=ptrInicial->aux;
	}
	ptrInicial->valor=valorUp;
	printf("PILA ACTUALIZADA !\n");
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
			printf("%d\n",ptrInicial->valor);
			ptrInicial=ptrInicial->aux;
		}
		
	}
}
struct nodoLista* delete(struct nodoLista *ptrInicial)
{
	if (ptrInicial == NULL)
    {
        printf("LA PILA ESTA VACIA !\n");
        return NULL;
    }
	struct nodoLista *boxActual =ptrInicial;
	struct nodoLista *boxAnterior =NULL;
	while(boxActual->aux!=NULL)
	{//RECORREMOS LA PILA PARA LLEGAR A LA CIMA
		boxAnterior=boxActual;
		boxActual=boxActual->aux;
	}
	if(boxAnterior!=NULL)
	{
		boxAnterior->aux=NULL;
	}
	else
	{
		ptrInicial=NULL;//CUANDO ELIMINAMOS EL ULTIMO ELEMENTO TENEMOS QUE CONVERTIR ptrInicial como al principio del programa
	}
	//ptrInicial=boxAnterior; NO HAY QUE ACTUALIZAR ptrInicial porque es una pila XD
	free(boxActual);
	printf("ELEMENTO ELIMINADO !\n");
	return ptrInicial;
}
#include <stdlib.h>
#include <stdio.h>
struct nodoLista
{
	int valor;
	struct nodoLista *ptrSiguiente;//APUNTADOR AL SIGUIENTE NODO	
};
typedef struct nodoLista NodoLista;
typedef NodoLista *ptrNodoLista;
//PROTOTIPO
void insertar(ptrNodoLista *ptrS, int valor);
void imprimir(ptrNodoLista ptrActual);
int eliminar(ptrNodoLista *ptrS, int valor);
int actualizarValor(ptrNodoLista *ptrS, int valor, int valorA);
int main(int argc, char const *argv[])
{
	ptrNodoLista ptrInicial = NULL; //inicialmente no existen nodos
	int elemento =4;
    insertar(&ptrInicial, elemento);
    insertar(&ptrInicial, 6);
    insertar(&ptrInicial, 1);
    imprimir(ptrInicial);
    eliminar(&ptrInicial, 7);
    printf("ACTUALIZANDO LISTA...\n\n");
    actualizarValor(&ptrInicial, 6, 22);
    imprimir(ptrInicial);
    
	return 0;
}
//FUNCIONES
void insertar(ptrNodoLista *ptrS, int valor)
{
	ptrNodoLista ptrNuevo; /* apuntador a un nuevo nodo */
	ptrNodoLista ptrAnterior; /* apuntador a un nodo previo de la lista */
	ptrNodoLista ptrActual; /* apuntador al nodo actual de la lista */
	ptrNuevo = malloc( sizeof( NodoLista ) ); /* crea un nodo en un espacio nuevo de la memoria */
	//VERIFICAMOS SI SE ASIGNO A LA MEMORIA
	if ( ptrNuevo != NULL ) { /* es espacio disponible */
		ptrNuevo->valor = valor; /* coloca el valor en el nodo */
		ptrNuevo->ptrSiguiente = NULL; /* el nodo no se liga a otro nodo */

		ptrAnterior = NULL;
		ptrActual = *ptrS;
		if(ptrAnterior==NULL)
		{
			ptrNuevo->ptrSiguiente=*ptrS;
			*ptrS=ptrNuevo;
		}
		else
		{
			pri
			ptrAnterior->ptrSiguiente=ptrNuevo;
			ptrNuevo->ptrSiguiente =ptrActual;
		}
	}
	else
	{
		printf("No se inserto %d. No hay memoria disponible.\n", valor);
	}
}//FIN DE INSERTAR
void imprimir(ptrNodoLista ptrActual)
{
	/* si la lista está vacía */
	if ( ptrActual == NULL ) 
	{
		printf( "La lista esta vacia.\n\n" );
	} /* fin de if */
	else
	{
		printf( "La lista es:\n" );
		/* mientras no sea el final de la lista */
		while ( ptrActual != NULL )
		{
			printf("%d —> ", ptrActual->valor );
			ptrActual = ptrActual->ptrSiguiente;
		} /* fin de while */
		printf( "NULL\n\n");
	} /* fin de else */
} /* fin de la función imprimeLista */
int eliminar(ptrNodoLista *ptrS, int valor)
{
	ptrNodoLista ptrAnterior;
	ptrNodoLista ptrActual;
	ptrNodoLista tempPtr;
	//eliminar el primer nodo
	if (valor==(*ptrS)->valor)
	{
		tempPtr=*ptrS;
		*ptrS=(*ptrS)->ptrSiguiente;
		free(tempPtr);
	}
	else
	{
		ptrAnterior=*ptrS;
		ptrActual=(*ptrS)->ptrSiguiente;
		while(ptrActual!= NULL && ptrActual->valor!=valor)
		{
			ptrAnterior=ptrActual;
			ptrActual=ptrActual->ptrSiguiente;
		}
		if(ptrActual!=NULL)
		{
			tempPtr=ptrActual;
			ptrAnterior->ptrSiguiente=ptrActual->ptrSiguiente;
			free(tempPtr);
		}
		else
		{
		    printf("%d NO SE ENCIENTRA\n\n",valor);//EN CASO DE QUE NO SE ENCUENTRE EL ELEMENTO QUE SE VA A ELIMINAR
		}
	}
 return 0;
}
int actualizarValor(ptrNodoLista *ptrS, int valor, int valorA)
{
	/*ptrNodoLista ptrActual = *ptrS;
	int *d=&valorA;
		while(ptrActual!= NULL && ptrActual->valor!=valor)
		{
			*ptrActual->valor=&valorA;
			//ptrActual=ptrActual->ptrSiguiente;
		}
 return 0;*/
 	ptrNodoLista ptrActual = *ptrS; // Inicializamos ptrActual con el primer nodo de la lista
	while(ptrActual != NULL)
	{
		if(ptrActual->valor == valor) // Si encontramos el nodo con el valor que buscamos
		{
			ptrActual->valor = valorA; // Actualizamos su valor
			break; // Salimos del bucle, ya que hemos encontrado y actualizado el valor
		}
		ptrActual = ptrActual->ptrSiguiente; // Pasamos al siguiente nodo
	}
	return 0;
}
/*TODO: INVESTIGAR COMO AGREGARLOS HACIA LA DERECHA
En realidad, en una lista enlazada, la noción de "derecha" o "izquierda" no es relevante en el sentido convencional, 
ya que los elementos de la lista no están necesariamente ordenados en una dirección específica en memoria. Más bien,
se trata de la dirección en la que los punteros están apuntando.
En el caso de esta lista enlazada, cuando se inserta un nuevo nodo al final, se está añadiendo después del último nodo existente. 
Entonces, si visualizas la lista como una secuencia, el nuevo nodo se añadiría después del último elemento, 
lo que podrías interpretar como una expansión hacia la "derecha" en la secuencia de la lista. Sin embargo, este término es más conceptual que literal.

Entonces, en el contexto de una lista enlazada, no se trata realmente de derecha o izquierda en términos de direcciones de memoria, 
sino más bien de la secuencia de nodos en la lista. En este caso, "hacia la derecha" simplemente se refiere a agregar un nuevo nodo al final de la secuencia existente.*/


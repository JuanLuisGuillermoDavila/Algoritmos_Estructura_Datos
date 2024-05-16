#include <stdlib.h>
#include <stdio.h>

struct nodoLista {
    int valor;
    struct nodoLista* ptrSiguiente; // APUNTADOR AL SIGUIENTE NODO
};

typedef struct nodoLista NodoLista;
typedef NodoLista* ptrNodoLista;

// PROTOTIPO
void insertar(ptrNodoLista* ptrS, int valor);
void imprimir(ptrNodoLista ptrActual);

int main(int argc, char const* argv[]) {
    ptrNodoLista ptrInicial = NULL; // inicialmente no existen nodos
    int elemento = 4;
    insertar(&ptrInicial, elemento);
    insertar(&ptrInicial, 6);
    insertar(&ptrInicial, 1);
    imprimir(ptrInicial);
    return 0;
}

// FUNCIONES
void insertar(ptrNodoLista* ptrS, int valor) {
    ptrNodoLista ptrNuevo;  /* apuntador a un nuevo nodo */
    ptrNodoLista ptrActual; /* apuntador al nodo actual de la lista */

    ptrNuevo = malloc(sizeof(NodoLista)); /* crea un nodo */

    // VERIFICAMOS SI SE ASIGNÓ A LA MEMORIA
    if (ptrNuevo != NULL) 
    { 
        ptrNuevo->valor = valor; /* coloca el valor en el nodo */
        ptrNuevo->ptrSiguiente = NULL; /* el nodo no se liga a otro nodo */

        // Si la lista está vacía, el nuevo nodo es el primero
        if (*ptrS == NULL) 
        {
            *ptrS = ptrNuevo;
        } 
        else 
        {
            ptrActual = *ptrS;

            // Avanzamos hasta el último nodo
            while (ptrActual->ptrSiguiente != NULL) 
            {
                ptrActual = ptrActual->ptrSiguiente;
            }

            // Enlazamos el nuevo nodo al último nodo
            ptrActual->ptrSiguiente = ptrNuevo;
        }
    } 
    else 
    {
        printf("No se insertó %d. No hay memoria disponible.\n", valor);
    }
}

void imprimir(ptrNodoLista ptrActual) {
    /* si la lista está vacía */
    if (ptrActual == NULL) {
        printf("La lista está vacía.\n\n");
    } else {
        printf("La lista es:\n");
        /* mientras no sea el final de la lista */
        while (ptrActual != NULL) {
            printf("%d —> ", ptrActual->valor);
            ptrActual = ptrActual->ptrSiguiente;
        } /* fin de while */
        printf("NULL\n\n");
    } /* fin de else */
}

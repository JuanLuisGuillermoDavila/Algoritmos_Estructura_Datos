#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura del nodo de la lista enlazada
struct NodoLista{
    char *cadena;
    struct NodoLista *siguiente;
};

// Estructura del nodo de la tabla hash
struct NodoTabla {
    struct NodoLista *inicio;
};

// Prototipo de funciones
struct NodoLista *crearNodoLista(char *cadena);
int funcionHash(char *cadena, int size);
void insertar(struct NodoTabla *tablaHash, char *cadena);
struct NodoLista *buscar(struct NodoTabla *tablaHash, char *cadena, int *indiceEncontrado);

// Función principal
int main(int argc, char const *argv[]) 
{
    int size = 10;
    struct NodoTabla tablaHash[size];
    for (int i = 0; i < size; i++) {
        tablaHash[i].inicio = NULL;
    }

    insertar(tablaHash, "Hola");
    insertar(tablaHash, "Mundo");
    insertar(tablaHash, "Halo");
    insertar(tablaHash, "Nublado");

    //PARA BUSCAR
    int indice;
    buscar(tablaHash, "Mundo", &indice);
    buscar(tablaHash, "Hola", &indice);
    buscar(tablaHash, "Halo", &indice);
    buscar(tablaHash, "Nublado", &indice);
    buscar(tablaHash, "PIPIPIPI", &indice);
    return 0;
}

// Funciones
struct NodoLista *crearNodoLista(char *cadena) {
    struct NodoLista *nuevoNodo = (struct NodoLista *)malloc(sizeof(struct NodoLista));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(1);
    }
    nuevoNodo->cadena = strdup(cadena); // Copiar la cadena en el nuevo nodo
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void insertar(struct NodoTabla *tablaHash, char *cadena) {
    int indice = funcionHash(cadena, 10);
    struct NodoLista *nuevoNodo = crearNodoLista(cadena);
    nuevoNodo->siguiente = tablaHash[indice].inicio;
    tablaHash[indice].inicio = nuevoNodo;
}

int funcionHash(char *cadena, int size) {
    int hash = 0;
    for (int i = 0; cadena[i] != '\0'; i++) {
        hash += cadena[i];
    }
    //printf("%d \n",hash);
    return hash % size;
}

struct NodoLista *buscar(struct NodoTabla *tablaHash, char *cadena, int *indiceEncontrado) {
    int indice = funcionHash(cadena, 10);
    struct NodoLista *actual = tablaHash[indice].inicio;
    while (actual != NULL) {
        if (strcmp(actual->cadena, cadena) == 0) {
            *indiceEncontrado = indice; // Guardar el índice donde se encontró la cadena
            printf("La cadena '%s' se encontró en el índice %d.\n", cadena, indice);
            return actual; // Se encontró la cadena
        }
        actual = actual->siguiente;
    }
    *indiceEncontrado = -1; // La cadena no se encontró en la tabla
    printf("La cadena '%s' no se encontró en el índice.\n", cadena);
    return NULL;
}


/*TODO: TABLA HASH DE DIMENCION N-1 QUE PERMITA AGREGAR DATOS A LAS ESTRUCTURAS, QUE LA IMPRIMA LO QUE CONTIENE LA POSICION
MODIFICAR LAS ESTRUCTURAS Y ELIMINAR TODA UNA COLECCION*/
#include <stdio.h>
#include <stdlib.h>
/*El siguiente programa contiene una tabla hash de tamaño "n-1" que almacena estructuras(Pilas), con n datos de tipo entero*/
//Estructuras
struct pila
{
	int valor;
	struct pila* aux;
};
struct tablaHash
{
	int size;
	struct pila* arr[];
};

//FUNCIONES PROTOTIPO
struct pila *create(struct pila* ptrInicial, int valor, struct tablaHash* indice, int size);
int funcionHash(int valor, int size);
void printTablaHash(struct tablaHash* tabla);

//MAIN
int main(int argc, char const *argv[])
{
	int size=10;//TAMAÑO DE LA TABLA
	struct pila* box=NULL;
	struct tablaHash* tabla = malloc(sizeof(struct tablaHash) + size * sizeof(struct pila*));
	//tabla->arr = malloc(size * sizeof(struct pila*));//ASIGNAMOS MEMORIA AL ARRAY DE LA TABLA
	for (int i = 0; i < size; ++i)
	{
		tabla->arr[i] = NULL;
	}//END FOR
    box = create(box, 5, tabla,size);
    box = create(box, 15, tabla,size); // Colisión intencional con 5 si size es 10
    box = create(box, 20, tabla,size);
    printTablaHash(tabla);

	return 0;
}//END MAIN

struct pila* create(struct pila* ptrInicial, int valor, struct tablaHash* indice, int size) {
    struct pila* nuevoNodo = malloc(sizeof(struct pila));
    if (nuevoNodo == NULL)
    {
        printf("No se pudo asignar memoria\n");
  
    }//END IF
    nuevoNodo->valor = valor;
    nuevoNodo->aux = NULL;
    
    int pos = funcionHash(valor, size);
    if (indice->arr[pos] == NULL) 
    {
        indice->arr[pos] = nuevoNodo;
    }//END IF 
    else 
    {
        struct pila* actual = indice->arr[pos];
        while (actual->aux != NULL) {
            actual = actual->aux;
        }//END WHILE
        actual->aux = nuevoNodo;
    }//END ELSE
    return ptrInicial;
}//END  
int funcionHash(int valor, int size) {

    return valor % size;
}//END
void printTablaHash(struct tablaHash* tabla) {
    for (int i = 0; i < tabla->size; i++) 
    {
        printf("Posicion %d: ", i);
        struct pila* actual = tabla->arr[i];
        while (actual != NULL) 
        {
            printf("%d -> ", actual->valor);
            actual = actual->aux;
        }//END WHILE
        printf("NULL\n");
    }//END FOR
}//END
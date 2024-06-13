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

//Funciones prototipo
void create(int valor, struct tablaHash* indice, int size);
int funcionHash(int valor, int size);
void read(struct tablaHash* tabla,int size);
void update(struct tablaHash* tabla,int size, int valor, int valorNw);
void delete(struct tablaHash* tabla, int size, int indice);
//Main
int main(int argc, char const *argv[])
{
	int size=10;//size de la tabla
    struct tablaHash* tabla = malloc(sizeof(struct tablaHash) + size * sizeof(struct pila*));
    tabla->size = size;
	for (int i = 0; i < size; ++i)
	{
		tabla->arr[i] = NULL;
	}//End for
    //Ingresamos datos a la tabla "Create"
    create(5, tabla,size);
    create(15, tabla,size); // Colisión intencional con 5 
    create(20, tabla,size);
    create(1, tabla,size);
    //Imprimir "Read"
    read(tabla,size);
    //Editar "Update"
    update(tabla,size,4,15);//Incorrecto
    update(tabla,size,1,11);//Correcto
    update(tabla,size,9,15);//Valor que no esta en la tabla
    read(tabla,size);
    // Eliminar datos en una posición específica
    delete(tabla, size, funcionHash(19, size));
    delete(tabla, size, funcionHash(5, size));
    read(tabla,size);

    //editar
	return 0;
}//End main

void create(int valor, struct tablaHash* indice, int size) {
    struct pila* nuevoNodo = malloc(sizeof(struct pila));
    if (nuevoNodo == NULL)
    {
        printf("No se pudo asignar memoria\n");
  
    }//End if
    nuevoNodo->valor = valor;
    nuevoNodo->aux = NULL;
    
    int pos = funcionHash(valor, size);
    if (indice->arr[pos] == NULL) 
    {
        indice->arr[pos] = nuevoNodo;
    }//End if
    else 
    {
        struct pila* actual = indice->arr[pos];
        while (actual->aux != NULL) {
            actual = actual->aux;
        }//End while
        actual->aux = nuevoNodo;
    }//End else
}//End fn
int funcionHash(int valor, int size)
{
    return valor % size;
}//End fn
void read(struct tablaHash* tabla, int size) {
    for (int i = 0; i < size; i++) 
    {
        printf("Posicion %d: ", i);
        struct pila* actual = tabla->arr[i];
        while (actual != NULL) 
        {
            printf("%d -> ", actual->valor);
            actual = actual->aux;
        }//End while
        printf("NULL\n");
    }//End for
}//End fn

void update(struct tablaHash* tabla,int size, int valor, int valorNw)
{
    /*Para que la tabla hash sigan funcionando correctamente
    es necesario poner una condicion que nos verifique que el valor que se va a editar y
    el nuevo valor tengan el mismo modulo "%", de lo contrario si el usuario quiere buscar el valor
    sera imposible encontrarlo en la tabla*/
    int flag=0;
    int indice = funcionHash(valor,size);
    int mod = funcionHash(valorNw,size);
    struct pila* actual = tabla->arr[indice];
    if(indice== mod)
    {
        while (actual != NULL) 
        {
            if(actual->valor==valor)
            {
                actual->valor=valorNw;
                flag=1;
            }//End if
            actual = actual->aux;
        }//End while
    }//End if
    else
    {
        printf("No se pudo actualizar el valor %d por %d, porque no comparten el mismo modulo\n",valor,valorNw);
    }//End else
    if(flag==0)
    {
        printf("y %d no se encuentra en la tabla\n",valorNw);
    }//End if
}//End fn
void delete(struct tablaHash* tabla, int size, int indice)
{
    struct pila* actual = tabla->arr[indice];
    struct pila* temp;
    if(tabla->arr[indice]!=NULL)
    {
        while (actual != NULL) {
            temp = actual;
            actual = actual->aux;
            free(temp);
        }//End while
        tabla->arr[indice] = NULL;
        printf("Datos en la posición %d eliminados\n", indice);
    }//End if
    else
    {
        printf("La posición %d no tiene elementos\n", indice);
    }//End else
}//End fn
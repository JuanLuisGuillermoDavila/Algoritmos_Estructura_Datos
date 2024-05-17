/*TODO: CREARE UN CRUD(Create, Read, Update, Delete) UTILIZANDO UNA ESTRUCTURA QUE CONTENGA UN VALOR (INT) Y QUE ESTE AUTO REFERENCIADA,
TODO ESTO ATRAVEZ DE UNA PILA
*/
#include <stdio.h>
#include <stdlib.h>
//ESTRUCTURA
struct NodoLista
{
	int valor;
	struct NodoLista *aux;
};
//FUNCIONES PROTOTIPO
void create(struct NodoLista *ptrInicial, int valor);
void read(struct NodoLista *ptrInicial);
void update(struct NodoLista *ptrInicial, int valor);
void delete(struct NodoLista *ptrInicial, int valor);
int main(int argc, char const *argv[]){
	return 0;
}
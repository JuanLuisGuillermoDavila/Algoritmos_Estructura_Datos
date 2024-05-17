#include <stdio.h>
#include <stdlib.h>
//ESTRUCTURA
struct Estructura
{
	int x;
	int y;
	struct Estructura *aux;
};
int main()
{
	//EJEMPLO DE APUNTADORES
	/*int *p= malloc(sizeof(int));
	//8 int
	*p=8;
	printf("%p\n",p);
	printf("%d\n",*p);*/
    struct Estructura *ptr= malloc(sizeof(struct Estructura));//EL APUNTADOR ES EL QUE NOS AYUDA A ACCEDER A LO QUE CONTIENE LA ESTRUCTURA
    ptr->x=9;//"->" apuntador por eso ptr no lleva * y accedemos a lo que esta apuntando
    ptr->y=3*ptr->x;
    printf("ESTRUCTURA\n");
    printf("%d\n",ptr->y);
    ptr->aux=ptr;//LO QUE HACEMOS ES GUARDAR EN aux LA DIRECCION DE MEMORIA DE ptr #NO ES ptr->aux=*ptr PORQUE ESTAMOS UTILIZANDO "->"
    //CREAMOS UN NUEVO NODO DE LA ESTRUCTURA, EL ANTUGUO GUARDA EN AUX EL VALOR DEL NUEVO Y EL NUEVO GUARDA EL VALOR DE EL MISMO
    ptr->aux->x=3;
    ptr->aux->y=18;
    ptr->aux->aux=ptr->aux;
    return 0;

}

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
    struct Estructura *ptrInicial= malloc(sizeof(struct Estructura));//EL APUNTADOR ES EL QUE NOS AYUDA A ACCEDER A LO QUE CONTIENE LA ESTRUCTURA
    ptrInicial->x=9;
    ptrInicial->y=27;
    ptrInicial->aux=malloc(sizeof(struct Estructura));//AUTO GUARDAMOS LA DIRECCION DE MEMORIA DEL PRIMER ELEMENTO EN AUX
    struct Estructura *ptrSegundo=ptrInicial->aux;//GUARDAMOS EL VALOR DE AUX DE ptrInicial el AUX DE ptrSegundo
    ptrSegundo->x=3;
    ptrSegundo->y=18;
    ptrSegundo->aux=malloc(sizeof(struct Estructura));
    struct Estructura *ptrTercero=ptrSegundo->aux;//GUARDAMOS EL VALOR DE AUX DE ptrSegundo en el AUX DE ptrTercero
    ptrTercero->x=21;
    ptrTercero->y=34;
    ptrTercero->aux=NULL;//COMO ptrTercero ES LA CIMA DE LA PILA LE ASIGNAMOS EL VALOR DE NULL
    printf("%d\n", ptrInicial->x);
    printf("%d\n", ptrInicial->y);
    printf("%d\n", ptrSegundo->x);
    printf("%d\n", ptrSegundo->y);
    printf("%d\n", ptrTercero->x);
    printf("%d\n", ptrTercero->y);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//ESTRUCTURAS
//TODO HACER UN CICLO QUE RECORRA Y AGREGAR MÁS ELEMENTOS
struct elemento
{
	int valor;
	struct elemento *autoreferencia;//variable de tipo elemento
};
int main(int argc, char const *argv[])
{
	struct elemento inicial,b,c,d;
	inicial.valor=8;
	inicial.autoreferencia=&b;
	inicial.autoreferencia=&b;
	b.valor =9;
	b.autoreferencia=&c;
	c.valor =10;
	c.autoreferencia=&d;
	d.valor =2;
	//d.autoreferencia=&inicial;AAAAAAAAAAAA
	d.autoreferencia=NULL;//NULL NOS INDICA QUE ES EL FINAL DE LA LISTA
	//INICIO
	struct elemento* aux = &inicial;//AUXILIAR ES UN APUNTADOR AL NODO INICIAL
	do
	{
	    if(aux->autoreferencia!=NULL)
        {
        	printf("%d\n",aux->valor);
            aux=aux->autoreferencia;
        }
        else
        {
            printf("%d\n",aux->valor);
            break;
        }

	}while(1);//MIENTRAS EXISTAN ELEMENTOS EN LA ESTRUCTURA, QUE SIGA ITERANDO
	return 0;
}
//TODO
/*QUE ES: malloc, free: UNA PRESENTACION EN POWERPOINT PARA EL JUEVES 02 "ASIGNACION DINAMICA DE MEMORIA"
ejemplo en programación "GESTION DE MEMORIA" 5-10 min*/
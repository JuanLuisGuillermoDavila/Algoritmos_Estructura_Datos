#include <stdio.h>
#include <stdlib.h>
//ESTRUCTURAS
struct elemento 
{
	int valor;
	struct elemento *autoreferencia;//variable de tipo elemento
}/*a,b,conjunto[3]*/;

int main(int argc, char const *argv[])
{
	//typedef struct elemento ele;
	//struct elemento b;
	struct elemento a,b,conjunto[3];
	b.valor =11;
	b.autoreferencia=&b;
	printf("%p\n",b.autoreferencia);
	a.valor =56;
	a.autoreferencia=&a;
	printf("%p\n",a.autoreferencia);
	//arreglo
	conjunto[0]=b;
	conjunto[1].valor=8;
	conjunto[1].autoreferencia=&conjunto[1];
	//printf("%d",conjunto[0].autoreferencia);
	return 0;
}
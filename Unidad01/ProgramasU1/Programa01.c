/*BUSQUEDA SECUENCIAL LINEAL, DE IZQUIERDA A DERECHA, EL ARREGLO POR REFERENCIA(EN UNA FUNCION)
->REFERENCIA AL ARREGLO
->n A BUSCAR
->RET. POSICION*/
#include <stdio.h>
#include <stdlib.h>//PARA UTILIZAR LA FUNCION RAND
#include <time.h>//PARA CAMBIAR LOS NÚMEROS QUE NOS DA RAND()
//FUNCIONES PROTOTIPO
void LlenarArreglo(int arr[],int size);//LLENAR EL ARREGLO
int BusquedaIzqDerF(int arr[], int size, int n);//Busqueda Secuencial-Izquierda-Derecha CICLO FOR
int BusquedaIzqDerW(int arr[], int size, int n);//Busqueda Secuencial-Izquierda-Derecha CICLO WHILE

//MAIN
int main(int argc, char const *argv[])
{
	srand (time(NULL));//PARA QUE LOS VALORES PSEUDOALEATORIOS SEAN DIFERENTES CADA QUE SE EJECUTA EL PROGRAMA
	int n;// n SERA LA VARIABLE QUE BUSCAREMOS EN EL ARREGLO
	//int arr[]={5,4,3,2,1};
	int arr[5];
	int t=sizeof(arr)/sizeof(arr[0]);
	LlenarArreglo(arr,t);//PARA DATOS PSEUDOALEATORIOS
	printf("QUE NÚMERO DESEA BUSCAR: ");
	scanf("%d",&n);
	printf("CICLO FOR\n");
	BusquedaIzqDerF(arr,t,n);
	printf("CICLO WHILE\n");
	BusquedaIzqDerW(arr,t,n);
	return 0;
}
//FUNCIONES
void LlenarArreglo(int arr[],int size)
{
	for(int i=0; i<size;i++)
	{
		arr[i]=rand()%10+1;
		printf("%d\t",arr[i] );
	}
	printf("\n");
}
int BusquedaIzqDerF(int arr[], int size, int n)
{
	for(int i=0; i<size;i++)
	{
		if(arr[i]==n) return printf("EL NUMERO '%d' SE ENCUENTRA EN LA POSICION %d\n",n,i);
	}
	return printf("%d NO SE ENCUENTRA EN EL ARREGLO\n",n);
}
//TODO: HACERLO CON UN WHILE
int BusquedaIzqDerW(int arr[], int size, int n)
{
	int i=0;
	while(1)
	{
		if(i<size)
		{
			if(arr[i]==n) return printf("EL NUMERO '%d' SE ENCUENTRA EN LA POSICION %d\n",n,i);

		}else{
			return printf("%d NO SE ENCUENTRA EN EL ARREGLO\n",n);
		}
		i+=1;
	}
}
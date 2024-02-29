#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//FUNCIONES PROTOTIPO
void Ordenar(int x, int arr[]);
//MAIN
int main()
{
    //int tam=5;
    int Datos[]={4,22,322,14,-5,67,7,9,8};
    int tam=sizeof(Datos)/sizeof(Datos[0]);//OBTENER EL TAMAÑO DEL VECTOR
    srand (time(NULL));
    for(int i=0;i<tam;i++)
    {
        //Datos[i] = rand()%11+1;
    }
    printf("DATOS DESORDENADOS:\n");
    for(int i=0; i<tam; i++)
    {
        printf("%d\n",Datos[i]);
    }
    Ordenar(tam,Datos);
    return 0;
}
//FUNCIONES
void Ordenar(int x, int arr[])
{
    int cont=0;
    int comp=0;
    for(int i=0; i<x; i++)
    {
        for(int j=0;j<x-1;j++)
        {
            comp+=1;//CUENTA COMPARACIONES
            if(arr[j]>arr[j+1])
            {
                int tmp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=tmp;
                cont++;//CUENTA LOS CAMBIOS
            }
        }
        printf("");
    }
    printf("DATOS ORDENADOS:\n");
    for(int i=0; i<x; i++)
    {
        printf("%d\n",arr[i]);
    }
    printf("NUMERO DE CAMBIOS:\n%d",cont);
    printf("\nNUMERO DE COMPARACIONES:\n%d",comp);
}

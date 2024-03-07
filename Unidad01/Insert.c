#include <stdio.h>
int main()
{
    int Datos[]={5,4,3,2,1};
    int t=sizeof(Datos)/sizeof(Datos[0]);
     printf("DATOS DESORDENADOS:\n");
    for(int i=0; i<t;i++)
    {
        printf("%d\t",Datos[i]);
    }
    int temp,j;
    for(int i=1; i<t;i++)
    {
        temp=Datos[i];
        for(j=i-1; j>=0 && temp<Datos[j]; j--)
        {
            Datos[j+1]=Datos[j];
        }
        Datos[j+1]=temp;
    }
    printf("\nDATOS ORDENADOS:\n");
    for(int i=0; i<t;i++)
    {
        printf("%d\t",Datos[i]);
    }
    return 0;
}

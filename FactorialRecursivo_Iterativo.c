#include <stdio.h>
//FUNCION PROTOTIPO
int Factorial(int x);
int FactorialIterativo(int x);
//CALCULA FACTORIAL ITERATIVO Y FIBONACCI PARA EL MAÑANA
int main()
{
    int n=5;
    printf("FACTORIAL RECURSIVO\n");
    printf("%d! es = %d\n",n,Factorial(n));
    printf("FACTORIAL ITERATIVO\n");//LA DEFINICION DE ITERATIVO NOS DICE QUE NECESITA BUCLES PARA EFECTUAR ALGUNA TAREA
    printf("%d! es = %d\n",n,FactorialIterativo(n));
    return 0;
}
int Factorial(int x)
{
    //CASO BASE
    if(x==0) return 1;
    //CASO GENERAR | CASO RECURSIVO
    return x*Factorial(x-1);
}
int FactorialIterativo(int x)
{
    if(x==0 || x==1) return 1;// EL FACTORIAL DE "0!" ES IGUAL A "1"
    int r=1;
    for(int i =1; i<=x;i++)
    {
        r*=i;
    }
    return r;
}
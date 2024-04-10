#include <stdio.h>
//FUNCION PROTOTIPO
int Factorial(int x);
//CALCULA FACTORIAL ITERATIVO Y FIBONACCI PARA EL MAÑANA
int main()
{
    int n=0;
    //Factorial(n,r);
    printf("%d! es = %d\n",n,Factorial(n));
    return 0;
}
int Factorial(int x)
{
    //CASO BASE
    if(x==0) return 1;
    //CASO GENERAR | CASO RECURSIVO
    return x*Factorial(x-1);
}

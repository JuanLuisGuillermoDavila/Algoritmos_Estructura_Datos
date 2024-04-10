#include <stdio.h>
//FUNCION PROTOTIPO
int Fibonacci(int x);
int main()
{
    int n=7;
    printf("Fibonacci de %d es = %d\n",n,Fibonacci(n));
    return 0;
}
//IMPLEMENTACION ¿COMO?
int Fibonacci(int x)
{
    //CASO BASE
    if(x==1) return 0;
    if(x==2) return 1;
    // CASO GENERAL | CASO RECURSIVO
    return Fibonacci(x-1)+Fibonacci(x-2);
}
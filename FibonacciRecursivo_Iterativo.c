#include <stdio.h>
//FUNCION PROTOTIPO
int Fibonacci(int x);
int FibonacciIterativo(int x);
int main()
{
    int n=7;
    printf("FACTORIAL RECORSIVO\n");
    printf("Fibonacci de %d es = %d\n",n,Fibonacci(n));
    printf("FACTORIAL ITERATIVO\n");
     printf("Fibonacci de %d es = %d\n",n,FibonacciIterativo(n));
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
int FibonacciIterativo(int x)
{
    if(x==1) return 0;
    if(x==2) return 1;
    int a = 0, b = 1, temp;
    for (int i = 2; i < x; i++) {
        temp = a + b;
        a = b;
        b = temp;
     }
    return b;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//FUNCIONES PROTOTIPO
int busquedaBinaria(int arr[], int j, int i, int d);
//TODO:
void llenarArreglo(int arr[],int size);
void printArray(int arr[], int size);
//ORDENAMIENTO MERGESORT
void merge(int arr[], int l, int m, int r);//MESCLA
void mergeSort(int arr[], int l, int r);//DIVIDE
int main()
{
    //int arr[]={1,2,3,4,5,6,7,8};
    //CREAREMOS UN ARREGLO PARA N DATOS
    srand (time(NULL));
    printf("TAMAÑO DEL ARREGLO:\n");
    int t=0;
    scanf("%d",&t);
    int arr[t];
    llenarArreglo(arr,t);
    printf("ARREGLO GENERADO:\n");
    printArray(arr,t);
    //PARA PODER REALIZAR UNA BUSQUEDA BINARIA PRIMERO TENEMOS QUE ORDENAR EL ARREGLO
    int j=0;
    int i=0;
    int d=t-1;
    mergeSort(arr,i,d);//ORDENAMIENTO MERGESORT
    printf("ARREGLO ORDENADO:\n");
    printArray(arr,t);
    printf("No. BUSQUEDA: \n");
    scanf("%d",&j);
    printf("LA POSICION DE %d ES: %d",j,busquedaBinaria(arr,j,i,d));
    return 0;
}
//FUNCIONES
int busquedaBinaria(int arr[], int j, int i, int d)
{
    int pos =-1;
    int m=(i+d)/2;
    //ESTAMOS POR CONSIDERAR UN CASO BASE
    if(arr[m]==j) return m;
    //PRIMER CASO GENERAL
    if (j>arr[m])pos=busquedaBinaria(arr,j,m+1,d);
    //SEGUNDO CASO GENERAL
    if (j<arr[m])pos=busquedaBinaria(arr,j,i,m);
    return pos;
}
void llenarArreglo(int arr[],int size)//TODO: METODO PARA LLENAR UN ARREGLO
{
    for(int i=0; i<size; i++)
    {
        arr[i] = rand()%7+1;
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}
void merge(int arr[], int l, int m, int r)
{
        int i, j, k;
    int n1 = (m - l) + 1;
    int n2 = r - m;
    // Create temp arrays
    int L[n1], R[n2];
    // Copy data to temp arrays
    // L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    // Merge the temp arrays back
    // into arr[l..r]
    // Initial index of first subarray
    i = 0;
    // Initial index of second subarray
    j = 0;
    // Initial index of merged subarray
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements
    // of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) //DETERMINA SI SE TIENE QUE SEGUIR DIVIDIENDO
    {
    // Same as (l+r)/2, but avoids
    // overflow for large l and r
    int m = l + (r - l) / 2;
    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
    }
}
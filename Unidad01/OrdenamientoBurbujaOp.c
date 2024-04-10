#include <stdio.h>

// Función para intercambiar dos elementos
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Función para implementar el ordenamiento burbuja optimizado
void optimizedBubbleSort(int arr[], int n, int *x, int *y) {
    int i, j;
    int swapped; // Variable para optimización

    for (i = 0; i < n-1; i++) {
        swapped = 0; // Inicialmente no se ha realizado ningún intercambio
        for (j = 0; j < n-i-1; j++) {
            (*y)++; // Incrementa el contador de comparaciones
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                (*x)++; // Incrementa el contador de intercambios
                swapped = 1; // Indica que se realizó un intercambio en esta pasada
            }
        }
        // Si no se realizó ningún intercambio en esta pasada, el arreglo ya está ordenado
        if (swapped == 0) {
            break;
        }
    }
}

// Función para imprimir un arreglo
void printArray(int arr[], int size, int x, int y) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("NUMERO DE CAMBIOS: %d\n", x);
    printf("NUMERO DE COMPARACIONES: %d\n", y);
}

// Programa principal
int main() {
    int cont = 0, comp = 0; // Inicializa los contadores con valores enteros
    int arr[] = {4, 22, 322, 14, -5, 67, 7, 9, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Arreglo original: \n");
    printArray(arr, n, cont, comp);
    optimizedBubbleSort(arr, n, &cont, &comp);
    printf("Arreglo ordenado en forma ascendente: \n");
    printArray(arr, n, cont, comp);
    //printf("\n");
    system("pause");
    return 0;
}

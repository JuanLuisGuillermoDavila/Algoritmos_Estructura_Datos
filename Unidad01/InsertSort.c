#include <stdio.h>

// Función para implementar el ordenamiento por inserción
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Mueve los elementos de arr[0..i-1], que son
           mayores que la llave, una posición adelante de su
           posición actual */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Función para imprimir un arreglo
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Programa principal
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original:\n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Arreglo ordenado en forma ascendente:\n");
    printArray(arr, n);
    system("\npause");
    return 0;
}

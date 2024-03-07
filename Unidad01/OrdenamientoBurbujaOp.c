#include <stdio.h>

// Programa principal
int main() {
    int cont = 0, comp = 0; // Inicializa los contadores con valores enteros
    int arr[] = {1,2,3,4,9,6,7,8,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Arreglo original: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("NUMERO DE CAMBIOS: %d\n", cont);
    printf("NUMERO DE COMPARACIONES: %d\n", comp);

    int i, j;
    int temp; // Variable temporal para el intercambio
    int swapped; // Variable para optimización

    for (i = 0; i < n-1; i++) {
        swapped = 0; // Inicialmente no se ha realizado ningún intercambio
        for (j = 0; j < n-i-1; j++) {
            comp++; // Incrementa el contador de comparaciones
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                cont++; // Incrementa el contador de intercambios
                swapped = 1; // Indica que se realizó un intercambio en esta pasada
            }
            printf("");
        }
        // Si no se realizó ningún intercambio en esta pasada, el arreglo ya está ordenado
        if (swapped == 0) {
            break;
        }
    }

    printf("Arreglo ordenado en forma ascendente: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("NUMERO DE CAMBIOS: %d\n", cont);
    printf("NUMERO DE COMPARACIONES: %d\n", comp);

    system("pause");
    return 0;
}


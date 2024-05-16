#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int *array;
    int size, i;

    // Solicitamos al usuario el tamaño del arreglo
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &size);

    // Asignamos memoria dinámicamente para el arreglo
    printf("Asignando memoria dinámica para un arreglo de %d enteros...\n", size);
    array = (int *)malloc(size * sizeof(int));

    // Verificamos si la asignación fue exitosa
    if (array == NULL) {
        printf("Error: No se pudo asignar memoria dinámica.\n");
        return 1; // Salimos del programa con código de error
    } else {
        printf("Memoria asignada correctamente.\n");
    }

    // Llenamos el arreglo con números aleatorios
    srand(time(NULL)); // Inicializamos la semilla para generar números aleatorios
    printf("\nLlenando el arreglo con números aleatorios...\n");
    for (i = 0; i < size; i++) {
        array[i] = rand() % 100; // Generamos un número aleatorio entre 0 y 99
    }
    printf("Arreglo llenado correctamente.\n");

    // Mostramos los elementos del arreglo
    printf("\nEl arreglo generado es:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Liberamos la memoria asignada para el arreglo
    printf("\nLiberando memoria asignada para el arreglo...\n");
    free(array);
    printf("Memoria liberada correctamente.\n");

    return 0;
}

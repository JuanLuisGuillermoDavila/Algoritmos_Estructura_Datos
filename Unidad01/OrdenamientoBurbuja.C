#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int Datos[] = {4, 22, 322, 14, -5, 67, 7, 9, 8};
    int tam = sizeof(Datos) / sizeof(Datos[0]);

    // Descomenta la siguiente línea si quieres generar números aleatorios en lugar de usar los datos predefinidos
    // srand(time(NULL));

    printf("DATOS DESORDENADOS:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d\n", Datos[i]);
    }

    int cont = 0;
    int comp = 0;

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam - 1; j++) {
            comp += 1;
            if (Datos[j] > Datos[j + 1]) {
                int tmp = Datos[j + 1];
                Datos[j + 1] = Datos[j];
                Datos[j] = tmp;
                cont++;
            }
        }
        printf("");
    }

    printf("\nDATOS ORDENADOS:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d\n", Datos[i]);
    }

    printf("NUMERO DE CAMBIOS:\n%d\n", cont);
    printf("NUMERO DE COMPARACIONES:\n%d\n", comp);

    return 0;
}

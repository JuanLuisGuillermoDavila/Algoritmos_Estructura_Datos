#include <stdio.h>
#include <string.h>
// FUNCIONES PROTOTIPO
void Codificar(char Texto[], int filas, int columnas);
void Decodificar(char Texto[], int filas, int columnas);
int main() {
    char Texto[] = "MARIOCARLOS";
    int filas = 2;
    int columnas = strlen(Texto) / filas;
    printf("TEXTO ORIGINAL: %s\n", Texto);
    Codificar(Texto, filas, columnas);
    printf("TEXTO CODIFICADO: %s\n", Texto);
    Decodificar(Texto, filas, columnas);
    printf("TEXTO DECODIFICADO: %s\n", Texto);
    return 0;
}
// FUNCIONES
void Codificar(char Texto[], int filas, int columnas) {
    char Matriz[filas][columnas];
    int x = 0;
    // LLENAR LA MATRIZ BIDIMENSIONAL
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            Matriz[i][j] = Texto[x++];
        }
    }
    // TRANSPONER LA MATRIZ (INTERCAMBIAR FILAS Y COLUMNAS)
    x = 0;
    for (int j = 0; j < columnas; j++) {
        for (int i = 0; i < filas; i++) {
            Texto[x++] = Matriz[i][j];
        }
    }
}
void Decodificar(char Texto[], int filas, int columnas) {
    char Matriz[filas][columnas];
    int x = 0;
    // LLENAR LA MATRIZ BIDIMENSIONAL
    for (int j = 0; j < columnas; j++) {
        for (int i = 0; i < filas; i++) {
            Matriz[i][j] = Texto[x++];
        }
    }
    // TRANSPONER LA MATRIZ DE NUEVO (INTERCAMBIAR FILAS Y COLUMNAS)
    x = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            Texto[x++] = Matriz[i][j];
        }
    }
}
/* Figura 10.3: fig10_03.c
02 Programa para barajar y repartir con el uso de estructuras */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Definición de la estructura carta */
struct carta {
    const char *cara; /* Define el apuntador cara */
    const char *palo; /* Define el apuntador palo */
};

typedef struct carta Carta; /* Nuevo tipo de nombre para la estructura baraja */

/* Prototipos */
void llenaMazo(Carta * const wMazo, const char * wCara[], const char * wPalo[]);
void barajar(Carta * const wMazo);
void repartir(const Carta * const wMazo);

int main() {
    Carta mazo[52]; /* Define el arreglo Carta */

    /* Inicializa el arreglo de apuntadores */
    const char *cara[] = { "As", "Dos", "Tres", "Cuatro", "Cinco", "Seis", 
    "Siete", "Ocho", "Nueve", "Diez", "Joto", "Quina", "Rey"};

    /* Inicializa el arreglo de apuntadores */
    const char *palo[] = { "Corazones", "Diamantes", "Treboles", "Espadas"};

    srand(time(NULL)); /* Randomizar */

    llenaMazo(mazo, cara, palo); /* Carga el mazo con las barajas */
    barajar(mazo); /* Coloca la Baraja en orden aleatorio */
    repartir(mazo); /* Reparte las 52 barajas */

    return 0; /* Indica terminación exitosa */
} /* Fin de main */

/* Coloca cadenas dentro de las estructuras Baraja */
void llenaMazo(Carta * const wMazo, const char * wCara[], const char * wPalo[]) {
    int i; /* Contador */

    /* Ciclo a través de wMazo */
    for (i = 0; i < 52; i++) {
        wMazo[i].cara = wCara[i % 13];
        wMazo[i].palo = wPalo[i / 13];
    } /* Fin de for */
} /* Fin de la función llenaMazo */

/* Baraja el mazo */
void barajar(Carta * const wMazo) {
    int i; /* Contador */
    int j; /* Variable para almacenar el valor aleatorio entre 0 - 51 */
    Carta temp; /* Define la estructura temporal para intercambiar cartas */

    /* Ciclo a través de wMazo para intercambiar aleatoriamente Baraja */
    for (i = 0; i < 52; i++) {
        j = rand() % 52;
        temp = wMazo[i];
        wMazo[i] = wMazo[j];
        wMazo[j] = temp;
    } /* Fin de for */
} /* Fin de la función barajar */

/* Reparte la baraja */
void repartir(const Carta * const wMazo) {
    int i; /* Contador */

    /* Ciclo a través de wMazo */
    for (i = 0; i < 52; i++) {
        printf("%5s de %-8s%c", wMazo[i].cara, wMazo[i].palo, (i + 1) % 2 ? '\t' : '\n');
    } /* Fin de for */
} /* Fin de la función repartir */

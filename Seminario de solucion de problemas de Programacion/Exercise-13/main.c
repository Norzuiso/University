/*
 * Enunciado: números positivos.

13.- Diseñar un programa que pida 10 números negativos y convertirlos a positivos.

 IMPRIMIR:
dichos números.

 * */
#include <stdio.h>
#include <math.h>

int main() {
int i = 1, num;
    do{
        printf("\nIngresa un numero entero negativo:");
        scanf("%i", &num);
        printf("\nN.%i.- |%i| = %i", i, num, abs(num));
        i++;
    }while(i <= 10);
    return 0;
}

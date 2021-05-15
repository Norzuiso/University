/*
 * Enunciado: números positivos.

16.- Diseñar un programa que pida 10 números negativos y convertirlos a positivos.

 IMPRIMIR:
dichos números.

 * */
#include <stdio.h>
#include <math.h>

int main() {
    int num=0;
    for(int i=0; i<10; i++){
        printf("\nIngresa un numero:");
        scanf("%i", &num);
        printf("\n%i", abs(num));
    }
    return 0;
}

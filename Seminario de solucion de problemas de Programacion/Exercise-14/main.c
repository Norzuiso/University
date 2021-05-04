/*
14.-Enunciado: “Tabla de Multiplicar”

Calcular e imprimir la tabla de multiplicar de un número cualquiera.

IMPRIMIR:

La tabla de multiplicar con:

a) el multiplicando,
b) el multiplicador y
c) el producto.
*/

#include <stdio.h>

int main() {
    int i = 1, num;
    printf("Ingresa un numero entero cualquiera:");
    scanf("%i", &num);
    do {
        printf("%i x %i = %i\n", num, i, num * i);
        i++;
    }while(i <=10);

    return 0;
}

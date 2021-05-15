/*
 *
Escriba un programa que lea un numero n, y escriba la tabla de multiplicar del número. Usando un bucle for.
 * */
#include <stdio.h>

int main() {
    int num;
    printf("Introduzca un numero: ");
    scanf("%i", &num);

    for (int i = 1; i <= 10; i++){
        printf("%i x %i = %i\n", i, num, num*i);
    }
    return 0;
}

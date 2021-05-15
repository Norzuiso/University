/*
 *
4. Escriba un programa que muestre la tabla de multiplicar del 1, 2, 3, 4, . . . 9.
De manera similar al anterior, pero ahora anidando dos bucles for, y sin leer ningún dato
 * */
#include <stdio.h>

int main() {
    for (int i = 1; i <= 10; i++){
        printf("\nTabla del %i\n", i);
        for (int j = 1; j <=10; ++j) {
            printf("%i x %i = %i\n", i, j, j*i);
        }
    }
    return 0;
}

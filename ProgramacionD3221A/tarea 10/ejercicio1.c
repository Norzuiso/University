/**
Josue Norberto Aguilar Islas
Code: 2168191282

 Tarea 10.-
1. Construye un programa que, al recibir como datos un arreglo unidimensional de máximo
20 elementos de tipo entero, permita ingresar números de tipo entero,
determine cuántas veces se encuentra este número dentro del arreglo.
 **/

#include <stdio.h>

static const int size = 5;

int main() {

    int numbers[size], num, count = 0;

    for (int i = 1; i <= size; i++) {
        printf("Ingresa el elemento %i del arreglo: ", i);
        scanf("%i", &numbers[i]);
    }

    printf("Ingresa el numero que se va a buscar en el arreglo: ");
    scanf("%i", &num);

    for (int i = 0; i < size; i++) {
        if (num== numbers[i]){
            count++;
        }
    }
    printf("El %i se encuentra %i en el arreglo", num, count);
    return 0;
}


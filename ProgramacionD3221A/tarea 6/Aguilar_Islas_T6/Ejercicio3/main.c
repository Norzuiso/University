//
// Created by josue on 4/27/2021.
//
//
// Created by josue on 4/27/2021.
//
/*
3. Encontrar la suma de un conjunto de números enteros, sin saber previamente cuantos números
se ingresaran, el programa finalizara cuando ingresemos un cero (0).
El programa al finalizar de ingresar valores, nos mostrara la cantidad de números ingresados,
así como la suma de los números.

 * */
#include <stdio.h>


int main() {
    int sum=0,temp=1, cont=0;
    while(temp !=0){
        printf("Ingresa un numero entero(0 para finalizar): ");
        scanf("%i", &temp);
        sum+=temp;
        cont++;
    }
    printf("%i numeros ingresados\n", cont);
    printf("La suma es de %i", sum);

}


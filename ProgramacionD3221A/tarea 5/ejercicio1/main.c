//
// Created by josue_aguilar on 22/04/2021.
//

/*
 1. Escribir un programa usando switch.
Mostrar un men ́u de opciones, (Usen colores para personalizar su practica)
• 1. Suma
• 2. Resta
• 3. Multiplicaci ́on
• 4. Divisi ́on.

Donde al ingresar dos n ́umeros enteros, calcular la suma, resta, multiplicaci ́on y divisi ́on, dependi-
endo de la opci ́on elegida.
 *
 */

#include <stdio.h>
#include <math.h>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

int main(void) {
    int opt;
    float  num1, num2;
    printf(CYN "Bienvenido!\n"
           "[1] Suma\n"
           "[2] Resta\n"
           "[3] Multiplicación\n"
           "[4] División\n");
    scanf("%i", &opt);
    switch (opt) {
        case 1:
            printf("---> Suma");
            printf("\nIngresa 2 numeros: ");
            scanf("%f, %f", &num1, &num2);
            printf("El resultado es: %.2f + %.2f = %.2f", num1, num2, num1+num2);
            break;
        case 2:
            printf("---> Resta");
            printf("\nIngresa 2 numeros: ");
            scanf("%f, %f", &num1, &num2);
            printf("El resultado es: %.2f - %.2f = %.2f", num1, num2, num1-num2);
            break;
        case 3:
            printf("---> Multiplicación");
            printf("\nIngresa 2 numeros: ");
            scanf("%f, %f", &num1 &num2);
            printf("El resultado es: %.2f * %.2f = %.2f", num1, num2, num1*num2);
            break;
        case 4:
            printf("---> Disvisión");
            printf("\nIngresa 2 numeros: ");
            scanf("%f, %f", &num1, &num2);
            printf("El resultado es: %.2f / %.2f = %.2f", num1, num2, num1/num2);
            break;
        default:
            printf("Opción incorrecta, nos vemos luego :c");
            break;
    }

}

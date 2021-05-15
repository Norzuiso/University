//
// Created by josue_aguilar on 22/04/2021.
//

/*
2. Escribir un programa usando switch.
en el tendr ́an el siguiente men ́u de opciones.
1. Ingresa tres n ́umeros, calcular su promedio.
Si el promedio es  ́unicamente mayor a 50 mostrarlo. Si no colocar un mensaje que diga, el
promedio es menor que 50
2. Dados los coeficientes de la ecuaci ́on de segundo grado, determinar si las ra ́ıces son reales o
complejas. (Nota: Verifique el valor del discriminante).
3. Comparaci ́on de cadenas de caracteres.
Comparar dos cadenas usando la funci ́on srtcmp y usando las variables cad1 y cad2 y regresar
el resultado usando la variable de tipo entero llamada resultado. El valor que regresa la funci ́on
srtcmp tiene tres opciones:
• Si el valor retornado es cero entonces las cadenas son iguales
• si el valor retornado es menor que cero, entonces la cad1 es menor que la cad2.
• Si el valor retornado es mayor que cero, entonces la primer cadena (cad1 es mayor que la
segunda cad2).
 *
 */
#include<stdio.h>
#include <string.h>

int main() {
    switch (showMenu()) {
        case 1:
            promedioTresNumeros();
            break;
        case 2:
            raicesComplejas();
            break;
        case 3:
            compareStrings();
            break;
    }
    return 0;
}
int showMenu(){
    int opt;
    printf("1. Ingresa tres n ́umeros, calcular su promedio."
           "\n2. Dados los coeficientes de la ecuaci ́on de segundo grado,\n\t determinar si las ra ́ıces son reales o\n"
           "complejas\n3. Comparaci ́on de cadenas de caracteres.\n");
    scanf("%d", &opt);
    return opt;
}
int promedioTresNumeros(){
    float num1, num2, num3, res;
    printf("Ingresa los 3 numeros: ");
    scanf("%f %f %f", &num1, &num2, &num3);
    res = (num1 + num2 + num3)/3;
    if(res < 50){
        printf("Promedio menor que 50");
    }else{
        printf("El promedio es: %.2f", res);
    }
    return 0;
}
int raicesComplejas(){
    double a, b, c, d, sqrtA, sqrtB, sqrtC, sqrtD;
    printf("\nIngresa los valores de a, b y c: ");
    scanf("%d %d %d", &a, &b, &c);
    d = b*b-4*a*c;

    if (d < 0){
        printf("\nLas raices son complejas");
    } else{
        printf("\nLas raices de la ecuación son reales");
        sqrtA = sqrt(a);
        sqrtB = sqrt(b);
        sqrtC = sqrt(c);
        sqrtD = sqrt(d);
        if(sqrtA <=0){
            printf("\na es una raiz compleja");
        }
        if(sqrtB <=0){
            printf("\nb es una raiz compleja");
        }
        if (sqrtC <=0){
            printf("\nc es una raiz compleja");
        }
        if (sqrtD <=0){
            printf("\nd es una raiz compleja");
        }
    }
    return 0;
}
int compareStrings(){
    char word1[50], word2[50];
    printf("\nIngresa 2 cadenas caracteres: ");
    scanf("%s %s", word1, word2);
    if(strcmp(word1, word2)==0){
        printf("\nLas cadenas de caracteres son iguales");
    } else {
        printf("\nLas cadenas de caracteres son diferentes");
    }
    return 0;
}
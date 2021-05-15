/*
 *
Programa_18:

Enunciado:

Diseñar un programa con la estructura “do…while”,

Que imprima la palabra “Hola”,
y pregunte lo siguiente:

¿Deseas que se vuelva a imprimir la palabra?
 Presione 1 para si
2 para no

Nota: ver video de esta estructura para codificarlo.

	IMPRIMIR:
Hola (cuantas veces se desee)



 * */

#include <stdio.h>

int main() {
    int num= 1, option;
    do{
        printf("HOLA!\n");
        printf("\nDeseas que se vuelva a imprimir la palabra?");
        printf("\nPresione 1 para si\n\t2 para no");
        scanf("%i", &option);
        if(option == 2){
            num=2;
        }
    }while(num==1);
    return 0;
}

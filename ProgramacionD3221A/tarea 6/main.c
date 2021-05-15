//
// Created by josue on 4/27/2021.
//
/*
4. Escribir un programa similar al anterior, donde ingresaremos numeros enteros, y finalizaremos
al ingresar un cero (0)
El programa al finalizar de ingresar valores, nos mostrara el mayor numero ingresado.
Pueden utilizar los temas vistos anteriormente

 * */
#include <stdio.h>


int main() {
int num=0,temp=1;
while(temp !=0){
    printf("Ingresa un numero entero(0 para finalizar): ");
    scanf("%i", &temp);
    if(num<temp){
        num=temp;
    }
}
printf("El mayor es %i", num);

}

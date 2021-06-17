/**
Josue Norberto Aguilar Islas
Code: 2168191282

Programa_29: Llamado de Funciones.
Enunciado:

Diseñar un programa con un “poema”, agregando 10 funciones sin parámetros.
Llamado de funciones anidadas o llamado de funciones en forma automática


Nota: Los fragmentos deben estar desordenados y en el momento que se impriman deben estar en orden.


Era mi corazon un ala viva y turbia
y pavorosa ala de anhelo.

Era primavera sobre los campos verdes.
Azul era la altura y era esmeralda el suelo.

Ella -la que me amaba- se murio en primavera.
Recuerdo aún sus ojos de paloma en desvelo.

Ella -la que me amaba- cerro los ojos. Tarde.
Tarde de campo, azul. Tarde de alas y vuelos.

Ella -la que me amaba- se murio en primavera.
Y se llevo la primavera al cielo.


 **/

#include <stdio.h>


void verso1();

void verso10();

void verso7();

void verso6();

void verso2();

void verso9();

void verso4();

void verso8();

void verso5();

void verso3();

int main() {
    verso1();
    verso2();
    verso3();
    verso4();
    verso5();
    verso6();
    verso7();
    verso8();
    verso9();
    verso10();


    return 0;
}

void verso3() { printf("Era primavera sobre los campos verdes.\n"); }

void verso5() { printf("Ella -la que me amaba- se murio en primavera.\n"); }

void verso8() { printf("Tarde de campo, azul. Tarde de alas y vuelos.\n"); }

void verso4() { printf("Azul era la altura y era esmeralda el suelo.\n"); }

void verso9() { printf("Ella - la que me amaba - se murio en primavera.\n"); }

void verso2() { printf("y pavorosa ala de anhelo.\n"); }

void verso6() { printf("Recuerdo aun sus ojos de paloma en desvelo.\n"); }

void verso7() { printf("Ella -la que me amaba- cerro los ojos. Tarde.\n"); }

void verso10() { printf("Y se llevo la primavera al cielo.\n"); }

void verso1() { printf("Era mi corazon un ala viva y turbia\n"); }

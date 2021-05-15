//
// Created by josue_aguilar on 22/04/2021.
//

/*
Escribir un programa usando switch.
Para el c ́alculo de la tasa metab ́olica basal, de mujeres y hombres. Para despu ́es calcular las
calor ́ıas diarias recomendadas, dependiendo de la actividad realizada.
(a) Utilizar switch para el primer menu, una vez ingresado a la opcion a o b, pedir los datos
para el peso(en kg), altura(en cm) y a ̃nos
(b) Realizar el calculo de la TMB (tasa metabolica basal) una vez realizado el calculo
(c) Utilizar un switch dentro de cada uno de los dos casos anteriores(switch anidado) para tener
un menu con cinco opciones en las que clasificaremos la actividad diaria realizada, y con
base a eso calcular las calorias diarias recomendadas.
(d) utilizar las siguientes ecuaciones para TMB y para las calor ́ıas diarias recomendadas.
 *
 */
#include<stdio.h>
#include <string.h>

int main() {
    char opt;
    float kg, altura, edad, tmb;
    printf("Las ecuaciones de Harris - Benedict revisadas por Mifflin y St Jeor en 1990 ,\n"
           "para el calculo de la tasa metabolica basal :\n"
           "A) TMB en hombres\n"
           "B) TMB en mujeres\n"
           "Ingresa una opcion : ");
    scanf("%c", &opt);

    printf("\nIngresa tu peso en kg : ");
    scanf("%i", &kg);
    printf("\nIngresa tu altura en cm : ");
    scanf("%i", &altura);
    printf("\nIngresa tu edad en a%cos : ", 164);
    scanf("%i", &edad);

    switch (opt) {
        case 'a':
            tmb= tmbHombres(kg, altura, edad);
            showMenuCalories(tmb);
            break;
        case 'b':
            tmb = tmbMujeres(kg, altura, edad);
            showMenuCalories(tmb);
            break;
        default:
            printf("Opción erronea :c");
            break;
    }

    return 0;
}

int showMenuCalories(float tmb){
    int opt;
    printf("Ingesta diaria de calorias recomendada\n"
           "Dependiendo de la actividad diaria realizada\n"
           "1. Poco o ningun ejercicio\n"
           "2. Ejercicio ligero (1 -3 dias a la semana )\n"
           "3. Ejercicio moderado (3 -5 dias a la semana )\n"
           "4. Ejercicio fuerte (6 -7 dias a la semana )\n"
           "5. Ejercicio muy fuerte ( dos veces al dia , entrenamientos muy duros )\n"
           "Elige una opción: ");
    scanf("%i", &opt);
    switch (opt) {
        case 1:
            diaryCalories(tmb, 1.2);
            break;
        case 2:
            diaryCalories(tmb, 1.375);
            break;
        case 3:
            diaryCalories(tmb, 1.55);
            break;
        case 4:
            diaryCalories(tmb, 1.725);
            break;
        case 5:
            diaryCalories(tmb, 1.9);
            break;
        default:
            printf("Opción invalida, nos vemos");
            break;
    }
}
int diaryCalories(float tmb, float value){
    printf("\nTasa metabolica es : %f", tmb);
    printf("\nCalorias diarias recomendadas : %f", tmb * value );

}
float tmbHombres(int kg, int altura, int edad){
    float tmb;
    tmb = (10 * kg) + (6.25 + altura) - (5 * edad) + 5;
    return tmb;
}

float tmbMujeres(int kg, int altura, int edad){
    tmb = (10 * kg) + (6.25 + altura) - (5 * edad) - 161;

    return tmb;
}

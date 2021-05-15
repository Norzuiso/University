/*
 *
5. Hacer un programa que implemente el juego del número secreto.
La computadora genera un número entre 1 y 50, y usted tiene que acertar el numero. Cuando
usted ingresa un numero, la computadora le dirá si el numero ingresado es mayor o menor al
numero escondido.
Tendrá la opción de elegir cuantas veces quiere intentar adivinar el numero. Y una vez terminados
los intentos, si adivino el numero, aparecerá el mensaje (Felicidades lo lograste en x intentos)
en caso contrario, (suerte para la próxima...)
Tip: Usar las funciones rand y srand así como la librería time.h así como if-else y do-while
 * */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum { F, T } boolean;

int main() {
    srand(time(NULL));
    boolean isCorrect = F;
    int number = rand() % 50, tryNums, counterTries = 1, guess;

    printf("Cuantos intentos quieres tener?\n");
    scanf("%i", &tryNums);
    do{
        printf("Ingresa numero entero (inteto %i) = ", counterTries);
        scanf("%i", &guess);
        if (number < guess){
            printf("Tu numero es mayor al mio\n");
        }else if (number > guess){
            printf("Tu numero es menor al mio\n");
        }
        if(tryNums == counterTries){
            printf("\nLastima, perdiste. Suerte para la proxima.\n");
            isCorrect = T;
        }
        if(guess == number){
            printf("\n ¡Felicidades!\n Adivinaste el numero! :D\n");
            isCorrect = T;
            counterTries--;
        }
        counterTries++;
    }while(isCorrect == F);
    printf("Utilizaste %i intentos", counterTries);
    return 0;
}

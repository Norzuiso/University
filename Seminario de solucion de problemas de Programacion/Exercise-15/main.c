/*
 *
Programa_15:

Enunciado: Clave de acceso con while.

Diseñar un programa con la estructura “while”,
Que pida la clave de acceso (123):
y si es correcta que
imprima la palabra “Hola”,
si no es correcta
que escriba la frase “su clave es incorrecta vuelva a intentarlo”



	IMPRIMIR:
Si es verdadera
“Hola”, o
Si es falsa
“su clave es incorrecta vuelva a intentarlo”.

 *
 * */
#include <stdio.h>

char password[10] = "123";

int main() {
    char passTry[255];
    int isPassTryCorrect;
    do{

        printf("Inlgresa tu contraseña de acceso: ");
        scanf("%s", passTry);
        isPassTryCorrect = strcmp(passTry, password);
        if(isPassTryCorrect == 0){
            printf("\nHola\n");
        }else{
            printf("\nContraseña incorrecta, intenta de nuevo\n");
        }
    }while(isPassTryCorrect != 0);

    return 0;
}

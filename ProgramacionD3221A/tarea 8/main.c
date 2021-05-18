    /**

    Instrucciones
    1. Escribir los siguientes programas usando funciones sin paso de parámetros. Las funciones estarán en el siguiente menú, agregar un ciclo (do-while) para que se mantenga repitiendo,
    pueden usar todo lo que hemos visto anteriormente:
    --------------------------------
    1. Mayor de 3 numeros
    2. Potencia
    3. funcion 1
    4. funcion 2
    5. funcion 3
    6. funcion factorial
    0. Salir
    Elige una opcion:

     * */

    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>

    typedef enum {
        F, T
    } boolean;

    boolean booleanMenu = T;
    static char *const line = "\n--------------------------------\n";
    static char *const menu = "--------------------------------\n"
                              "1. Mayor de 3 numeros\n"
                              "2. Potencia\n"
                              "3. funcion 1\n"
                              "4. funcion 2\n"
                              "5. funcion 3\n"
                              "6. funcion factorial\n"
                              "0. Salir\n"
                              "Elige una opcion:";

    void clearScreen();

    void defaultOption();

    boolean case0Exit();

    void greaterOf3Numbers();

    void powNumber();

    void function1();

    void function2();

    void function3();

    void functionFactorial();

    void continueInMenu();

    int main() {
        char menuOption = 0;
        do {
            printf("%s", menu);
            scanf("%c", &menuOption);
            switch (menuOption) {
                case '0':
                    booleanMenu = case0Exit();
                    clearScreen();
                    continueInMenu();
                    break;
                case '1':
                    greaterOf3Numbers();
                    clearScreen();
                    continueInMenu();
                    break;
                case '2':
                    powNumber();
                    clearScreen();
                    continueInMenu();
                    break;
                case '3':
                    function1();
                    clearScreen();
                    continueInMenu();
                    break;
                case '4':
                    function2();
                    clearScreen();
                    continueInMenu();
                    break;
                case '5':
                    function3();
                    clearScreen();
                    continueInMenu();
                    break;
                case '6':
                    functionFactorial();
                    clearScreen();
                    continueInMenu();
                    break;
                default:
                    defaultOption();
                    clearScreen();
                    break;
            }
        } while (booleanMenu == T);
        return 0;
    }

    void continueInMenu() {
        printf("Deseas volver a ingresar al menu (s - si ) (n - no ):");
        char answer = 'a';
        scanf("%c", &answer);
        if (answer == 's' || answer == 'S') {
            booleanMenu = T;
        } else if (answer == 'n' || answer == 'N') {
            booleanMenu = F;
        } else {
            printf("Opcion erronea :c");
        }
    }

    void functionFactorial() {
        printf("Opcion 6 %s", line);
        int num, factor = 1;
        printf("Ingresa un numero entero positivo:");
        scanf("%i", &num);
        for (int i = 1; i <= num; i++) {
            factor *= i;
        }
        printf("%i! es %i\n", num, factor);
    }

    void function3() {
        printf("Opcion 5 %s", line);
        int numRows = 0, aux = 0, x = 0;
        printf("Ingresa el numero de filas: ");
        scanf("%i", &numRows);
        for (int i = 1; i <= numRows; i++) {
            x++;
            printf("\n%i", x);
            aux = i;
            for (int j = 1; j < aux; j++) {
                x++;
                printf("\t%i", x);
            }
        }
        printf("\n");
    }

    void function2() {
        printf("Opcion 4 %s", line);
        int num = 0, aux = 0;
        printf("Ingresa un numero entero: ");
        scanf("%i", &num);
        for (int i = 1; i <= num; i++) {
            printf("\n%i", i);
            aux = i;
            for (int j = 1; j < aux; j++) {
                printf("\t%i", i);
            }
        }
        printf("\n");
    }

    void function1() {
        printf("Opcion 3 %s", line);
        int num = 0, aux = 0, x;
        printf("Ingresa un numero entero:");
        scanf("%i", &num);
        for (int i = 0; i < num; i++) {
            aux = num;
            printf("%i", aux);
            x = i;
            for (int j = 0; j < x; j++) {
                aux--;
                printf("%i", aux);
            }
            printf("\n");
        }
    }

    void powNumber() {
        float num = 0;
        int exp = 0;
        printf("Opcion 2 - Potencia de un numero %s", line);
        printf("Potencia de un numero:");
        scanf("%f", &num);
        printf("Ingresa el exponente entero: ");
        scanf("%d", &exp);
        float result = pow(num, exp);
        printf("%.2f elevado a %i es %.2f\n", num, exp, result);
    }

    void greaterOf3Numbers() {
        int number;
        int aux;
        printf("Opcion 1 %s", line);
        for (int i = 0; i < 3; i++) {
            printf("Ingresa un number: ");
            scanf("%i", &number);
            if (aux < number) {
                aux = number;
            }
            printf("\nEl number mayor es %d\n", aux);
        }
    }

    boolean case0Exit() {
        printf("Opcion 0 %s", line);
        printf("Gracias por usar mi programa <3\n");
        return F;
    }

    void defaultOption() {
        printf("Opcion invalida, intenta de nuevo\n");
    }

    void clearScreen() {
        system("PAUSE");
        system("clear");
    }

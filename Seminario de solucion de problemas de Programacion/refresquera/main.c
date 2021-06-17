/**
 *
Proyecto final “Base de datos - Refresquera el amigo”.
16/06/2021
Aguilar Islas Josue Norberto.
01.
D09.
Martes y jueves de  7-9 pm.
42749.
I5883.
Seminario de solución de problemas de programación.


 INSTRUCCIONES:
Terminar el código, el programa “Base de datos Refresquera”, con registros, en el programa principal tendrá cuatro funciones,
        Capturar,
        Mostrar,
        Buscar
        Salir

  _____  ______ ______ _____  ______ ____  _    _ ______ _____               ______ _                 __  __ _____ _____  ____
 |  __ \|  ____|  ____|  __ \|  ____/ __ \| |  | |  ____|  __ \    /\       |  ____| |          /\   |  \/  |_   _/ ____|/ __ \
 | |__) | |__  | |__  | |__) | |__ | |  | | |  | | |__  | |__) |  /  \      | |__  | |         /  \  | \  / | | || |  __| |  | |
 |  _  /|  __| |  __| |  _  /|  __|| |  | | |  | |  __| |  _  /  / /\ \     |  __| | |        / /\ \ | |\/| | | || | |_ | |  | |
 | | \ \| |____| |    | | \ \| |___| |__| | |__| | |____| | \ \ / ____ \    | |____| |____   / ____ \| |  | |_| || |__| | |__| |
 |_|  \_|______|_|    |_|  \_|______\___\_\\____/|______|_|  \_/_/    \_\   |______|______| /_/    \_|_|  |_|_____\_____|\____/



**/

#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <Windows.h>

static char *const WELCOME_MESSAGE = "Bienvenido a la refresquera el amigo\n\n";

static char *const PASSWORD = "1234";

enum Colors { // Listado de colores (La letra "L" al inicio, indica que es un color más claro que su antecesor).
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LGREY = 7,
    DGREY = 8,
    LBLUE = 9,
    LGREEN = 10,
    LCYAN = 11,
    LRED = 12,
    LMAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
};

enum Vowels {
    ASCII_A_CODE = 160,
    ASCII_E_CODE = 130,
    ASCII_I_CODE = 161,
    ASCII_O_CODE = 162,
    ASCII_U_CODE = 163,

};

void showMenu();
void Color(int Background, int Text);

int main() {

    do {
        Color(BLACK, WHITE);
        printf("Ingresa la contraseña para continuar: ");
        scanf("%s", &tryPassword);
        printf(tryPassword);

        if(tryPassword == PASSWORD){
            Color(WHITE, GREEN);
            printf(WELCOME_MESSAGE);
            showMenu();
        }else{
            Color(WHITE, RED);
            printf("Contraseña incorrecta, intenta de nuevo\n");
            tryPassword="";
        }
        printf(tryPassword);
    }while(tryPassword != PASSWORD);
    return 0;
}

void showMenu() {
    char opt;
    Color(WHITE, BLACK);
    printf("\n\t\tMen%c\t\n\n",ASCII_U_CODE);
    printf("\t1.- Capturar\n\t2.- Mostrar\n\t3.- Buscar\n\t4.- Salir\n\nElige una Opci%cn:", ASCII_O_CODE);
    scanf("%c", &opt);
    Color(BLACK, WHITE);
    switch(opt){
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        default:
            break;
    }
}

void Color(int Background, int Text){
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    int    New_Color= Text + (Background * 16);
    SetConsoleTextAttribute(Console, New_Color | BACKGROUND_INTENSITY);
}
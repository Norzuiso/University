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
#include <string.h>

static char *const WELCOME_MESSAGE = "\n\n\tBienvenido a la refresquera el amigo\n\n";

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
    ASCII_N_TILDE_CODE = 164,

};

void showMenu();

void Color(int Background, int Text);

void access();

void clearScreen();

void options(int opt);

void gotoxy(int x, int y);

void capturarRefresco();

void mostrarRefresco();

void buscarRefresco();

void mostrarProvedor();

void capturarProvedor();

void buscarProvedor();

int checkIfIsProvOrRefr();

struct refrescos {
    char code[20];
    char nombre[20];
    char presentation[20];
    char volumen[10];
    char color[15];
    char sabor[25];
    char precio_al_publico[15];
    char precio_proveedor[15];
    char observaciones[50];
} refres[10];


struct provedor {
    char code[20];
    char name[50];
    char companyName[50];
    char street[255];
    char neighborhood[50];
    char zipCode[10];
    char country[50];
    char rfc[20];
    char phone[10];
    char refrescoCode[20];
    char observaciones[50];
} prov[10];

int main() {
    Color(WHITE, BLACK);
    clearScreen();
    access();
    return 0;
}

void access() {
    char tryPassword[4];
    int i = 4;
    do {
        gotoxy(3, i);
        Color(WHITE, BLACK);
        printf("Ingresa la contrase%ca para continuar: ", ASCII_N_TILDE_CODE);
        scanf("%s", &tryPassword);

        if (strcmp(tryPassword, "123") == 0) {
            showMenu();
        } else {
            Color(WHITE, RED);
            gotoxy(3, 3);
            printf("\nContrase%ca incorrecta, intenta de nuevo\n", ASCII_N_TILDE_CODE);
            strcpy(tryPassword, "");
        }
        clearScreen();
        i++;
    } while (strcmp(tryPassword, "123") != 0);
}

void showMenu() {
    clearScreen();
    Color(WHITE, GREEN);
    printf("%s", WELCOME_MESSAGE);

    int opt;
    do {
        Color(WHITE, BLUE);
        printf("\n\t\tMen%c\t\n\n", ASCII_U_CODE);
        printf("\t1.- Capturar\n\t2.- Mostrar\n\t3.- Buscar\n\t4.- Salir\n\n\tElige una Opci%cn:", ASCII_O_CODE);
        scanf("%i", &opt);
        options(opt);
    } while (opt != 4);
}

void options(int opt) {
    int provOrRef;

    switch (opt) {
        case 1:
            provOrRef = checkIfIsProvOrRefr();
            if (provOrRef == 1) {
                capturarProvedor();
            } else {
                capturarRefresco();
            }
            break;
        case 2:
            provOrRef = checkIfIsProvOrRefr();
            if (provOrRef == 1) {

                mostrarProvedor();
            } else {
                mostrarRefresco();
            }

            break;
        case 3:
            provOrRef = checkIfIsProvOrRefr();

            if (provOrRef == 1) {

                buscarProvedor();
            } else {

                buscarRefresco();
            }

            break;
        case 4:
            printf("\n\nGracias por usar :D\n");
            break;
        default:
            printf("Opcion incorrecta, intenta de nuevo");
            break;
    }
    clearScreen();
}

int checkIfIsProvOrRefr() {
    int proOrRef;

    printf("\n\t\tProvedor o Refresco? \n\n");
    printf("\t\n(1)provedor \n(2)refresco\n");
    scanf("%i", &proOrRef);
    if (proOrRef == 2) {
        return proOrRef;
    } else if (proOrRef == 1) {
        return proOrRef;

    } else {
        printf("\n\nOpci%cn Incorrecta, intenta de nuevo por favor\n", ASCII_O_CODE);
        clearScreen();
        showMenu();
    }
}


void capturarProvedor() {
    clearScreen();
    printf("\n\n\t\tCapturar provedor\n\n");
    for (int i = 0; i <= 10; i++) {
        if (strcmp(prov[i].code, "") == 0) {
            printf("\n\tCodigo: %i", i);
            itoa(i, prov[i].code, 10);
            printf("\n\tNombre:");
            scanf("%s", prov[i].name);
            printf("\n\t Compañia:");
            printf("\n\t\t Nombre de la compañia:");
            scanf("%s", prov[i].companyName);
            printf("\n\t\t  Calle:");
            scanf("%s", prov[i].street);
            printf("\n\t\t  Colonia:");
            scanf("%s", prov[i].neighborhood);
            printf("\n\t\t   Codigo postal: ");
            scanf("%s", prov[i].zipCode);
            printf("\n\t\t  Pais: ");
            scanf("%s", prov[i].country);
            printf("\n\t\t RFC: ");
            scanf("%s", prov[i].rfc);
            printf("\n\t\t Telefono: ");
            scanf("%s", prov[i].phone);
            printf("\n\tCodigo de refresco: ");
            scanf("%s", prov[i].refrescoCode);
            printf("\n\tObservaciones:");
            scanf("%s", prov[i].observaciones);
        }
    }
}

void capturarRefresco() {
    clearScreen();
    printf("\n\n\t\tCapturar refresco\n\n");
    for (int i = 0; i <= 10; i++) {
        if (strcmp(refres[i].code, "") == 0) {
            printf("\n\tCodigo: %i", i);
            itoa(i, refres[i].code, 10);
            printf("\n\tNombre:");
            scanf("%s", refres[i].nombre);
            printf("\n\tPresentaci%cn:", ASCII_O_CODE);
            scanf("%s", refres[i].presentation);
            printf("\n\tVolumen:");
            scanf("%s", refres[i].volumen);
            printf("\n\tColor:");
            scanf("%s", refres[i].color);
            printf("\n\tSabor:");
            scanf("%s", refres[i].sabor);
            printf("\n\t Precio Al Publico:");
            scanf("%s", refres[i].precio_al_publico);
            printf("\n\t Precio al provedor:");
            scanf("%s", refres[i].precio_proveedor);
            printf("\n\t Observaciones:");
            scanf("%s", refres[i].observaciones);
        }
    }
}

void mostrarProvedor() {
    clearScreen();
    printf("\n\n\t\tCapturar provedor\n\n");
    for (int i = 0; i <= 10; i++) {
        printf("\n\tCodigo: %s", prov[i].code);
        printf("\n\tNombre:%s", prov[i].name);
        printf("\n\t Compañia:");
        printf("\n\t\t Nombre de la compañia:%s", prov[i].companyName);
        printf("\n\t\t  Calle:%s", prov[i].street);
        printf("\n\t\t  Colonia:%s", prov[i].neighborhood);
        printf("\n\t\t   Codigo postal: %s", prov[i].zipCode);
        printf("\n\t\t  Pais: %s", prov[i].country);
        printf("\n\t\t RFC: %s", prov[i].rfc);
        printf("\n\t\t Telefono: %s", prov[i].phone);
        printf("\n\tCodigo de refresco: %s", prov[i].refrescoCode);
        printf("\n\tObservaciones:%s", prov[i].observaciones);
    }
}

void mostrarRefresco() {
    clearScreen();
    printf("\n\n\t\tMostrar refresco\n\n");
    for (int i = 0; i <= 10; i++) {
        printf("\n\tCodigo: %s", refres[i].code);
        printf("\n\tNombre:%s", refres[i].nombre);
        printf("\n\tPresentaci%cn:%s", ASCII_O_CODE, refres[i].presentation);
        printf("\n\tVolumen:%s", refres[i].volumen);
        printf("\n\tColor:%s", refres[i].color);
        printf("\n\tSabor:%s", refres[i].sabor);
        printf("\n\t Precio Al Publico:%s", refres[i].precio_al_publico);
        printf("\n\t Precio al provedor:%s", refres[i].precio_proveedor);
        printf("\n\t Observaciones:%s", refres[i].observaciones);
    }

}

void buscarRefresco() {
    clearScreen();
    int i;
    printf("\n\n\t\tBuscar refresco\n\n");
    printf("\n\n\tIngresa el codigo del refresco a buscar:");
    scanf("%i", &i);

    printf("\n\t\tCodigo: %s", refres[i].code);
    printf("\n\t\tNombre:%s", refres[i].nombre);
    printf("\n\t\tPresentaci%cn:%s", ASCII_O_CODE, refres[i].presentation);
    printf("\n\t\tVolumen:%s", refres[i].volumen);
    printf("\n\t\tColor:%s", refres[i].color);
    printf("\n\t\tSabor:%s", refres[i].sabor);
    printf("\n\t \tPrecio Al Publico:%s", refres[i].precio_al_publico);
    printf("\n\t\t Precio al provedor:%s", refres[i].precio_proveedor);
    printf("\n\t\t Observaciones:%s", refres[i].observaciones);
    clearScreen();

}

void buscarProvedor() {
    int i;
    clearScreen();
    printf("\n\n\t\tBuscar provedor\n\n");
    printf("\n\n\tIngresa el codigo del provedor a buscar:");
    scanf("%i", &i);

    printf("\n\t\tCodigo: %s", prov[i].code);
    printf("\n\t\tNombre:%s", prov[i].name);
    printf("\n\t \tCompañia:");
    printf("\n\t\t \tNombre de la compañia:%s", prov[i].companyName);
    printf("\n\t\t  \tCalle:%s", prov[i].street);
    printf("\n\t\t  \tColonia:%s", prov[i].neighborhood);
    printf("\n\t\t \t  Codigo postal: %s", prov[i].zipCode);
    printf("\n\t\t\t  Pais: %s", prov[i].country);
    printf("\n\t\t\t RFC: %s", prov[i].rfc);
    printf("\n\t\t\t Telefono: %s", prov[i].phone);
    printf("\n\t\tCodigo de refresco: %s", prov[i].refrescoCode);
    printf("\n\t\tObservaciones:%s", prov[i].observaciones);
}

void Color(int Background, int Text) {
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    int New_Color = Text + (Background * 16);
    SetConsoleTextAttribute(Console, New_Color | BACKGROUND_INTENSITY);
}

void clearScreen() {
    system("PAUSE");
    system("CLS");
}

void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

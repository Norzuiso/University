/**
Josue Norberto Aguilar Islas
Code: 2168191282

Programa_26: Funciones con parámetros.

Enunciado:
Sistema, “Áreas de Figuras Geométricas”, las Funciones a agregar son las siguientes:
	a) Cuadrado.
	b) Rectángulo
	c) Triangulo
    d) Salir

Nota: El llamado de las funciones con la estructura selectiva múltiple, switch o casos.

 **/

#include <stdio.h>

void square(float width);

void rectangle(float height, float width);

void triangle(float height, float width);

float getHeight();

float getWith();

void selectMenuOption(int opt);

int main() {
    int opt;

    do {
        printf("Qué figura quieres?\n");
        printf("1->Cuadrado\n2->Rectangulo\n3->Triangulo\n4->Salir");
        scanf("%i", &opt);
        selectMenuOption(opt);
    } while (opt != 4);

    return 0;
}

void selectMenuOption(int opt) {
    float height = 0, width = 0;
    switch (opt) {
        case 1:
            width = getWith();
            square(width);
            break;
        case 2:
            width = getWith();
            height = getHeight();
            rectangle(width, height);
            break;
        case 3:
            width = getWith();
            height = getHeight();
            triangle(height, width);
            break;
        case 4:
            printf("\n\tGracias por usar\n");
            break;
        default:
            printf("opcion incorrecta\n");
            break;
    }
}

void triangle(float height, float width) {
    printf("El area del Triangulo es = %.2f\n", (width * height) / 2);
}

float getWith() {
    float width =0;
    printf("Ingresa el ancho:");
    scanf("%f", &width);
    return width;
}

float getHeight() {
    float height =0;
    printf("Ingresa el altura:");
    scanf("%f", &height);
    return height;
}


void rectangle(float height, float width) {
    printf("El area del rectangulo es = %.2f\n", width * height);
}

void square(float width) {
    printf("El area del cuadrado es = %.2f\n", width * width);
}

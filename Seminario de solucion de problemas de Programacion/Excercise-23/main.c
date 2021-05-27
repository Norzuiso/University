/**
Josue Norberto Aguilar Islas
Code: 2168191282

Programa_24:
Enunciado:
Sistema, “Áreas de Figuras Geométricas”, las Funciones a agregar son las siguientes:
	a) Cuadrado.
	b) Rectángulo
	c)  Triangulo
    d) Salir

Nota: El llamado de las funciones con la estructura selectiva doble if...else.

 **/

#include <stdio.h>

void square();

void rectangle();

void triangle();

int main() {
    int opt;

    do {
        printf("Qué figura quieres?\n");
        printf("1->Cuadrado\n2->Rectangulo\n3->Triangulo\n4->Salir");
        scanf("%i", &opt);
        switch (opt) {
            case 1:
                square();
                break;
            case 2:
                rectangle();
                break;
            case 3:
                triangle();
                break;
            case 4:
                printf("\n\tGracias por usar\n");
                break;
            default:
                printf("opcion incorrecta\n");
                break;
        }
    } while (opt != 4);

    return 0;
}

void triangle() {
    float height = 0, width = 0;
    printf("Ingresa el altura del Triangulo:");
    scanf("%f", &height);
    printf("Ingresa el ancho del Triangulo:");
    scanf("%f", &width);
    printf("El area del Triangulo es = %.2f\n", (width * height) / 2);
}

void rectangle() {
    printf("Ingresa la altura del rectangulo:");
    float height = 0, width = 0;
    scanf("%f", &height);
    printf("Ingresa el ancho del rectangulo:");
    scanf("%f", &width);
    printf("El area del rectangulo es = %.2f\n", width * height);
}

void square() {
    printf("Ingresa el valor de un lado: ");
    float side = 0;
    scanf("%f", &side);
    printf("El area del cuadrado es = %.2f\n", side * 4);
}

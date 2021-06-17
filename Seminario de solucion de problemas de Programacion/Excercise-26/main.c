/**
Josue Norberto Aguilar Islas
Code: 2168191282


Enunciado:
Sistema, “Áreas de Figuras Geométricas”, las Funciones a agregar son las siguientes:
	a) Cuadrado.
	b) Rectángulo
	c)  Triangulo
          d) Salir


Nota: El llamado de las funciones automático o directo(secuencial).

 **/

#include <stdio.h>

void square(float width);

void rectangle(float height, float width);

void triangle(float height, float width);

float getHeight();

float getWith();

int main() {

    float height = 0, width = 0;
//Square
    width = getWith();
    square(width);
//rectangle
    width = getWith();
    height = getHeight();
    rectangle(height, width);
//triangle
    width = getWith();
    height = getHeight();
    triangle(height, width);


    return 0;
}

void triangle(float height, float width) {
    printf("El area del Triangulo es = %.2f\n", (width * height) / 2);
}

float getWith() {
    float width = 0;
    printf("Ingresa el ancho:");
    scanf("%f", &width);
    return width;
}

float getHeight() {
    float height = 0;
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

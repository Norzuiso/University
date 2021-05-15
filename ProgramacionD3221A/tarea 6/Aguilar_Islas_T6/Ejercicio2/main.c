//
// Created by josue on 4/27/2021.
//
//
// Created by josue on 4/27/2021.
//
/*

 2. Utilicemos ahora una instrucción while para calcular la media (promedio) de una lista de n
números.
1. Asignar el valor de 1 a la variable entera cont. Esta variable se utilizará como contador en
el bucle.
2. Asignar el valor de 0 a la variable en coma flotante suma.
3. Leer el valor de la variable entera n.
4. Realizar los siguientes pasos de forma repetida mientras cont no sea mayor que n.
a) Leer un número de la lista. Cada número se almacenará en la variable en coma flotante
x.
b) Añadir el valor de x al actual de suma.
c) Incrementar en 1 el valor de cont.
5. Dividir por n el valor de suma para obtener el deseado de la media.
6. Escribir el valor calculado de la media.

 * */
#include <stdio.h>


int main() {
    int cont = 1, n;
    float prom = 0;
    printf("Cuantos numeros? \n");
    scanf("%d", &n);
    while (cont <= n) {
        printf("x=%i\n", cont);
        prom+=cont;
        cont++;
    }
    prom = prom/n;
    printf("La media es %.2f\n",prom);
}


/**
Josue Norberto Aguilar Islas
Code: 2168191282

Programa_21:

Enunciado:

Hacer un algoritmo que llene una matriz de 4 * 4 y determine la posición [renglón, columna] del número mayor almacenado en la matriz.
Nota: Los números capturados deben ser diferentes.


Instrucciones:

Diseñar:
1.- Tabla de búsqueda de datos
2.- Seudocódigo y
3.- Lenguaje C
4.- Captura de pantalla, serían las siguientes tres:
      4.1.- Con el compilador y el código fuente
      4.2.- Cuando lo ejecutan o corren.
      4.3.- Cuando agregan datos al programa ejecutado.
 **/

#include <stdio.h>

int main() {
    int nums[4][4], num, auxGreater, auxI, auxJ;
    for(int i=0; i<=4; i++){
        for(int j=0; j<=4; j++){
            printf("[%i][%i]=", i,j);
            scanf("%i", &num);
            nums[i][j]=num;
            if(auxGreater < num){
                auxGreater = num;
                auxJ= j;
                auxI= i;
            }
        }
    }
    printf("El mayor de los numeros es: [%i][%i]=%i", auxI, auxJ, auxGreater);
    return 0;
}

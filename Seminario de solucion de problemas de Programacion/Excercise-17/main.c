La tabla de multiplicar con:

a) el multiplicando,
        b) el multiplicador y
        c) el producto.

* */

#include <stdio.h>

int main() {
    int num=0;
    printf("Ingresa un numero: ");
    scanf("%i", &num);
    for(int i=0; i<10; i++){
        printf("\n%i x %i = %i", num, i, num*i);
    }
    return 0;
}


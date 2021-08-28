#include <stdio.h>

struct racional
{
    int numerador;
    int denominador;
};

struct libro
{
    char name[20];
    int paginas;
    char indice[20];
    char edicion[20];
    char editorial[20];
    float costo;
};

bool valida_racional (racional a)
{
    if(a.denominador!=0)
    return true;
    else
    return false;
}

racional suma_racionales (racional a, racional b)
{
    racional c;
    if (valida_racional(a)==true&&valida_racional(b)==true)
    {
    //instrucciones de la suma
    }
    return c;
}

racional resta_racionales(racional x, racional y)
{
    racional z;
    if (valida_racional(x)==true&&valida_racional(y)==true)
    {
    //instrucciones de la resta
    }
    return z;
}

racional multiplicacion_racionales(racional x, racional y)
{
    racional z;
    if (valida_racional(x)==true&&valida_racional(y)==true)
    {
    //instrucciones de la resta
    }
    return z;
}

racional division_racionales(racional x, racional y)
{
    racional z;
    if (valida_racional(x)==true&&valida_racional(y)==true)
    {
    //instrucciones de la resta
    }
    return z;
}

libro registrar (libro a)
{
    char n[20];
    int pa;
    char ind[20];
    char edi[20];
    char edit[20];
    float cos;
    //pedir cada dato
    //leer cada dato en el struct
    //repetir las instrucciones para el resto de los campos
    return a;
}

void mostrar(libro a)
{
    printf("Nombre del libro %s", a.name);
    //imprimier el resto de los campos
    
}


int main (void)
{
    int a[4];
    scanf("%d", &a[0]);
    racional racional1, racional2;
    //pedir y leer los numeros racionales
    //estructura selectiva ciclica para elegir alguna operacion aritmetica
    //mostrar el resultado
    printf("El valor de a es %d:", a);
    printf("Esta es una linea que se imprime \n");
    return 0;
}
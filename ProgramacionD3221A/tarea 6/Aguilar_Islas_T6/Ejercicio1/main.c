//
// Created by josue on 4/27/2021.
//

//
// Created by josue on 4/27/2021.
//
/*
1. Una empresa paga a sus empleados como gerentes (quienes reciben un salario semanal fijo),
    trabajadores por horas (que reciben un sueldo fijo por hora para las primeras 40 horas que
    trabajen y “tiempo y medio”, 1.5 veces su sueldo por horas, para las horas extra trabajadas),
    empleados por comisión (que reciben $250 más 5.7 por ciento de sus ventas totales por semana),
    o trabajadores por piezas (que reciben una cantidad fija de dinero por cada artículo que producen;
    cada trabajador por piezas en esta empresa trabaja sólo en un tipo de artículo).
    Escriba un programa para calcular el sueldo semanal para cada empleado. No necesita saber
    cuántos empleados hay de antemano. Cada tipo de empleado tiene su propio código de pago:
        código 1 los gerentes
        código 2 los trabajadores por horas
        código 3 los trabajadores por comisión
        código 4 los trabajadores por piezas
Use una instrucción switch para calcular el sueldo de cada empleado, de acuerdo con el código de
pago de cada uno. Dentro del switch, pida al usuario (es decir, el cajero de nóminas) que introduzca
los hechos apropiados que su programa necesita para calcular el sueldo de cada empleado, de
acuerdo con su código de pago. El programa se seguirá repitiendo hasta ingresar el código -1. Al
finalizar el programa te dirá el total de empleados pagados según su clasificación.
 * */
#include <stdio.h>

void workerForPieces();

void simpleManager();

void workerforHour();

void workerComission();

int main() {
    int opt, managerPayed=0, workersForHourPayed=0, workersForPiecesPayed=0, workersCoPayed=0;
    while (opt != -1) {
        printf("\nIngrese el codigo de pago (-1 para finalizar): ");
        scanf("%i", &opt);

        switch (opt) {
            case 1:
                simpleManager();
                managerPayed++;
                break;

            case 2:
                workerforHour();
                workersForHourPayed++;

                break;
            case 3:
                workerComission();
                workersCoPayed++;
                break;
            case 4:
                workerForPieces();
                workersForPiecesPayed++;
                break;
            case -1:
                printf("\nNumero total de gerentes pagados: %i\n", managerPayed);
                printf("Numero total de trabajadores por hora pagados: %i\n ", workersForHourPayed);
                printf("Numero total de trabajadores de la comision pagados: %i\n", workersCoPayed);
                printf("Cantidad total de trabajadores por pieza pagados: %i\n", workersForPiecesPayed);
                break;
            default:
                printf("opción incorrecta, intenta de nuevo");
                break;
        }
    }

}

void workerComission() {
    float totalSalesWeek = 0;
    printf("\nTrabajador de comision seleccionado.");
    printf("\n Ingrese las ventas brutas semanales: ");
    scanf("%f", &totalSalesWeek);
    printf("\nEl salario del trabajador de la comision es de $%.2f", 250+(totalSalesWeek*0.057));
}

void workerforHour() {
    int totalHours, extraHour;
    float salaryByHour, finalPayment;

    printf("\nTrabajador por horas seleccionado");
    printf("\nIngrese el salario porhora: ");
    scanf("%f", &salaryByHour);
    printf("\nIngrese el total de horas trabajadas: ");
    scanf("%i", &totalHours);
    if (totalHours > 40) {
        extraHour = totalHours - 40;
        finalPayment = (extraHour * salaryByHour) * .5;
        finalPayment += 40 * salaryByHour;
        printf("\nEl trabajador ha trabajado %i horas extras", extraHour);
    } else {
        finalPayment = totalHours * salaryByHour;
    }
    printf("\nEl sueldo total es de $%.2f", finalPayment);

}

void simpleManager() {
    float salary = 0;
    printf("\nGerente seleccionado.");
    printf("\nIngrese el salario semana: ");
    scanf("%f", &salary);
    printf("\nEl pago del gerente es de $%.2f", salary);
}

void workerForPieces() {
    float numPieces, salaryByPieces;
    printf("\nTrabajador de piezas seleccionado.");
    printf("\nIngrese el numero de piezas: ");
    scanf("%f", &numPieces);
    printf("Ingrese el salario por pieza: ");
    scanf("%f", &salaryByPieces);
    printf("\nEl salario del trabajador es de $%.2f", numPieces * salaryByPieces);
}

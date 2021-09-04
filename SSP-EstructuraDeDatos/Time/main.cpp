#include <iostream>
#include "Hora.h"

using namespace std;

int main()
{
    Hora tiempo[10];
    int hora = 0;
    int minuto = 0;
    int segundo = 0;

    cout << "Ingresa la hora" << endl;
    cin >> hora;

    cout << "Ingresa el minuto" << endl;
    cin >> minuto;

    cout << "Ingresa el segundo" << endl;
    cin >> segundo;

    tiempo[0].setTiem(hora, minuto, segundo);

    cout << "Tiempo en formato militar" << endl;
    tiempo[0].printMilitarFormat();

    cout << "Tiempo en formato estandar" << endl;
    tiempo[0].printEstandarFormat();
}
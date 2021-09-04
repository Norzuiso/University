#include "Hora.h"

Hora::Hora()
{
    hora = 0;
    minuto = 0;
    segundo = 0;
}

void Hora::setTiem(int h, int m, int s)
{
    hora = (h >= 0 && h < 24) ? h : 0;

    minuto = (m >= 0 && m < 60) ? m : 0;

    segundo = (s >= 0 && s < 60) ? s : 0;
}
void Hora::printMilitarFormat()
{
    cout << hora
         << ":" << minuto << ":" << segundo << endl;
}
void Hora::printEstandarFormat()
{
    cout << hora
         << ":" << minuto << ":" << segundo << endl;
}
#include <iostream>

using namespace std;

class Hora
{
private:
    int hora;
    int minuto;
    int segundo;

public:
    Hora();
    void setTiem(int h, int m, int s);
    void printMilitarFormat();
    void printEstandarFormat();
};

#ifndef HORARIO_ESTUDIANTE_H
#define HORARIO_ESTUDIANTE_H

#include <iostream>
#include "Estudiante.h"
#include "Hora.h"
#include "Clase.h"

using namespace std;

class Horario_estudiante {
private:
    Estudiante estudiante;
    Clase clase;
    Hora horaInicio;
    Hora horaFin;
public:
    Horario_estudiante(const Estudiante &estudiante, const Clase &clase, const Hora &horaInicio, const Hora &horaFin);

    Horario_estudiante();

    const Estudiante &getEstudiante() const;

    void setEstudiante(const Estudiante &estudiante);

    const Clase &getClase() const;

    void setClase(const Clase &clase);

    const Hora getHoraInicio() const;

    void setHoraInicio(const Hora &horaInicio);

    const Hora &getHoraFin() const;

    void setHoraFin(const Hora &horaFin);

    static Horario_estudiante createHorarioEstudiante();


    void printHorario();
};

#endif //HORARIO_ESTUDIANTE_H
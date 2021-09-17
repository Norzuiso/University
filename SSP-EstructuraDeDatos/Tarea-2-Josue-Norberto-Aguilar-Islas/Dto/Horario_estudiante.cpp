
#include "Horario_estudiante.h"
#include <iostream>

Horario_estudiante::Horario_estudiante(const Estudiante &estudiante, const Clase &clase,
                                       const Hora &horaInicio, const Hora &horaFin) : estudiante(estudiante),
                                                                                      clase(clase),
                                                                                      horaInicio(horaInicio),
                                                                                      horaFin(horaFin) {}

Horario_estudiante::Horario_estudiante() {}

const Estudiante &Horario_estudiante::getEstudiante() const {
    return estudiante;
}

void Horario_estudiante::setEstudiante(const Estudiante &estudiante) {
    Horario_estudiante::estudiante = estudiante;
}

const Clase &Horario_estudiante::getClase() const {
    return clase;
}

void Horario_estudiante::setClase(const Clase &clase) {
    Horario_estudiante::clase = clase;
}

const Hora Horario_estudiante::getHoraInicio() const {
    return horaInicio;
}

void Horario_estudiante::setHoraInicio(const Hora &horaInicio) {
    Horario_estudiante::horaInicio = horaInicio;
}

const Hora &Horario_estudiante::getHoraFin() const {
    return horaFin;
}

void Horario_estudiante::setHoraFin(const Hora &horaFin) {
    Horario_estudiante::horaFin = horaFin;
}

Horario_estudiante Horario_estudiante::createHorarioEstudiante() {
    cout << "Hora de inicio" << endl;
    const Hora &hora = Hora::createHora();

    cout << "Hora fin de clase" << endl;
    const Hora &horaFin = Hora::createHora();

    const Estudiante &estudiante1 = Estudiante::createEstudiante();

    const Clase &clase = Clase::createClase();

    return Horario_estudiante(estudiante1, clase, hora, horaFin);
}

void Horario_estudiante::printHorario() {
    cout << "---------------------------------" << endl;
    cout << "Clase: "
         << clase.getName()
         << endl;

    cout << "---------------------------------" << endl;
    cout << "Hora de inicio: ";
    horaInicio.printEstandarFormat();

    cout << "Hora de fin: ";
    horaFin.printEstandarFormat();

    cout << "Estudiante: "
         << estudiante.getName()
         << " "
         << estudiante.getLastName()
         << endl;

    cout << "---------------------------------" << endl;

}

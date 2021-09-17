
#include <string>
#include "Estudiante.h"

Estudiante::Estudiante(const string &name, const string &lastName)
        : name(name), lastName(lastName) {}

Estudiante::Estudiante() {}

const string &Estudiante::getName() const {
    return name;
}

void Estudiante::setName(const string &name) {
    Estudiante::name = name;
}

const string &Estudiante::getLastName() const {
    return lastName;
}

void Estudiante::setLastName(const string &lastName) {
    Estudiante::lastName = lastName;
}

Estudiante Estudiante::createEstudiante() {
    Estudiante estudiante;
    string name;
    string lastName;

    cout << "Ingresa el nombre del estudiante" << endl;
    cin.ignore();
    getline(cin, name); 
    
    cout << "Ingresa el apellido del estudiante" << endl;
    cin.ignore();
    getline(cin, lastName); 
    
    return Estudiante(name, lastName);
}


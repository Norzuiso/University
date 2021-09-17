#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>

using namespace std;

class Estudiante{
private:
    string name;
    string lastName;
public:
    Estudiante(const string &name, const string &lastName);

    Estudiante();

    const string &getName() const;

    void setName(const string &name);

    const string &getLastName() const;

    void setLastName(const string &lastName);

    static Estudiante createEstudiante();

};

#endif //ESTUDIANTE_H
//
// Created by josue on 9/3/2021.
//

#include "Clase.h"

Clase::Clase() {}

Clase::Clase(const string &name) : name(name) {}

const string &Clase::getName() const {
    return name;
}

void Clase::setName(const string &name) {
    Clase::name = name;
}

Clase Clase::createClase() {
    Clase clase;
    string name;
    cout << "El Nombre de la clase" << endl;
    cin.ignore();
    getline(cin, name); 

    return Clase(name);
}


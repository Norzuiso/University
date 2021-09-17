//
// Created by josue on 9/3/2021.
//

#ifndef TAREA_2_JOSUE_NORBERTO_AGUILAR_ISLAS_CLASE_H
#define TAREA_2_JOSUE_NORBERTO_AGUILAR_ISLAS_CLASE_H

#include <iostream>

using namespace std;


class Clase {
private:
    string name;
public:
    Clase();

    Clase(const string &name);

    const string &getName() const;

    void setName(const string &name);

    static Clase createClase();
};


#endif //TAREA_2_JOSUE_NORBERTO_AGUILAR_ISLAS_CLASE_H

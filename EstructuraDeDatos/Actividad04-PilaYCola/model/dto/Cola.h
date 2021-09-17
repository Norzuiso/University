//
// Created by josue on 9/5/2021.
//

#ifndef ACTIVIDAD04_PILAYCOLA_COLA_H
#define ACTIVIDAD04_PILAYCOLA_COLA_H

#include "../../logic/utils/Utils.h"

template<class T, int size = 1024>
class Cola {
private:
    T data[size];
    int frontPos;
    int endPos;

public:
    Cola();

    bool isEmpty();

    bool isFull();

    void enqueue(const T &);

    T dequeue();

    T getFront();


};

template<class T, int size>
Cola<T, size>::Cola() : frontPos(0), endPos(size - 1) {
}

template<class T, int size>
bool Cola<T, size>::isEmpty() {
    return frontPos == endPos + 1 or (frontPos == 0 and endPos == size - 1);
}

template<class T, int size>
bool Cola<T, size>::isFull() {
    return frontPos == endPos + 2
           or (frontPos == 0 and endPos == size - 2)
           or (frontPos == 1 and endPos == size - 1);
}

template<class T, int size>
void Cola<T, size>::enqueue(const T &value) {
    Utils::isTrueThrowException(isFull(), "La Cola se encuentra llena");
    if (++endPos == size) {
        endPos = 0;
    }
    data[endPos] = value;
}

template<class T, int size>
T Cola<T, size>::dequeue() {
    Utils::isTrueThrowException(isEmpty(), "No hay suficientes valores en la cola");

    T result(data[frontPos]);

    if (++frontPos == size) {
        frontPos = 0;
    }

    return result;
}

template<class T, int size>
T Cola<T, size>::getFront() {
    Utils::isTrueThrowException(isEmpty(), "No hay suficientes valores en la cola");
    return data[frontPos];
}


#endif //ACTIVIDAD04_PILAYCOLA_COLA_H

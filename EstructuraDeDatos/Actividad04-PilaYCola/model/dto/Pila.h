//
// Created by josue on 9/5/2021.
//

#ifndef ACTIVIDAD04_PILAYCOLA_PILA_H
#define ACTIVIDAD04_PILAYCOLA_PILA_H

#include "../../logic/utils/Utils.h"

template<class T, int size = 1024>
class Pila {
private:
    T data[size];
    int top;
private:
    Pila();

    bool isEmpty();

    bool isFull();

    void push(T value);

    T pop();

    T getTop();

};

template<class T, int size>
Pila<T, size>::Pila() {
    top = -1;
}

template<class T, int size>
bool Pila<T, size>::isEmpty() {
    return top == -1;
}

template<class T, int size>
bool Pila<T, size>::isFull() {
    return top == size - 1;
}

template<class T, int size>
void Pila<T, size>::push(T value) {
    Utils::isTrueThrowException(isEmpty(), "Desbordamiento de datos");

    data[++top] = value;
}

template<class T, int size>
T Pila<T, size>::pop() {
    Utils::isTrueThrowException(isEmpty(), "La pila se encuentra vacia ");
    return data[top--];
}

template<class T, int size>
T Pila<T, size>::getTop() {
    Utils::isTrueThrowException(isEmpty(), "La pila se encuentra vacia ");
    return data[top];
}


#endif //ACTIVIDAD04_PILAYCOLA_PILA_H

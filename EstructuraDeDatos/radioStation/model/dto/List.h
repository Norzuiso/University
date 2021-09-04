//
// Created by josue on 8/28/2021.
//
#include <iostream>
#include "../../exceptions/ListException.h"

using namespace std;

template<typename T>

#ifndef RADIOSTATION_LISTA_H
#define RADIOSTATION_LISTA_H


class List {
private:
    T *data;
    int last;
    int size;

    void copyAll(const List &);

public:
    int getLast() const;

    List(const int &size);


    bool isEmpty();

    bool isFull();

    void insertDataInPosition(const int &, const T &);

    void deleteData(const int &);

    int getFirstPosition();

    int getLastPosition();

    int getPreviousPosition(const int &position);

    int getNextPosition(const int &position);

    T retrieve(const int &);

    void deleteAll();

    bool isInvalidPos(const int &position);

    bool isValidPosition(const int &position);

    string toString();

    void insertData(const T &value);

    T getValueFromPosition(const int &position);
};

template<typename T>
void List<T>::copyAll(const List &list) {
    int i(0);
    while (i <= list.last) {
        data[i] = list.data[i];
        i++;
    }
    size = list.size();
    last = list.last;
}

template<typename T>
List<T>::List(const int &size) {
    this->size = size;
    data = new T[size];

    last = -1;
}


template<typename T>
bool List<T>::isEmpty() {
    return last == -1;
}

template<typename T>
bool List<T>::isFull() {
    return last == 499;
}

template<typename T>
void List<T>::insertDataInPosition(const int &position, const T &value) {
    if (isFull()) {
        throw ListException("Error: La Lista ya se encuentra llena");
    }

    if (position == -1) {
        throw ListException("Posicion invalida, insertDataInPosition");
    }

    int i(last);
    while (i > position) {
        data[i + 1] = data[i];
        i--;
    }
    data[position + 1] = value;
    last++;
}

template<typename T>
void List<T>::insertData(const T &value) {
    if (isFull()) {
        throw ListException("Error: La Lista ya se encuentra llena");
    }
    data[last+1] = value;
    last++;
}

template<typename T>
void List<T>::deleteData(const int &position) {
    if (isInvalidPos(position)) {
        throw ListException("Posicion invalida, deleteData");
    }

    int i(position);
    while (i < last) {
        data[i] = data[i + 1];
        i++;
    }
    last--;
}

template<typename T>
int List<T>::getFirstPosition() {
    if (isEmpty()) {
        return -1;
    }
    return 0;
}

template<typename T>
int List<T>::getLastPosition() {
    return last;
}

template<typename T>
int List<T>::getPreviousPosition(const int &position) {
    if (position == getFirstPosition() or isInvalidPos(position)) {
        return -1;
    }
    return position - 1;
}

template<typename T>
int List<T>::getNextPosition(const int &position) {
    if (position == getFirstPosition() or isInvalidPos(position)) {
        return -1;
    }
    return position + 1;
}


template<typename T>
T List<T>::retrieve(const int &position) {
    if (isInvalidPos(position)) {
        throw ListException("Posicion invalida, retrieve");
    }
    return data[position];
}

template<typename T>
void List<T>::deleteAll() {
    last = -1;
}

template<typename T>
bool List<T>::isInvalidPos(const int &position) {
    return !isValidPosition(position);
}

template<typename T>
bool List<T>::isValidPosition(const int &position) {
    return position >= 0 and position > last;
}

template<typename T>
string List<T>::toString() {
    string res;
    int i(1);

    while (i <= last) {
        res += to_string(data[i]) + "\n ";
        i++;
    }
    res += "\n";

    return res;
}

template<typename T>
T List<T>::getValueFromPosition(const int &position) {
    return data[position];
}

template<typename T>
int List<T>::getLast() const {
    return last;
}


#endif //RADIOSTATION_LISTA_H

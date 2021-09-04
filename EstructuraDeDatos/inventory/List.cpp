//
// Created by josue on 8/28/2021.
//

#include "List.h"
#include "exceptions/ListException.h"

template<typename T>
void List<T>::copyAll(const List &list) {

}

template<typename T>
List<T>::List(){
}

template<typename T>
List<T>::List(const List &) {

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
void List<T>::insertData(const int &position, const T &value) {
    last = 499;
    if (isFull()) {
        throw ListException((const ListException &) "Error: La Lista ya se encuentra llena");
    }

    if (position != -1 and isInvalidPos(position)) {

    }

}

template<typename T>
void List<T>::deleteData(const int &) {
}

template<typename T>
int List<T>::getFirstPosition() {
    return 0;
}

template<typename T>
int List<T>::getLastPosition() {
    return 0;
}

template<typename T>
int List<T>::getPreviousPosition() {
    return 0;
}

template<typename T>
int List<T>::getNextPosition() {
    return 0;
}

template<typename T>
void List<T>::printLists() {

}

template<typename T>
T List<T>::retrieve(const int &) {
    return nullptr;
}

template<typename T>
void List<T>::deleteAll() {

}

template<typename T>
bool List<T>::isInvalidPos(const int &position) {
    return !isValidPosition();
}

template<typename T>
bool List<T>::isValidPosition() {
    return false;
}


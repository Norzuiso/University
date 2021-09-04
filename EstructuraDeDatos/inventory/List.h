//
// Created by josue on 8/28/2021.
//
#include <iostream>

using namespace std;

template<typename T>

#ifndef RADIOSTATION_LISTA_H
#define RADIOSTATION_LISTA_H


class List {
private:
    T data[500];
    int last;

    void copyAll(const List &);

public:
    List();

    List(const List &);

    bool isEmpty();

    bool isFull();

    void insertData(const int &, const T &);

    void deleteData(const int &);

    int getFirstPosition();

    int getLastPosition();

    int getPreviousPosition();

    int getNextPosition();

    void printLists();

    T retrieve(const int &);

    void deleteAll();


    bool isInvalidPos(const int &position);

    bool isValidPosition();
};



#endif //RADIOSTATION_LISTA_H

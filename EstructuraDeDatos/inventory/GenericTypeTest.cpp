//
// Created by josue on 8/29/2021.
//

#include "GenericTypeTest.h"


template<class T>
GenericTypeTest<T>::GenericTypeTest(T test) {
    value = test;
}

template<class T>
GenericTypeTest<T>::GenericTypeTest() {}

template<class T>
void GenericTypeTest<T>::setValue(T value) {
    GenericTypeTest::value = value;
}
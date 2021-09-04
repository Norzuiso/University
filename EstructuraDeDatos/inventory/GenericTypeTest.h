
#ifndef GENERIC_TYPE_TEST_H
#define GENERIC_TYPE_TEST_H

// CPP program to illustrate Templates
#include <iostream>

using namespace std;

template<class T>
class GenericTypeTest {
private:
    T value;

public:
    GenericTypeTest(T test);

    void setValue(T value);

    GenericTypeTest();

    T getValue() {
        return value;
    }
};


#endif //GENERIC_TYPE_TEST_H

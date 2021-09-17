//
// Created by josue on 8/22/2021.
//

#ifndef INVENTORY_UTILS_H
#define INVENTORY_UTILS_H

#include <string>
#include <iostream>

using namespace std;

class Utils {

public:
    static void throwErrorMsg(const string &errorMsg);

    static string getStringValue(const string &messageRequest);

    static float getFloatValue(const string &messageRequest);

    static int getIntValue(const string &messageRequest);

    static void isTrueThrowPilaException(bool option, const string &message);

    static void isTrueThrowException(bool option, const string &message);

};


#endif //INVENTORY_UTILS_H

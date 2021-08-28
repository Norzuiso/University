//
// Created by josue on 8/22/2021.
//

#ifndef INVENTORY_UTILS_H
#define INVENTORY_UTILS_H

#include <string>

using namespace std;

class Utils {

public:
    static void throwErrorMsg(const string &errorMsg);

    static string getStringValue(const string &messageRequest);

    static float getFloatValue(const string &messageRequest);

    static int getIntValue(const string &messageRequest);

};


#endif //INVENTORY_UTILS_H

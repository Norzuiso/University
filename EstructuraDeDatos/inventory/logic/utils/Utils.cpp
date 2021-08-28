//
// Created by josue on 8/22/2021.
//

#include "Utils.h"

#include <iostream>
#include <string>

using namespace std;

string Utils::getStringValue(const string &messageRequest) {
    string value;
    cout << messageRequest;
    cin >> value;
    return value;
}

void Utils::throwErrorMsg(const string &errorMsg) { cout << errorMsg << endl; }

float Utils::getFloatValue(const string &messageRequest) {
    float value;
    cout << messageRequest;
    cin >> value;
    return value;
}

int Utils::getIntValue(const string &messageRequest) {
    int value;
    cout << messageRequest;
    cin >> value;
    return value;
}



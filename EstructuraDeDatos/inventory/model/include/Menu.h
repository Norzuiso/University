//
// Created by josue on 8/22/2021.
//

#ifndef INVENTORY_MENU_H
#define INVENTORY_MENU_H

#include "Date.h"

#include <iostream>
#include <string>

using namespace std;

class Menu {
private:
    string projectName;
    string outPutStr;
    Date actualDate;
public:
    Menu();

    Menu(const string &projectName, const string &outPutStr, const Date &actualDate);

    const string &getProjectName() const;

    void setProjectName(const string &projectName);

    const string &getOutPutStr() const;

    void setOutPutStr(const string &outPutStr);

    const Date &getActualDate() const;

    void setActualDate(const Date &actualDate);

};


#endif //INVENTORY_MENU_H

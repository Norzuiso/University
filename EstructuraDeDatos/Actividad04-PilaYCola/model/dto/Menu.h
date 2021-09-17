//
// Created by josue on 8/22/2021.
//

#ifndef INVENTORY_MENU_H
#define INVENTORY_MENU_H

#include <iostream>
#include <string>
#include <string>

using namespace std;

class Menu {
private:
    string projectName;
    string outPutStr;
public:
    Menu();

    const string &getProjectName() const;

    void setProjectName(const string &projectName);

    const string &getOutPutStr() const;

    void setOutPutStr(const string &outPutStr);

};


#endif //INVENTORY_MENU_H

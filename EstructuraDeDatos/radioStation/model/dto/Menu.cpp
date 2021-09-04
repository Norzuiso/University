//
// Created by josue on 8/22/2021.
//

#include "Menu.h"

using namespace std;

Menu::Menu() {}

const string &Menu::getProjectName() const {
    return projectName;
}

void Menu::setProjectName(const string &projectName) {
    Menu::projectName = projectName;
}

const string &Menu::getOutPutStr() const {
    return outPutStr;
}

void Menu::setOutPutStr(const string &outPutStr) {
    Menu::outPutStr = outPutStr;
}

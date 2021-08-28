//
// Created by josue on 8/22/2021.
//

#include "../include/Menu.h"

#include <iostream>
#include <string>

using namespace std;

Menu::Menu() {}

Menu::Menu(const string &projectName, const string &outPutStr, const Date &actualDate) : projectName(projectName),
                                                                                         outPutStr(outPutStr),
                                                                                         actualDate(actualDate) {}

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

const Date &Menu::getActualDate() const {
    return actualDate;
}

void Menu::setActualDate(const Date &actualDate) {
    Menu::actualDate = actualDate;
}

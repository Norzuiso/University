//
// Created by josue on 8/22/2021.
//
#include "InventoryLogic.h"
#include <iostream>
#include <vector>
#include <string>
#include "MenuLogic.h"

using namespace std;

int MenuLogic::showMenu(std::vector<std::string> options) {
    for (int i = 0; i < options.size(); i++) {
        cout << i << ".- " << options[i];
    }
    int option;
    cin >> option;
    return option;
}

void MenuLogic::showWelcomeMenssage(const string &Welcome) { cout << Welcome << endl; }
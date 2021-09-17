//
// Created by josue on 8/22/2021.
//

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

void MenuLogic::println(const string &msg) {
    std::cout << msg << endl;
}

void MenuLogic::print(const string &msg) {
    std::cout << msg;
}
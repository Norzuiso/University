//
// Created by josue on 8/22/2021.
//

#ifndef INVENTORY_MENULOGIC_H
#define INVENTORY_MENULOGIC_H
#include <iostream>
#include <vector>
#include <string>

class MenuLogic {

public:
    static int showMenu(std::vector<std::string> options);
    static void showWelcomeMenssage(const std::string &Welcome);
    static void println(const std::string &msg);
    static void print(const std::string &msg);
};

#endif //INVENTORY_MENULOGIC_H

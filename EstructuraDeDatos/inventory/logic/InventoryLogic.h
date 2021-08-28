//
// Created by josue on 8/22/2021.
//

#ifndef INVENTORY_INVENTORYLOGIC_H
#define INVENTORY_INVENTORYLOGIC_H


static const char *const WELCOME_MESSAGE = " ------------------------------------------------------------------------------  \n"
                                           " |                   Sistema de Inventario \"El pollito\"                       |  \n"
                                           " |                                   Por                                      |  \n"
                                           " |                      Josue Norberto Aguilar Islas                          |  \n"
                                           " |              Centro Universitario de Ciencias Exactas e Ingenierias        |  \n"
                                           " ------------------------------------------------------------------------------  \n";

static const char *const CLOSE = "Salir \n";

static const char *const DECREASE_QUANTITY = "Retirar existencia\n";

static const char *const INCREASE_QUANTITY = "Amuentar existencia\n";

static const char *const NEW_PRODUCT = "Nuevo producto\n";

#include "../model/include/Product.h"

class InventoryLogic {
private:
public:
    InventoryLogic();

    void startProject();

    void showWelcomeMenssage(const string &Welcome);

    void optionHub(int option);

    void addNewProduct();

    static void increaseQuantity();

    void decreaseQuantity();
};


#endif //INVENTORY_INVENTORYLOGIC_H

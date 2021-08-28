//
// Created by josue on 8/22/2021.
//

#include "InventoryLogic.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "MenuLogic.h"
#include "utils/Utils.h"
#include "ProductLogic.h"

using namespace std;

std::list<Product> products;
ProductLogic productLogic;

void InventoryLogic::startProject() {
    int option;
    productLogic = ProductLogic();

    do {
        MenuLogic::showWelcomeMenssage(WELCOME_MESSAGE);
        option = MenuLogic::showMenu({
                                             NEW_PRODUCT,
                                             INCREASE_QUANTITY,
                                             DECREASE_QUANTITY,
                                             CLOSE});
        optionHub(option);

    } while (option != 3);
}

void InventoryLogic::optionHub(int option) {
    switch (option) {
        case 0:
            addNewProduct();
            break;
        case 1:
            increaseQuantity();
            break;
        case 2:
            decreaseQuantity();
            break;
        case 3:
            cout << "Gracias por usar el programa :D" << endl;
            break;
        default:
            Utils::throwErrorMsg("Opcion erronea, intentalo de nuevo");
            break;
    }
}

void InventoryLogic::increaseQuantity() {
    if (products.size() == 0) {
        Utils::throwErrorMsg("Error, no hay productos agregados");
    } else {
        string barcode = Utils::getStringValue("Ingrea el codigo de barras del producto:");
        Product product = productLogic.getProductFromListByBarcode(products, barcode);
        int addQuantity = Utils::getIntValue("Cuantas piezas vas a agregar:");
        int actualQuantity = product.getQuantity();
        int newQuantity = actualQuantity + addQuantity;
        product.setQuantity(newQuantity);
        products = productLogic.saveProduct(&product, products);
        productLogic.showProduct(product);
    }
}

void InventoryLogic::decreaseQuantity() {
    if (products.size() == 0) {
        Utils::throwErrorMsg("Error, no hay productos agregados");
    } else {
        string barcode = Utils::getStringValue("Ingrea el codigo de barras del producto:");
        Product product = productLogic.getProductFromListByBarcode(products, barcode);
        int addQuantity = Utils::getIntValue("Cuantas piezas vas a quitar:");
        int actualQuantity = product.getQuantity();
        int newQuantity = actualQuantity - addQuantity;
        product.setQuantity(newQuantity);
        products = productLogic.saveProduct(&product, products);

        productLogic.showProduct(productLogic.getProductFromListByBarcode(products, barcode));
    }
}

void InventoryLogic::addNewProduct() {
    const Product &product = productLogic.createNewProduct();
    products.push_front(product);
    cout << "Producto agregado correctamente" << endl;
    productLogic.showProduct(product);
}

InventoryLogic::InventoryLogic() {}

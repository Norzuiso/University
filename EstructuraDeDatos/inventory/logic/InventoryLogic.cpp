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

template<class T>
void InventoryLogic<T>::startProject() {
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

template<class T>
void InventoryLogic<T>::optionHub(int option) {
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

template<class T>
void InventoryLogic<T>::increaseQuantity() {
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

template<class T>
void InventoryLogic<T>::decreaseQuantity() {
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

template<class T>
void InventoryLogic<T>::addNewProduct() {
    const Product &product = productLogic.createNewProduct();
    products.push_front(product);
    cout << "Producto agregado correctamente" << endl;
    productLogic.showProduct(product);
}


template<class T>
InventoryLogic<T>::InventoryLogic() {}

template<class T>
T InventoryLogic<T>::getValue() const {
    return value;
}

template<class T>
void InventoryLogic<T>::setValue(T value) {
    InventoryLogic::value = value;
}

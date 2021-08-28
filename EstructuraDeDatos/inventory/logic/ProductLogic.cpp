//
// Created by josue on 8/22/2021.
//

#include "utils/Utils.h"
#include <string>
#include <iostream>
#include <cstring>
#include "InventoryLogic.h"
#include "ProductLogic.h"

ProductLogic::ProductLogic() {}

Product ProductLogic::createNewProduct() {
    string barcode = getValidBarcode();
    string productName = Utils::getStringValue("Ingrea el nombre del producto:");
    float weight = Utils::getFloatValue("Ingrea el peso del producto: ");
    float priceWholesale = Utils::getFloatValue("Ingrea el precio por mayoreo del producto: ");
    float normalPrice = Utils::getFloatValue("Ingrea el precio normal del producto: ");
    int quantity = Utils::getIntValue("Ingresa la cantidad actual de producto: ");

    Date date = getValidDate();

    return Product(barcode, productName, weight, date, priceWholesale, normalPrice, quantity);
}

Date ProductLogic::getValidDate() {
    int day = Utils::getIntValue("Ingresa el numero del dia: ");
    int month = Utils::getIntValue("Ingresa el numero del mes: ");
    int year = Utils::getIntValue("Ingresa el ano: ");
    return {day, month, year};
}

string ProductLogic::getValidBarcode() {
    string barcode = " ";
    do {
        barcode = Utils::getStringValue("Ingrea el codigo de barras:");
        if (barcode.size() != 13) {
            Utils::throwErrorMsg("Error el codigo de barras debe contener 13 digitos");
        }
    } while (barcode.size() != 13);
    return barcode;
}

Product ProductLogic::getProductFromListByBarcode(std::list<Product> listOfProducts, const string barcode) {
    Product finalProduct;
    for (auto product : listOfProducts) {
        string basicString = product.getBarcode();
        if (basicString.compare(barcode) == 0) {
            finalProduct = product;
        }
    }
    return finalProduct;
}

void ProductLogic::showProduct(const Product &product) {
    cout << "\nMostrando Producto: " << product.getProductName();

    cout << "Codigo de barras: " << product.getBarcode() << endl;
    cout << "Producto: " << product.getProductName() << endl;
    cout << "Peso: " << product.getWeight() << endl;
    Date &date = const_cast<Date &>(product.getInputDate());
    cout << "Fecha de ingreso: " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << endl;
    cout << "Precio mayoreo: " << product.getPriceWholesale() << endl;
    cout << "Precio regular: " << product.getNormalPrice() << endl;
    cout << "cantidad: " << product.getQuantity() << endl;

}

list<Product> ProductLogic::saveProduct(Product* product, list<Product> listOfProducts) {

    std::list <Product>::iterator iObject;
    for (iObject= listOfProducts.begin(); iObject != listOfProducts.end(); ++iObject)
    {
        Product tempProduct = *iObject;
        string barcode = tempProduct.getBarcode();
        if (barcode == product->getBarcode()) {
            *iObject = *product;
        }
    }

    return listOfProducts;
}

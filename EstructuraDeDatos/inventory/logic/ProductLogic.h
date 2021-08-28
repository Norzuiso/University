//
// Created by josue on 8/22/2021.
//

#ifndef INVENTORY_PRODUCTLOGIC_H
#define INVENTORY_PRODUCTLOGIC_H


#include <list>
#include "../model/include/Product.h"

class ProductLogic {

public:
    ProductLogic();

    Product createNewProduct();

    Date getValidDate();

    string getValidBarcode();

    Product getProductFromListByBarcode(std::list<Product> listOfProducts, const string barcode);

    void showProduct(const Product &product);

    list<Product> saveProduct(Product *product, list<Product> listOfProducts);
};


#endif //INVENTORY_PRODUCTLOGIC_H

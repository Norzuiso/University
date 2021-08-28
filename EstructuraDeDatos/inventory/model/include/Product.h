//
// Created by josue on 8/22/2021.
//

#ifndef INVENTORY_PRODUCT_H
#define INVENTORY_PRODUCT_H

#include <string>
#include "Date.h"

using namespace std;

class Product {
private:
    string barcode;
    string productName;
    float weight;
    Date inputDate;
    float priceWholesale;
    float normalPrice;
    int quantity;

public:
    Product();

    Product(const string &barcode, const string &productName, float weight, const Date &inputDate, float priceWholesale,
            float normalPrice, int quantity);

    const string &getBarcode() const;

    void setBarcode(const string &barcode);

    const string &getProductName() const;

    void setProductName(const string &productName);

    float getWeight() const;

    void setWeight(float weight);

    const Date &getInputDate() const;

    void setInputDate(const Date &inputDate);

    float getPriceWholesale() const;

    void setPriceWholesale(float priceWholesale);

    float getNormalPrice() const;

    void setNormalPrice(float normalPrice);

    int getQuantity() const;

    void setQuantity(int quantity);

};

#endif //INVENTORY_PRODUCT_H

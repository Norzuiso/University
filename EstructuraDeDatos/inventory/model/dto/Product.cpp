//
// Created by josue on 8/22/2021.
//

#include "../include/Product.h"

#include <string>

using namespace std;

Product::Product(const string &barcode, const string &productName, float weight, const Date &inputDate,
                 float priceWholesale, float normalPrice, int quantity) : barcode(barcode), productName(productName),
                                                                          weight(weight), inputDate(inputDate),
                                                                          priceWholesale(priceWholesale),
                                                                          normalPrice(normalPrice),
                                                                          quantity(quantity) {}

Product::Product() {}

const string &Product::getBarcode() const {
    return barcode;
}

void Product::setBarcode(const string &barcode) {
    Product::barcode = barcode;
}

const string &Product::getProductName() const {
    return productName;
}

void Product::setProductName(const string &productName) {
    Product::productName = productName;
}

float Product::getWeight() const {
    return weight;
}

void Product::setWeight(float weight) {
    Product::weight = weight;
}

const Date &Product::getInputDate() const {
    return inputDate;
}

void Product::setInputDate(const Date &inputDate) {
    Product::inputDate = inputDate;
}

float Product::getPriceWholesale() const {
    return priceWholesale;
}

void Product::setPriceWholesale(float priceWholesale) {
    Product::priceWholesale = priceWholesale;
}

float Product::getNormalPrice() const {
    return normalPrice;
}

void Product::setNormalPrice(float normalPrice) {
    Product::normalPrice = normalPrice;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::setQuantity(int quantity) {
    Product::quantity = quantity;
}

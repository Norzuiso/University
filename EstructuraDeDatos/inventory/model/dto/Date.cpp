//
// Created by josue on 8/22/2021.
//

#include "../include/Date.h"


Date::Date() {

}

int Date::getDay() const {
    return day;
}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

void Date::setDay(int day) {
    Date::day = day;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

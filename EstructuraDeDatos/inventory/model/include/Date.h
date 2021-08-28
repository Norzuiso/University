//
// Created by josue on 8/22/2021.
//

#ifndef INVENTORY_DATE_H
#define INVENTORY_DATE_H


#include <ctime>

class Date {
private:
    int day;
    int month;
    int year;
public:
    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);

    Date();

    Date(int day, int month, int year);
};


#endif //INVENTORY_DATE_H

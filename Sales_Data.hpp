//
// Created by yinlei on 2020-4-24.
//
#include <string>
#include <iostream>

struct Sales_Data {
    std::string isbn() const {
        return this->bookNo;
    }

    Sales_Data& combine(const Sales_Data &data);
    double avg_price() const;

    std::string bookNo;
    unsigned  units_sold = 0;
    double revenue = 0.0;
};

Sales_Data add(const Sales_Data &one, const Sales_Data &another);
std::ostream & print(std::ostream &os, const Sales_Data &data);
std::istream & read(std::istream &, Sales_Data data); // 省略形参名
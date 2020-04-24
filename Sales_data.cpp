//
// Created by yinlei on 2020/4/24.
//
#include "Sales_Data.hpp"

double Sales_Data::avg_price() const {
    if (units_sold) {
        return this->revenue / this->units_sold;
    } else {
        return 0;
    }
}

Sales_Data & Sales_Data::combine(const Sales_Data &data) {
    this->units_sold += data.units_sold;
    this->revenue += data.revenue;
    // this是指针，指向当前对象
    return *this; // 解引用才能获得当前对象，一个对象正好可以返回给引用
}

Sales_Data::Sales_Data(std::istream &istream) {
    read(istream, *this); // 再建一个cpp文件吧，将声明和定义分开。
}

// 以下是非成员函数
std::istream & read(std::istream &is, Sales_Data &data) {
    double price = 0;
    is >> data.bookNo >> data.units_sold >> price;
    data.revenue = price * data.units_sold;
    return is;
}

std::ostream & print(std::ostream &os, const Sales_Data &data) { // lose const: 对‘print(std::ostream&, Sales_Data const&)’未定义的引用
    os << data.isbn() << " " << data.units_sold << " "
       << data.revenue << " " << data.avg_price();
    return os;
}

Sales_Data add(Sales_Data &lv, Sales_Data &rv) {
    Sales_Data sum = lv; // 值拷贝
    sum.combine(rv); // Sales_Data已经定义了一个方法，将两个对象合并（相加）到一起
    return sum;
}

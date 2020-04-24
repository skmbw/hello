//
// Created by yinlei on 2020-4-24.
//
#include <string>
#include <iostream>

struct Sales_Data {
    // 规则太复杂
    // const是修改this指针的，默认this是指向类类型非常量版本的常量指针
    // 现在表示this是指向常量的指针
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

// 以下是非成员函数
std::istream & read(std::istream &is, Sales_Data &data) {
    double price = 0;
    is >> data.bookNo >> data.units_sold >> price;
    data.revenue = price * data.units_sold;
    return is;
}

std::ostream & print(std::ostream &os, Sales_Data &data) {
    os << data.isbn() << " " << data.units_sold << " "
        << data.revenue << " " << data.avg_price();
    return os;
}

Sales_Data add(Sales_Data &lv, Sales_Data &rv) {
    Sales_Data sum = lv; // 值拷贝
    sum.combine(rv); // Sales_Data已经定义了一个方法，将两个对象合并（相加）到一起
    return sum;
}
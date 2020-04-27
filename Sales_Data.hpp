//
// Created by yinlei on 2020-4-24.
//
// if not preprocesss command, will multi-define
#ifndef SALES_DATA_HPP
#define SALES_DATA_HPP

#include <string>
#include <iostream>

// struct定义的类，默认访问控制符是public的
class Sales_Data {
    // 不声明友元，这三个函数将无法访问Sales_Data的成员变量
    // 友元只是访问权限，而不是函数声明
    friend Sales_Data add(const Sales_Data& data, const Sales_Data& another);
    friend std::ostream &print(std::ostream& ostream, const Sales_Data& data);
    friend std::istream &read(std::istream& istream, Sales_Data& data);
public:
    // 默认构造函数
    Sales_Data() = default;
    Sales_Data(std::istream & istream); // 这个构造函数还没有初始化
    Sales_Data(const std::string &no): bookNo(no) {}
    // 构造函数初始化列表的顺序是按照成员定义的顺序开始的，跟初始化列表中的顺序没有关系
    Sales_Data(const std::string &no, unsigned n, double p):
        bookNo(no), units_sold(n), revenue(p * n) {}

    // 规则太复杂
    // const是修改this指针的，默认this是指向类类型非常量版本的常量指针
    // 现在表示this是指向常量的指针
    std::string isbn() const {
        return this->bookNo;
    }

    Sales_Data& combine(const Sales_Data &data);

private:
    double avg_price() const;

    std::string bookNo;
    // 内置类型，也就是基本类型，如果在类内或者块内，不默认初始化，那么它的值是未知的，很危险。
    unsigned  units_sold = 0;
    double revenue = 0.0;
};

Sales_Data add(const Sales_Data &one, const Sales_Data &another);
std::ostream & print(std::ostream &os, const Sales_Data &data); // print(std::ostream&, Sales_Data const&)’未定义的引用
std::istream & read(std::istream &, Sales_Data &data); // 省略形参名,the second param forget the &, undefined ref

#endif
//
// Created by yinlei on 17-7-7.
//
#include <iostream>
#include "Test.h"
#include <string>
#include <vector>
#include "Sales_Data.hpp"
#include <fstream>

void Test::test() {
    std::ifstream ifstream;
    ifstream.open("~/nohub.out");
    std::cout << ifstream.is_open() << std::endl;

    Sales_Data salesData("as-123");
    print(std::cout, salesData) << std::endl; // endl flush cache

    std::cout << "hello test." << std::endl;
    learn();
}

void Test::learn() {
    std::string str = "asdf";
    auto begin = str.begin();
    auto end = str.end();
    for (;begin != end; begin++) {
        std::cout << *begin << std::endl; // endl 方法会立即刷新缓冲区，将字符打印到控制台
    }
}

std::vector<std::string> Test::process(const std::string &s1) {
    return {"aa", "bb", "cc"};
}

std::vector<int> Test::return_int(const int &s1) {
    // 可以返回多个内置基本类型啊？P227，可能的意思是返回int，而非vector<int>，那样返回列表初始化，当然只能是一个了，不是废话嘛
    return {1, 2, 3};
}

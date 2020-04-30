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
    std::ofstream ofstream;
    ofstream.open("/home/yinlei/nohub.out");
    std::string s("adb");
    ofstream << s;
    std::cout << s << ofstream.is_open() << std::endl;
    ofstream.close();

    std::ifstream file("/home/yinlei/nohub.out");
    char s1[4];
    file.getline(s1, 4);
    std::cout << s1 << std::endl;

//    while (getline(file, s)) // 重载的自动调用的istream的getline，不是string的

    file.close();

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

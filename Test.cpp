//
// Created by yinlei on 17-7-7.
//
#include <iostream>
#include "Test.h"
#include <string>

void Test::test() {
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

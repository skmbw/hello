//
// Created by yinlei on 2020-4-26.
//

#ifndef HELLO_SCREEN_H
#define HELLO_SCREEN_H

#include <string>

/**
 * 屏幕类
 */
class Screen {
public:
    // 定义类型别名，要先定义，后面才能使用。一般也是定义在开头部分
    using pos = std::string::size_type;

    Screen() = default;

    Screen(pos height, pos width, char c) : height(height), width(width), contents(height * width, c) {}
    // 读取光标处的字符，这是一个隐式内联函数.定义在类内的函数是自动内联的
    char get() const {
        return contents[cursor];
    }
    // 显式声明成内联，和上一个是重载成员函数
    inline char get(pos rw, pos cur) const ;

    Screen &move(pos rw, pos cur);
    Screen & set(char c);
    Screen & set(pos h, pos w, char c);
private:
    pos cursor = 0;
    pos width = 0;
    pos height = 0;
    std::string contents;
};

// 内联函数一般要在.h头文件中定义
inline Screen &Screen::move(pos rw, pos cur) {
    pos row = rw * width; // 计算行的位置
    this->cursor = row + cur; // 移动光标到指定的位置
//    cursor = row + cur;
    return *this; // 返回当前屏幕的引用
}

char Screen::get(pos rw, pos cur) const {
    pos row = rw * width;
    return contents[row + cur];
}

inline Screen & Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}
#endif //HELLO_SCREEN_H

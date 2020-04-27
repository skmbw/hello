//
// Created by yinlei on 2020-4-26.
//

#ifndef HELLO_SCREEN_H
#define HELLO_SCREEN_H

#include <string>
#include "WindowMgr.h"

/**
 * 屏幕类
 */
class Screen {
    friend class WindowMgr;
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
    Screen & set(pos r, pos col, char ch);
    Screen & display(std::ostream &ostream) {
        do_display(ostream);
        return *this;
    }
    const Screen & display(std::ostream &ostream) const {
        do_display(ostream);
        return *this;
    }
private:
    pos cursor = 0;
    pos width = 0;
    pos height = 0;
    std::string contents;
    void do_display(std::ostream &ostream) const {
        ostream << contents;
    }
};

// 内联函数一般要在.h头文件中定义
inline Screen &Screen::move(pos rw, pos cur) {
    pos row = rw * width; // 计算行的位置
    this->cursor = row + cur; // 移动光标到指定的位置
//    cursor = row + cur;
    return *this; // 返回当前屏幕的引用
}

inline Screen & Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen & Screen::set(pos r, pos col, char ch) {
    contents[r * width + col] = ch; // 将ch赋值给指定位置的字符
    return *this;
}
#endif //HELLO_SCREEN_H

//
// Created by yinlei on 2020-4-26.
//

#ifndef HELLO_WINDOWMGR_H
#define HELLO_WINDOWMGR_H

#include <vector>
#include <string>
#include "Screen.h"

class WindowMgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex index);
private:
    // 默认有一个空白字符的屏
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};
#endif //HELLO_WINDOWMGR_H

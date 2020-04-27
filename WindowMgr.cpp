//
// Created by yinlei on 2020-4-27.
//
#include "WindowMgr.h"
#include <string>

void WindowMgr::clear(ScreenIndex index) {
    Screen &s = screens[index];
    // 将指定的Screen重置为空白
    s.contents = std::string(s.height * s.width, ' ');
}

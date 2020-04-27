//
// Created by yinlei on 2020-4-27.
//

#include "Screen.h"

char Screen::get(pos rw, pos cur) const {
    pos row = rw * width;
    return contents[row + cur];
}
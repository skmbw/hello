//
// Created by yinlei on 2020/4/19.
//

#include "Sales_item.h"
#include <iostream>

class AvgPrice {
public:
    int avg_price()
    {
        Sales_item total;
        // 读取第一个记录
        if (std::cin >> total) {
            Sales_item trans;
            // 读取第二条记录
            while (std::cin >> trans) {
                if (total.isbn() == trans.isbn()) {
                    total += trans;
                } else {
                    std::cout << total << std::endl;
                    total = trans;
                }
            }
            std::cout << total << std::endl;
        } else {
            std::cerr << "No data?!" << std::endl;
            return -1;
        }
        return 0;
    }
};



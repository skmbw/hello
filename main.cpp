#include <iostream>
//#include "opencv2/opencv.hpp"
#include "avg_price.h"
//#include <stdio.h>
#include "Test.h"

using namespace std;
//using namespace cv;

//#if !_ISOC11_SOURCE
//using ::gets;
//#endif
/**
 * C++数据类型的选用：
 * 1、明确知道非负，使用无符号的
 * 2、整形一般使用int，或者long long（short太小，long一般和int一样大），对应java的int和long
 * 3、算术表达式中不使用char或者bool，char在不同的机器上可能不同。
 * 4、浮点运算用double，float精度不够，long double没必要。
 *
 * @return
 */
int main() {
    Test test;
    test.test(); // 用于以后学习新知识测试
    std::string str("yinlei123");
    // string.size() 返回的是无符号的数据，不要和有符号的数进行比较
    if (str.size() > 1) { // 这个类型是 string::size_type
        std::cout << str << std::endl;
    }
    int a = -1 % 256; // = -1
    unsigned char cc = -1; // 超出0-255之间的数，会被循环赋值=（取模余数+数值范围）。数值范围是256，被除数÷除数=商……余数，余数=被除数-商×除数
//    int c = (-7)/(unsigned)4; // warning C4308: 负整型常量转换为无符号类型
    AvgPrice price;
    price.avg_price();
    std::cout << "Hello, World!" << std::endl;
    // 不要使用char* 去声明一个字符串，https://zhidao.baidu.com/question/534987671.html
    // 要用的话，也要使用const char * ab = "yinlei尹雷";
    char ab[] = "yinlei尹雷";
    cout << ab << endl;

    // 'printf'在此作用域中尚未声明，见
    // https://zhidao.baidu.com/question/390847449618643645.html
    printf("c style printf %s\n", ab); // 在stdio.h中

    string s = "yinqianxun尹雷"; // error C2001: 常量中有换行符，含有汉字‘尹千寻’就不行了？？
    string s2 = ab; // char数组就是字符串
//    string s2 = "zxvxzc";
    const char *s3 = s2.c_str();
    cout << s << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    unsigned ui = -1;
    cout << ui << endl;


//    cout << "开始切割" << endl;
//    Mat image = imread("/home/yinlei/ic.jpg", 1);
//    imshow("source", image);
////    MatSize matSize = image.size;
////    Mat image1(image.rows, image.cols, image.type(), Scalar(180, 120, 50));
//    Mat image1(image.rows, image.cols, image.type());
//    Mat image2(image.rows, image.cols, image.type(), Scalar(180, 120, 50));
////    Mat image2(image.rows, image.cols, image.type());
//    Point center(image.cols / 2, image.rows / 2);
//    int radius = 15;
//
//    // 图片、中心、半径、初始颜色、边线粗细、边界类型
//    circle(image, center, radius, Scalar(0, 200, 100), 0, 4, 0);
////    circle(image, center, radius, Scalar(255, 255, 255), 0, 8, 0);
//
//    for (int x = 0; x < image.cols; x++) {
//        for (int y = 0; y < image.rows; y++) {
//            int temp = ((x - center.x) * (x - center.x) + (y - center.y) * (y - center.y));
//            if (temp < (radius * radius)) {
//                image1.at<Vec3b>(Point(x, y))[0] = image.at<Vec3b>(Point(x, y))[0];
//                image1.at<Vec3b>(Point(x, y))[1] = image.at<Vec3b>(Point(x, y))[1];
//                image1.at<Vec3b>(Point(x, y))[2] = image.at<Vec3b>(Point(x, y))[2];
//            } else {
//                image2.at<Vec3b>(Point(x, y))[0] = image.at<Vec3b>(Point(x, y))[0];
//                image2.at<Vec3b>(Point(x, y))[1] = image.at<Vec3b>(Point(x, y))[1];
//                image2.at<Vec3b>(Point(x, y))[2] = image.at<Vec3b>(Point(x, y))[2];
//            }
//        }
//    }
//
//    imshow("image1", image1);
//    imshow("image2", image2);
//
//    while (uchar(waitKey() != 'q')) {}
    return 0;
}
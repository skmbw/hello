#include <iostream>
#include "opencv2/opencv.hpp"
//#include <stdio.h>

using namespace std;
using namespace cv;

//#if !_ISOC11_SOURCE
//using ::gets;
//#endif

int main() {
    std::cout << "Hello, World!" << std::endl;
    // 不要使用char* 去声明一个字符串，https://zhidao.baidu.com/question/534987671.html
    // 要用的话，也要使用const char * ab = "yinlei尹雷";
    char ab[] = "yinlei尹雷";
    cout << ab << endl;
    string s = "yinqianxun尹千寻";
    // 'printf'在此作用域中尚未声明，见
    // https://zhidao.baidu.com/question/390847449618643645.html
    printf("c style printf %s\n", ab); // 在stdio.h中

    // char数组就是字符串
    string s2 = ab;
    const char *s3 = s2.c_str();
    cout << s << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    unsigned ui = -1;
    cout << ui << endl;


    cout << "开始切割" << endl;
    Mat image = imread("/home/yinlei/ic.jpg", 1);
    imshow("source", image);
//    MatSize matSize = image.size;
//    Mat image1(image.rows, image.cols, image.type(), Scalar(180, 120, 50));
    Mat image1(image.rows, image.cols, image.type());
    Mat image2(image.rows, image.cols, image.type(), Scalar(180, 120, 50));
//    Mat image2(image.rows, image.cols, image.type());
    Point center(image.cols / 2, image.rows / 2);
    int radius = 15;

    // 图片、中心、半径、初始颜色、边线粗细、边界类型
    circle(image, center, radius, Scalar(0, 200, 100), 0, 4, 0);
//    circle(image, center, radius, Scalar(255, 255, 255), 0, 8, 0);

    for (int x = 0; x < image.cols; x++) {
        for (int y = 0; y < image.rows; y++) {
            int temp = ((x - center.x) * (x - center.x) + (y - center.y) * (y - center.y));
            if (temp < (radius * radius)) {
                image1.at<Vec3b>(Point(x, y))[0] = image.at<Vec3b>(Point(x, y))[0];
                image1.at<Vec3b>(Point(x, y))[1] = image.at<Vec3b>(Point(x, y))[1];
                image1.at<Vec3b>(Point(x, y))[2] = image.at<Vec3b>(Point(x, y))[2];
            } else {
                image2.at<Vec3b>(Point(x, y))[0] = image.at<Vec3b>(Point(x, y))[0];
                image2.at<Vec3b>(Point(x, y))[1] = image.at<Vec3b>(Point(x, y))[1];
                image2.at<Vec3b>(Point(x, y))[2] = image.at<Vec3b>(Point(x, y))[2];
            }
        }
    }

    imshow("image1", image1);
    imshow("image2", image2);

    while (uchar(waitKey() != 'q')) {}
    return 0;
}
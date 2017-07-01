#include <iostream>
//#include <stdio.h>

using namespace std;

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
    const char * s3 = s2.c_str();
    cout << s << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    unsigned ui = -1;
    cout << ui << endl;
    return 0;
}
#include <iostream>
#include "common.h"

bool isNumber(const char &c) { // 判断一个字符是否为是数字
    return c >= '0' && c <= '9';
}

// -a => 0 - a
std::string zero(std::string &str) { // 负号变减号
    std::string str2;
    for (int i=0; i<str.size(); i++) {
        if ((i==0 && str[i]=='-') || (str[i-1]=='(' && str[i]=='-'))
            str2.push_back('0');
        str2.push_back(str[i]);
    }
    return str2;
}

std::string delSpace(std::string &str) { // 消除空格
    std::string str2;
    for (int i=0; i<str.size(); i++) {
        if (str[i] != ' ')
            str2.push_back(str[i]);
    }
    return str2;
}

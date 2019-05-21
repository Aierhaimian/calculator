#include <iostream>
#include <string>
#include "common.h"
#include "calculator.h"

int main() {
    Calculator<double> c;
    std::string str;
    std::cout << "The Calculator for Terminal" << std::endl;
    while (std::getline(std::cin, str)) {
        std::string tmp;
        std::string infix, postfix;
        std::cout << str << std::endl;
        tmp = delSpace(str);
        std::cout << tmp << std::endl;
        infix = zero(tmp);
        std::cout << infix << std::endl;
        bool vaild = c.infix2postfix(infix, postfix);
        std::cout << vaild << " : " << postfix << std::endl;
        std:: cout << c.calculation(postfix) << std::endl;
    }
    return 0;
}

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <stack>

#include "common.h"


template<class T>
class Calculator {
public:
    double calculation(const std::string &postfix); // 后缀表达式计算
    bool infix2postfix(const std::string &infix, std::string &postfix); // 中缀表达式转后缀表达式
private:
    std::stack<double> number;
    std::stack<char> operate;
};

template<class T>
double Calculator<T>::calculation(const std::string &postfix) {
    if (postfix.empty())
        throw OperatorInvalidException();
    std::string str;
    double a, b;
    for (int i=0; i<postfix.size(); i++) {
        while ((postfix[i] >= '0' && postfix[i] <= '9') || postfix[i] == '.') {
            str.push_back(postfix[i++]);
            if (postfix[i] == ' ') {
                number.push(stod(str));
                str.clear();
            }
        }

        switch(postfix[i]) {
        case '+':
            a = number.top();
            number.pop();
            b = number.top();
            number.pop();
            number.push(b + a);
            break;
        case '-':
            a = number.top();
            number.pop();
            b = number.top();
            number.pop();
            number.push(b - a);
            break;
        case '*':
            a = number.top();
            number.pop();
            b = number.top();
            number.pop();
            number.push(b * a);
            break;
        case '/':
            a = number.top();
            number.pop();
            if (a == 0)
                throw DivisorIsZero();
            b = number.top();
            number.pop();
            number.push(b / a);
            break;
        default:
            break;
        }
    }
    a = number.top();
    number.pop();
    return a;
}

template<class T>
bool Calculator<T>::infix2postfix(const std::string &infix, std::string &postfix) {
    for (int i=0; i<infix.size(); i++) {
        while ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.') {
            postfix.push_back(infix[i++]);
            if (infix[i] < '0' || infix[i] > '9' || infix[i] != '.')
                postfix.push_back(' ');
        }
        
        switch(infix[i])
        {
        char tmp;
        case ')':
            tmp = operate.top();
            operate.pop();
            while (tmp != '(') {
                postfix.push_back(tmp);
                postfix.push_back(' ');
                tmp = operate.top();
                operate.pop();
            }
            break;

        case '+':
        case '-':
            if (operate.empty())
                operate.push(infix[i]);
            else {
                do {
                    tmp = operate.top();
                    if (tmp != '(') {
                        postfix.push_back(tmp);
                        postfix.push_back(' ');
                        operate.pop();
                    }
                }while(!operate.empty() && tmp != '(');
                operate.push(infix[i]);
            }
            break;

        case '*':
        case '/':
        case '(':
            operate.push(infix[i]);
            break;

        case '\0':
            break;

        default:
            throw OperatorInvalidException();
        }
    }

    while (!operate.empty()) {
        postfix.push_back(operate.top());
        postfix.push_back(' ');
        operate.pop();
    }
    return true;
}

#endif

#ifndef COMMON_H
#define COMMON_H

#include <iostream>

class Exception {
public:
    Exception() {
        msg = "Exception!";
    }

    virtual std::string Massage() {
        return msg;
    }
protected:
    std::string msg;
};

class OperatorInvalidException : public Exception {
public:
    OperatorInvalidException() {
        msg = "Operator invaild exception!";
    }
};

class DivisorIsZero : public Exception {
public:
    DivisorIsZero() {
        msg = "Divisor is zero!";
    }
};

bool isNumber(const char &c);

std::string zero(std::string &str);

std::string delSpace(std::string &str);

#endif

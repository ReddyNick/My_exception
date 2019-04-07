#ifndef MY_EXCEPTION_MY_EXCEPTION_H
#define MY_EXCEPTION_MY_EXCEPTION_H

#include <vector>

const int EXCEP_SIZE = 10;

class Myexception
{
public:
    char* message;
    static int size;

    Myexception();
    explicit Myexception(const char* str);
    ~Myexception();

    int print_err();
};


#endif //MY_EXCEPTION_MY_EXCEPTION_H

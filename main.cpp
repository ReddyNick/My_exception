#include <iostream>
#include "my_exception.h"

int f1(int a)
{
    try
    {
        if (a == 1)
            throw Myexception("a == 1 in f1");
    }

    catch (Myexception& excep)
    {
        throw;
    }
    return 0;
}

int f2(int a)
{
    try
    {
        if (a == 2)
            throw Myexception("a == 2");
        f1(a);
    }

    catch (Myexception& excep)
    {
        throw Myexception("error in f2");
    }

    return 0;
}

int f3(int a)
{
    try
    {
        if (a == 3)
            throw Myexception("a == 3");
        f2(a);
    }

    catch (Myexception& excep)
    {
        throw Myexception("error in f3");
    }

    return 0;
}

int main()
{
    try
    {
        f3(1);
    }

    catch (Myexception& excep)
    {
        excep.print_err();
    }


    std::cout << std::endl << "hi^^\n";
    return 0;
}
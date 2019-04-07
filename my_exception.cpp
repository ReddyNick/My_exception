#include "my_exception.h"
#include <string.h>
#include <stdio.h>
#include <cassert>
#include <vector>

int Myexception::size = 0;
std::vector<Myexception> exceptions(EXCEP_SIZE);

Myexception::Myexception():
             message(nullptr)
{}

Myexception::Myexception(const char *str)
{
    if (size == EXCEP_SIZE) return;

    exceptions[size].message = new char[strlen(str)];
    strcpy(exceptions[size].message, str);

    size++;
}

Myexception::~Myexception()
{
    delete[] message;
}

int Myexception::print_err()
{
    size--;

    printf("%s ", exceptions[size].message);
    size--;
    while (size >= 0)
    {
        printf("because %s ", exceptions[size].message);
        size--;
    }

    printf("\n");

    return 0;
}

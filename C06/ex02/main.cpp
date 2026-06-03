#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    Base* ptr = generate();

    std::cout << "identify pointer: ";
    identify(ptr);

    std::cout << "identify reference: ";
    identify(*ptr);

    delete ptr;

    return 0;
}
#include <iostream>
#include "Array.hpp"

int main()
{
    std::cout << "----- Empty array -----" << std::endl;
    Array<int> empty;
    std::cout << "size = " << empty.size() << std::endl;

    std::cout << "\n----- Array<int>(5) -----" << std::endl;
    Array<int> a(5);

    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "\n----- Fill array -----" << std::endl;
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i * 10;

    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "\n----- Copy constructor -----" << std::endl;
    Array<int> b(a);

    a[0] = 42;

    std::cout << "a[0] = " << a[0] << std::endl;
    std::cout << "b[0] = " << b[0] << std::endl;

    std::cout << "\n----- Assignment operator -----" << std::endl;
    Array<int> c;

    c = a;

    a[1] = 100;

    std::cout << "a[1] = " << a[1] << std::endl;
    std::cout << "c[1] = " << c[1] << std::endl;

    std::cout << "\n----- Out of bounds -----" << std::endl;

    try
    {
        std::cout << a[10] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught" << std::endl;
    }

    return 0;
}

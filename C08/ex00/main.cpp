#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
    try
    {
        std::vector<int> v;

        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        std::vector<int>::iterator it = easyfind(v, 20);

        std::cout << "Vector: found " << *it << std::endl; 
    }
    catch (std::exception& e)
    {
        std::cout << "vector: " << e.what() << std::endl;
    }

    try
    {
        std::list<int> l;

        l.push_back(5);
        l.push_back(15);
        l.push_back(25);

        std::list<int>::iterator it = easyfind(l, 15);

        std::cout << "list: found " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "list: " << e.what() << std::endl;
    }

    try
    {
        std::deque<int> d;
        
        d.push_back(1);
        d.push_back(2);
        d.push_back(3);

        std::deque<int>::iterator it = easyfind(d, 99);
        
        std::cout << "Deque: found " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "deque: " << e.what() << std::endl;
    }

    return 0;

}

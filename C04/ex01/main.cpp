
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== 1) ARRAY TEST (Dog/Cat as Animal*) ===" << std::endl;

    const int N = 10;
    Animal* animals[N];

    for (int i = 0; i < N / 2; i++)
        animals[i] = new Dog();
    for (int i = N / 2; i < N; i++)
        animals[i] = new Cat();

    for (int i = 0; i < N; i++)
        delete animals[i];

    std::cout << "\n=== 2) DEEP COPY TEST (Dog) ===" << std::endl;

    Dog original;
    original.setIdea(0, "I love bones");

    Dog copy = original; // copy constructor (deep copy)

    original.setIdea(0, "CHANGED IDEA");

    std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;
    std::cout << "Copy idea[0]:     " << copy.getIdea(0) << std::endl;

    std::cout << "\n=== 3) DEEP COPY TEST (Cat operator=) ===" << std::endl;

    Cat c1;
    c1.setIdea(1, "I rule the house");

    Cat c2;
    c2 = c1; // operator= (deep copy)

    c1.setIdea(1, "CHANGED CAT IDEA");

    std::cout << "c1 idea[1]: " << c1.getIdea(1) << std::endl;
    std::cout << "c2 idea[1]: " << c2.getIdea(1) << std::endl;

    return 0;
}

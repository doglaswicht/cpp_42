#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "Objets Directs" << std::endl;

    Dog dog;
    Cat cat;

    dog.makeSound();   
    cat.makeSound();   


    std::cout << "\n Nice polimorphism (virtual)" << std::endl;

    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->makeSound();  
    a2->makeSound(); 

    delete a1;
    delete a2;


    std::cout << "\nBad polimorphism (no virtual)" << std::endl;

    WrongAnimal* w1 = new WrongCat();

    w1->makeSound();   

    delete w1;


    std::cout << "\n Reference BASE" << std::endl;

    Dog d2;
    Animal& ref = d2;

    ref.makeSound(); 


    std::cout << "\n Program finished " << std::endl;

    return 0;
}

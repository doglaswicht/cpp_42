#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Cat : public Animal
{
	private:
		Brain* brain_;
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		virtual ~Cat();

		virtual void makeSound() const;
		void setIdea(int, const std::string&);
		std::string getIdea(int) const;

};

#endif

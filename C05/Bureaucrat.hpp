#ifndef BUREAUCRAT_
#define BUREAUCRAT_
#include <string>

class Bureaucrat
{
	private:
		const std::string name_;
		int	grade_;
	public:
		Bureucrat (const std::string& name, int grade);
		Bureucrat (const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		
		const std::string& getName()const;
		getGrade();
};

#endif

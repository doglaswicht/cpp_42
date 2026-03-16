#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "===== TEST 1: valid Form =====" << std::endl;
	try
	{
		Form taxForm("TaxForm", 50, 25);
		std::cout << taxForm << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 2: invalid Form =====" << std::endl;
	try
	{
		Form invalidForm("InvalidForm", 0, 200);
		std::cout << invalidForm << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 3: Bureaucrat signs successfully =====" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 10);
		Form contract("Contract", 20, 10);

		std::cout << boss << std::endl;
		std::cout << contract << std::endl;

		boss.signForm(contract);

		std::cout << contract << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 4: Bureaucrat fails to sign =====" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 100);
		Form secretForm("SecretForm", 50, 25);

		std::cout << intern << std::endl;
		std::cout << secretForm << std::endl;

		intern.signForm(secretForm);

		std::cout << secretForm << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
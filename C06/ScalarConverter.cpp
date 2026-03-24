/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 10:56:01 by dleite-b          #+#    #+#             */
/*   Updated: 2026/03/23 17:40:24 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

static bool isPseudoLiteral(const std::string& s)
{
	return (s == "nan" || s == "nanf"
		|| s == "+inf" || s == "-inf"
		|| s == "+inff" || s == "-inff");
}

static bool isCharLiteral(const std::string& s)
{
	return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

static bool isIntLiteral(const std::string& s)
{
	size_t	i;

	if (s.empty())
		return (false);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i == s.length())
		return (false);
	while (i < s.length())
	{
		if (!std::isdigit(s[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool isFloatLiteral(const std::string& s)
{
	size_t	i;
	bool	hasDot;
	bool	hasDigit;

	if (s.length() < 2 || s[s.length() - 1] != 'f')
		return (false);
	i = 0;
	hasDot = false;
	hasDigit = false;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (i < s.length() - 1)
	{
		if (s[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		}
		else if (std::isdigit(s[i]))
			hasDigit = true;
		else
			return (false);
		i++;
	}
	return (hasDot && hasDigit);
}

static bool isDoubleLiteral(const std::string& s)
{
	size_t	i;
	bool	hasDot;
	bool	hasDigit;

	if (s.empty())
		return (false);
	i = 0;
	hasDot = false;
	hasDigit = false;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i == s.length())
		return (false);
	while (i < s.length())
	{
		if (s[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		}
		else if (std::isdigit(s[i]))
			hasDigit = true;
		else
			return (false);
		i++;
	}
	return (hasDot && hasDigit);
}

static void printConversions(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value)
		|| value < std::numeric_limits<char>::min()
		|| value > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value)
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;

	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
	{
		if (value < 0)
			std::cout << "-inff" << std::endl;
		else
			std::cout << "+inff" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1)
			<< static_cast<float>(value) << "f" << std::endl;

	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
	{
		if (value < 0)
			std::cout << "-inf" << std::endl;
		else
			std::cout << "+inf" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1)
			<< value << std::endl;
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string& literal)
{
	double	value;

	if (isPseudoLiteral(literal))
	{
		if (literal == "nan" || literal == "nanf")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "-inf" || literal == "-inff")
			value = -std::numeric_limits<double>::infinity();
		else
			value = std::numeric_limits<double>::infinity();
		printConversions(value);
	}
	else if (isCharLiteral(literal))
	{
		value = static_cast<double>(literal[1]);
		printConversions(value);
	}
	else if (isIntLiteral(literal))
	{
		value = std::strtod(literal.c_str(), NULL);
		printConversions(value);
	}
	else if (isFloatLiteral(literal))
	{
		value = std::strtod(literal.c_str(), NULL);
		printConversions(value);
	}
	else if (isDoubleLiteral(literal))
	{
		value = std::strtod(literal.c_str(), NULL);
		printConversions(value);
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 10:56:01 by dleite-b          #+#    #+#             */
/*   Updated: 2026/06/03 11:42:46 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter(){}


ScalarConverter::Type ScalarConverter::detectType(const std::string& literal)
{
    if (literal == "nan" || literal == "+inf" || literal == "-inf" ||
        literal == "nanf" || literal == "+inff" || literal == "-inff")
        return SPECIAL;

    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        if (literal[0] == '+' || literal[0] == '-' ||
            literal[0] == '.' || literal[0] == 'f')
            return INVALID;
        return CHAR;
    }

    bool hasDot = false;
    bool hasF = false;
    bool hasDigit = false;
    unsigned int i = 0;

    if (literal[i] == '+' || literal[i] == '-')
        i++;

    for (; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            if (hasDot)
                return INVALID;
            hasDot = true;
        }
        else if (literal[i] == 'f')
        {
            if (i != literal.length() - 1)
                return INVALID;
            hasF = true;
        }
        else if (std::isdigit(literal[i]))
            hasDigit = true;
        else
            return INVALID;
    }

    if (!hasDigit)
        return INVALID;

    if (hasF)
    {
        if (!hasDot)
            return INVALID;
        return FLOAT;
    }

    if (hasDot)
        return DOUBLE;

    return INT;
}


void ScalarConverter::convert(std::string const &literal)
{
    Type type = detectType(literal);
    double value;

    if(type == INVALID)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    if (type == CHAR)
        value = static_cast<double>(literal[0]);
    else if (literal == "nan" || literal == "nanf")
        value = std::numeric_limits<double>::quiet_NaN();
    else if (literal == "+inf" || literal == "+inff")
        value = std::numeric_limits<double>::infinity();
    else if (literal == "-inf" || literal == "-inff")
        value = -std::numeric_limits<double>::infinity();
    else
        value = std::strtod(literal.c_str(), NULL);
    
    printChar(value);
    
    
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void    ScalarConverter::printChar(double value)
{
    if(std::isnan(value) || std::isinf(value))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    if(value < 0 || value > 127)
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(value);

    if(!std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::printInt(double value)
{
    if(std::isnan(value) || std::isinf(value))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }

    if(value < std::numeric_limits<int>::min() || 
        value > std::numeric_limits<int>::max())
        {
            std::cout << "int: impossible" << std::endl;
            return;
        }
    std::cout << "int: " << static_cast<int>(value) << std::endl;


}

void ScalarConverter::printFloat(double value)
{
    float f = static_cast<float>(value);

    std::cout << "float: " << std::fixed << std::setprecision(1)
            << f << "f" << std::endl;

}

void ScalarConverter::printDouble(double value)
{
    std::cout << "double: " << std::fixed << std::setprecision(1)
            << value << std::endl;
}
/*

    else if(type == INT )
        std::cout << "IS INT" << std::endl;
    else if(type == DOUBLE )
        std::cout << "IS DOUBLE" << std::endl;
    else if(type == SPECIAL )
        std::cout << "IS SPECIAL" << std::endl;
    else if(type == FLOAT )
        std::cout << "IS FLOAT" << std::endl;
    else
        std::cout << "IS INVALID" << std::endl;
*/

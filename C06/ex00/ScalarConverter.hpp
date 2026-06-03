/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 10:56:04 by dleite-b          #+#    #+#             */
/*   Updated: 2026/06/03 11:41:59 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
    private:
        enum Type
        {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            SPECIAL,
            INVALID
        };
        
        ScalarConverter();
        ScalarConverter(ScalarConverter const &other);
        ScalarConverter& operator=(ScalarConverter const &other);
        ~ScalarConverter();
        
        static Type detectType(std::string const &literal);

        static void printChar(double value);
        static void printInt(double value);
        static void printFloat(double value);
        static void printDouble(double value);

        
    public:
        static void convert(std::string const &literal);
        
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:33:42 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/11 15:33:43 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	_rawBits = 0;
}

Fixed::Fixed(const Fixed& other)
{
	_rawBits = other.getRawBits();
}

Fixed& Fixed::operator = (const Fixed& other)
{
	if(this != &other)
		_rawBits = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed::Fixed(const int value)
{
	_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	_rawBits = (int)roundf(value * 256);
}

float Fixed::toFloat(void) const
{
	return(float)_rawBits / 256;
}

int Fixed::toInt(void) const
{
	return _rawBits >> _fractionalBits;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->_rawBits + other._rawBits);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->_rawBits - other._rawBits);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    long long raw = (long long)this->_rawBits * other._rawBits;
    result.setRawBits((int)(raw >> _fractionalBits));
    return result;
}


Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	if (other._rawBits == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return result; 
	}
	long long temp = ((long long)this->_rawBits << _fractionalBits) / (long long)other._rawBits;
	result.setRawBits((int)temp);
	return result;
}

bool Fixed::operator>(const Fixed& other) const
{
    return this->_rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->_rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->_rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->_rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->_rawBits != other._rawBits;
}

Fixed& Fixed::operator++()
{
    this->_rawBits += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_rawBits += 1;
    return temp;
}

Fixed& Fixed::operator--()
{
    this->_rawBits -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_rawBits -= 1;
    return temp;
}


Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

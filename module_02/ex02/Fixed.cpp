/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:24:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/29 19:05:43 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) :
	_value(0)
{
	std::cout
		<< "Default constructor called"
		<< std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout
		<< "Copy constructor called"
		<< std::endl;

	*this = fixed;
}

Fixed::Fixed(const int value) :
	_value(value << Fixed::_bits)
{
	std::cout
		<< "Int constructor called"
		<< std::endl;
}

Fixed::Fixed(const float value) :
	_value(roundf(value * (1 << Fixed::_bits)))
{
	std::cout
		<< "Float constructor called"
		<< std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout
		<< "Copy assignment operator called"
		<< std::endl;

	if (this != &fixed)
		_value = fixed.getRawBits();

	return *this;
}

Fixed::~Fixed(void)
{
	std::cout
		<< "Destructor called"
		<< std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout
		<< "getRawBits function called"
		<< std::endl;

	return _value;
}

void Fixed::setRawBits(int const value)
{
	std::cout
		<< "setRawBits function called"
		<< std::endl;

	_value = value;
}

int Fixed::toInt(void) const
{
	return _value >> _bits;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << Fixed::_bits);
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return _value < fixed.getRawBits();
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return _value > fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return _value <= fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return _value >= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return _value == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return _value != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed)
{
	return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed)
{
	return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed)
{
	return Fixed(toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(void)
{
	_value++;

	return *this;
}

Fixed Fixed::operator++(int)
{
	return Fixed(toFloat() * _value++);
}

Fixed &Fixed::operator--(void)
{
	_value--;

	return *this;
}

Fixed Fixed::operator--(int)
{
	return Fixed(toFloat() * _value--);
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1.getRawBits() < fixed2.getRawBits()) ? fixed1 : fixed2;
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.getRawBits() < fixed2.getRawBits()) ? fixed1 : fixed2;
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1.getRawBits() > fixed2.getRawBits()) ? fixed1 : fixed2;
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.getRawBits() > fixed2.getRawBits()) ? fixed1 : fixed2;
}

std::ostream &operator<<(std::ostream &os, const Fixed &value)
{
	return os << value.toFloat();
}

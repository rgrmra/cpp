/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:24:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/29 18:17:58 by rde-mour         ###   ########.org.br   */
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

	return _value;;
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
	return _value >> Fixed::_bits;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << Fixed::_bits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &value)
{
	return os << value.toFloat();
}

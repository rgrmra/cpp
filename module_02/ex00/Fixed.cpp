/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:24:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/24 18:52:41 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
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

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout
		<< "Copy assignment operator called"
		<< std::endl;

	if (this != &fixed)
		this->_value = fixed.getRawBits();

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

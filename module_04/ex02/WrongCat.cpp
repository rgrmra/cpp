/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:28:11 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/02 10:40:04 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat(void) :
	WrongAnimal()
{
	std::cout
		<< "WrongCat default constructor called"
		<< std::endl;

	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &wrongcat) :
	WrongAnimal(wrongcat)
{
	std::cout
		<< "WrongCat copy constructor called"
		<< std::endl;

	*this = wrongcat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat)
{
	std::cout
		<< "WrongCat copy assignment operator called"
		<< std::endl;

	if (this != &wrongcat)
		_type = wrongcat._type;

	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout
		<< "WrongCat destructor called"
		<< std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout
		<< "WrongCat sound"
		<< std::endl;
}

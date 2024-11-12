/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:18:31 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/12 09:36:21 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal(void) :
	_type("Generic Wrong Animal")
{
	std::cout
	<< "WrongAnimal default constructor called"
	<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal)
{
	std::cout
		<< "WrongAnimal copy constructor called"
		<< std::endl;

	*this = wronganimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wronganimal)
{
	std::cout
		<< "WrongAnimal copy assignment operator called"
		<< std::endl;

	if (this == &wronganimal)
		return *this;

	_type = wronganimal._type;

	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout
		<< "WrongAnimal destructor called"
		<< std::endl;
}

const std::string WrongAnimal::get_type(void) const
{
	return _type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout
		<< "Generic WrongAnimal sound"
		<< std::endl;
}

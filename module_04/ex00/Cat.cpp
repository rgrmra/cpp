/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:38:38 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/01 18:45:26 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat(void)
{
	std::cout
		<< "Cat default constructor called"
		<< std::endl;

	_type = "Cat";
}

Cat::Cat(const Cat &cat) :
	Animal(cat)
{
	std::cout
		<< "Cat copy constructor called"
		<< std::endl;

	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout
		<< "Cat copy assignment constructor called"
		<< std::endl;

	if (this != &cat)
		_type = cat._type;

	return *this;
}

Cat::~Cat(void)
{
	std::cout
		<< "Cat destructor called"
		<< std::endl;
}

void Cat::makeSound(void) const
{
	std::cout
		<< "The Cat meows!"
		<< std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:38:38 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/02 11:19:26 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat(void)
{
	std::cout
		<< "Cat default constructor called"
		<< std::endl;

	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &cat) :
	Animal(cat)
{
	std::cout
		<< "Cat copy constructor called"
		<< std::endl;

	_brain = new Brain();

	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout
		<< "Cat copy assignment operator called"
		<< std::endl;

	if (this != &cat)
	{
		_type = cat._type;
		*_brain = *cat._brain;
	}

	return *this;
}

Cat::~Cat(void)
{
	std::cout
		<< "Cat destructor called"
		<< std::endl;

	delete _brain;
}

void Cat::makeSound(void) const
{
	std::cout
		<< "The Cat meows!"
		<< std::endl;
}

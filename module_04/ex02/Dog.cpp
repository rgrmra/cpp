/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:27:13 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/02 11:45:00 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(void)
{
	std::cout
		<< "Dog default constructor called"
		<< std::endl;

	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &dog) :
	Animal(dog)
{
	std::cout
		<< "Dog copy constructor called"
		<< std::endl;

	_brain = new Brain();

	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout
		<< "Dog copy assignment operator called"
		<< std::endl;

	if (this != &dog)
	{
		_type = dog._type;
		*_brain = *dog._brain;
	}

	return *this;
}

Dog::~Dog(void)
{
	std::cout
		<< "Dog destructor called"
		<< std::endl;

	delete _brain;
}

void Dog::makeSound(void) const
{
	std::cout
		<< "The Dog barks!"
		<< std::endl;
}

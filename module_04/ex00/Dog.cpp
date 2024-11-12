/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:27:13 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/12 08:49:00 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	std::cout
		<< "Dog default constructor called"
		<< std::endl;

	_type = "Dog";
}

Dog::Dog(const Dog &dog) :
	Animal(dog)
{
	std::cout
		<< "Dog copy constructor called"
		<< std::endl;

	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout
		<< "Dog copy assignment operator called"
		<< std::endl;

	if (this == &dog)
		return *this;

	_type = dog._type;

	return *this;
}

Dog::~Dog(void)
{
	std::cout
		<< "Dog destructor called"
		<< std::endl;
}

void Dog::makeSound(void) const
{
	std::cout
		<< "The Dog barks!"
		<< std::endl;
}

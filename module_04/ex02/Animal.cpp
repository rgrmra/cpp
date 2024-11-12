/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:04:15 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/12 09:35:10 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) :
	_type("Generic Animal")
{
	std::cout
		<< "Animal default constructor called"
		<< std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout
		<< "Animal copy constructor called"
		<< std::endl;

	*this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout
		<< "Animal copy assignment operator called"
		<< std::endl;

	if (this == &animal)
		return *this;

	_type = animal._type;
	
	return *this;
}

Animal::~Animal(void)
{
	std::cout
		<< "Animal destructor called"
		<< std::endl;
}

const std::string Animal::get_type(void) const
{
	return _type;
}

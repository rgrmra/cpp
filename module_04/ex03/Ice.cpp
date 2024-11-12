/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:50:47 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/12 14:15:13 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include <iostream>

Ice::Ice(void) :
	AMateria("ice")
{
	std::cout
		<< "Ice default constructor called"
		<< std::endl;
}

Ice::Ice(const Ice &ice) :
	AMateria(ice)
{
	std::cout
		<< "Ice copy constructor called"
		<< std::endl;

	*this = ice;
}

Ice &Ice::operator=(const Ice &ice)
{
	std::cout
		<< "Ice copy assignment operator called"
		<< std::endl;

	if (this == &ice)
		return *this;
	
	_type = ice._type;

	return *this;
}

Ice::~Ice(void)
{
	std::cout
		<< "Ice destructor called"
		<< std::endl;
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout
		<< "* shoots an ice bolt at " << target.getName() << " *"
		<< std::endl;
}

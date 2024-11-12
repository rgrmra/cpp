/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:48:10 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/12 19:53:26 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Fire.hpp"
#include "AMateria.hpp"
#include <iostream>

Fire::Fire(void) :
	AMateria("fire")
{
	std::cout
		<< "Fire default constructor called"
		<< std::endl;
}

Fire::Fire(const Fire &fire) :
	AMateria(fire)
{
	std::cout
		<< "Fire copy constructor called"
		<< std::endl;

	*this = fire;
}

Fire &Fire::operator=(const Fire &fire)
{
	std::cout
		<< "Fire copy assignment operator called"
		<< std::endl;

	if (this == &fire)
		return *this;
	
	_type = fire._type;

	return *this;
}

Fire::~Fire(void)
{
	std::cout
		<< "Fire destructor called"
		<< std::endl;
}

AMateria *Fire::clone() const
{
	return new Fire(*this);
}

void Fire::use(ICharacter &target)
{
	std::cout
		<< "* puts fire in " << target.getName() << " *"
		<< std::endl;
}


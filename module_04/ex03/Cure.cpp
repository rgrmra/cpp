/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:08:59 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/02 16:13:57 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure(void) :
	AMateria("cure")
{
	std::cout
		<< "Cure default constructor called"
		<< std::endl;
}

Cure::Cure(const Cure &cure) :
	AMateria(cure)
{
	std::cout
		<< "Cure copy constructor called"
		<< std::endl;

	*this = cure;
}

Cure &Cure::operator=(const Cure &cure)
{
	std::cout
		<< "Cure copy assignment operator called"
		<< std::endl;

	if (this != &cure)
		_type = cure._type;

	return *this;
}

Cure::~Cure(void)
{
	std::cout
		<< "Cure destructor called"
		<< std::endl;
}

AMateria *Cure::clone(void) const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout
		<< "* heals " << target.getName() << "'s wounds *"
		<< std::endl;
}

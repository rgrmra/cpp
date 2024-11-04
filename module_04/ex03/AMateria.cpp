/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:51:10 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/02 21:13:09 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

AMateria::AMateria(void) :
	_type("unknow")
{
	std::cout
		<< "AMateria default constructor called"
		<< std::endl;
}

AMateria::AMateria(const std::string &type) :
	_type(type)
{
	std::cout
		<< "AMateria default parameterized constructor called"
		<< std::endl;
}

AMateria::AMateria(const AMateria &src)
{
	std::cout
		<< "AMateria copy constructor called"
		<< std::endl;

	*this = src;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	std::cout
		<< "AMateria copy assignment operator called"
		<< std::endl;

	if (this != &rhs)
		_type = rhs._type;
	
	return *this;
}

AMateria::~AMateria(void)
{
	std::cout
		<< "AMateria destructor called"
		<< std::endl;
}

const std::string &AMateria::getType(void) const
{
	return _type;;
}

void AMateria::use(ICharacter& target)
{
	std::cout
		<< "Not in use yet for " << target.getName()
		<< std::endl;
}

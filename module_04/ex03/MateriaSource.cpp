/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:15:01 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/02 19:42:58 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

MateriaSource::MateriaSource(void)
{
	std::cout
		<< "MateriaSource default constructor called"
		<< std::endl;

	for (size_t i = 0; i < MATERIASOURCE_INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	std::cout
		<< "MateriaSource copy constructor called"
		<< std::endl;

	*this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	std::cout
		<< "MateriaSource copy assignment constructor called"
		<< std::endl;

	if (this == &rhs)
		return *this;

	for (size_t i = 0; i < MATERIASOURCE_INVENTORY_SIZE; i++)
		_inventory[i] = _inventory[i] ? rhs._inventory[i]->clone() : NULL;

	return *this;
}

MateriaSource::~MateriaSource(void)
{
	std::cout
		<< "MateriaSource destructor called"
		<< std::endl;

	for (size_t i = 0; i < MATERIASOURCE_INVENTORY_SIZE; i++)
		delete _inventory[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (size_t i = 0; i < MATERIASOURCE_INVENTORY_SIZE; i++)
	{
		if (_inventory[i])
			continue ;
		
		_inventory[i] = m;
		break ;
	}
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (size_t i = 0; i < MATERIASOURCE_INVENTORY_SIZE; i++)
	{
		if (not _inventory[i] || _inventory[i]->getType() != type)
			continue ;

		return _inventory[i]->clone();
	}

	return NULL;
}

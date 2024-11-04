/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:32:06 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/02 20:59:01 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

Character::Character(void) :
	_name("unknow")
{
	std::cout
		<< "Character default constructor called"
		<< std::endl;

	for (size_t i = 0; i < CHARACTER_INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string &name) :
	_name(name)
{
	std::cout
		<< "Character default parameterized constructor called"
		<< std::endl;

	for (size_t i = 0; i < CHARACTER_INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &character)
{
	std::cout
		<< "Character copy constructor called"
		<< std::endl;

	*this = character;
}

Character &Character::operator=(const Character &character)
{
	std::cout
		<< "Character copy assignmnet operator called"
		<< std::endl;

	if (this == &character)
		return *this;

	_name = character._name;

	for (size_t i = 0; i < CHARACTER_INVENTORY_SIZE; i++)
		_inventory[i] = _inventory[i] ? character._inventory[i]->clone() : NULL;

	return *this;
}

Character::~Character(void)
{
	std::cout
		<< "Character destructor called"
		<< std::endl;

	for (size_t i = 0; i < CHARACTER_INVENTORY_SIZE; i++)
		delete _inventory[i];
}

const std::string &Character::getName(void) const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	for (size_t i = 0; i < CHARACTER_INVENTORY_SIZE; i++)
	{
		if (_inventory[i])
			continue ;

		_inventory[i] = m;
		break ;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= CHARACTER_INVENTORY_SIZE)
		return ;

	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= CHARACTER_INVENTORY_SIZE)
		return ;

	if (not _inventory[idx])
		return ;

	_inventory[idx]->use(target);

}

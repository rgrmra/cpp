/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:17:59 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/11 19:21:39 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(void) :
	ClapTrap(DIAMOND_SUFFIX(static_cast<std::string>("unknow")))
{
	std::cout
		<< "DiamondTrap default constructor called"
		<< std::endl;

	_name = "unknow";
	_hit_points = FRAGTRAP_HIT_POINTS;
	_energy_points = SCAVTRAP_ENERGY_POINTS;
	_attack_damage = FRAGTRAP_ATTACK_DAMAGE;
}

DiamondTrap::DiamondTrap(const std::string name) :
	ClapTrap(DIAMOND_SUFFIX(static_cast<std::string>(name))),
	_name(name)
{
	std::cout
		<< "DiamondTrap default parameterized constructor called"
		<< std::endl;

	_hit_points = FRAGTRAP_HIT_POINTS;
	_energy_points = SCAVTRAP_ENERGY_POINTS;
	_attack_damage = FRAGTRAP_ATTACK_DAMAGE;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap) :
	ClapTrap(diamondtrap),
	ScavTrap(diamondtrap),
	FragTrap(diamondtrap)
{
	std::cout
		<< "DiamondTrap copy constructor called"
		<< std::endl;

	*this = diamondtrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
	std::cout
		<< "DiamondTrap copy assignment operator called"
		<< std::endl;

	if (this != &diamondtrap)
	{
		_name = diamondtrap._name;
		_hit_points = diamondtrap._hit_points;
		_energy_points = diamondtrap._energy_points;
		_attack_damage = diamondtrap._attack_damage;
	}

	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout
		<< "DiamondTrap destructor called"
		<< std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout
		<< "DiamondTrap: I'm " << _name
		<< " and ClapTrap is " << ClapTrap::_name
		<< std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:15:13 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/01 16:10:47 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) :
	ClapTrap()
{
	std::cout
		<< "ScavTrap default constructor called"
		<< std::endl;

	_hit_points = SCAVTRAP_HIT_POINTS;
	_energy_points = SCAVTRAP_ENERGY_POINTS;
	_attack_damage = SCAVTRAP_ATTACK_DAMAGE;
}

ScavTrap::ScavTrap(std::string name) :
	ClapTrap(name)
{
	std::cout
		<< "ScavTrap default parameterized constructor called"
		<< std::endl;

	_hit_points = SCAVTRAP_HIT_POINTS;
	_energy_points = SCAVTRAP_ENERGY_POINTS;
	_attack_damage = SCAVTRAP_ATTACK_DAMAGE;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) :
	ClapTrap(scavtrap)
{
	std::cout
		<< "ScavTrap copy constructor called"
		<< std::endl;

	*this = scavtrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
	std::cout
		<< "ScavTrap copy assignment operator called"
		<< std::endl;
	
	if (this != &scavtrap)
	{
		_name = scavtrap._name;
		_hit_points = scavtrap._hit_points;
		_energy_points = scavtrap._energy_points;
		_attack_damage = scavtrap._attack_damage;
	}

	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout
		<< "ScavTrap destructor called"
		<< std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (not has_hit_points("ScavTrap"))
		return ;

	if (not has_energy_points("ScavTrap"))
		return ;

	if (not has_attack_damage("ScavTrap"))
		return ;

	std::cout
		<< "ScavTrap " << _name
		<< " attacks " << (not target.empty() ? target : "unnamed")
		<< ", causing " << _attack_damage << " points of damage!"
		<< std::endl;

	_energy_points--;
}

void ScavTrap::guardGate(void)
{
	if (not has_hit_points("ScavTrap"))
		return ;

	if (not has_energy_points("ScavTrap"))
		return ;

	std::cout
		<< "ScavTrap " << _name
		<< " is now in Gate Keeper Mode."
		<< std::endl;
}

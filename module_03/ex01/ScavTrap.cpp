/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:15:13 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/01 11:13:22 by rde-mour         ###   ########.org.br   */
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

	set_hit_points(100);
	set_energy_points(50);
	set_attack_damage(20);
}

ScavTrap::ScavTrap(std::string name) :
	ClapTrap(name)
{
	std::cout
		<< "ScavTrap default parameterized constructor called"
		<< std::endl;

	set_hit_points(100);
	set_energy_points(50);
	set_attack_damage(20);
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
		set_name(scavtrap.get_name());
		set_hit_points(scavtrap.get_hit_points());
		set_energy_points(scavtrap.get_energy_points());
		set_attack_damage(scavtrap.get_attack_damage());
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
	if (not has_hit_points())
		return ;

	if (not has_energy_points())
		return ;

	if (not has_attack_damage())
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
	std::cout
		<< "ScavTrap " << _name
		<< " is now in Gate Keeper Mode."
		<< std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:22:20 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/11 18:51:32 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(void) :
	ClapTrap()
{
	std::cout
		<< "FragTrap default constructor called"
		<< std::endl;

	_hit_points = FRAGTRAP_HIT_POINTS;
	_energy_points = FRAGTRAP_ENERGY_POINTS;
	_attack_damage = FRAGTRAP_ATTACK_DAMAGE;
}

FragTrap::FragTrap(const std::string name) :
	ClapTrap(name)
{
	std::cout
		<< "FragTrap default parameterized constructor called"
		<< std:: endl;

	_hit_points = FRAGTRAP_HIT_POINTS;
	_energy_points = FRAGTRAP_ENERGY_POINTS;
	_attack_damage = FRAGTRAP_ATTACK_DAMAGE;
}

FragTrap::FragTrap(const FragTrap &fragtrap) :
	ClapTrap(fragtrap)
{
	std::cout
		<< "FragTrap copy constructor called"
		<< std::endl;

	*this = fragtrap;
}


FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
	
	std::cout
		<< "FragTrap copy assignment operator called"
		<< std::endl;

	if (this != &fragtrap)
	{
		_name = fragtrap._name;
		_hit_points = fragtrap._hit_points;
		_energy_points = fragtrap._energy_points;
		_attack_damage = fragtrap._attack_damage;
	}

	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout
		<< "FragTrap destructor called"
		<< std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (not _hit_points)
		return log("attack: FragTrap " + _name + " is dead!");

	if (not _energy_points)
		return log("attack: FragTrap " + _name + " has no energy!");

	std::cout
		<< "FragTrap " << _name
		<< " attacks " << (not target.empty() ? target : "unnamed")
		<< ", causing " << _attack_damage << " points of damage!"
		<< std::endl;

	_energy_points--;
}

void FragTrap::highFivesGuys(void)
{
	if (not _hit_points)
		return log("highFivesGuys: FragTrap " + _name + " is dead!");

	if (not _energy_points)
		return log("highFivesGuys: FragTrap " + _name + " has no energy!");

	std::cout
		<< "FragTrap raises his hand for a high-five!"
		<< std::endl;
}

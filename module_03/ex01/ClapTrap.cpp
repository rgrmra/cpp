/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:03:36 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/11 19:42:22 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) :
	_name("unknow"),
	_hit_points(CLAPTRAP_HIT_POINTS),
	_energy_points(CLAPTRAP_ENERGY_POINTS),
	_attack_damage(CLAPTRAP_ATTACK_DAMAGE)
{
	std::cout
		<< "ClapTrap default constructor called"
		<< std::endl;
}

ClapTrap::ClapTrap(std::string name) :
	_name(name),
	_hit_points(CLAPTRAP_HIT_POINTS),
	_energy_points(CLAPTRAP_ENERGY_POINTS),
	_attack_damage(CLAPTRAP_ATTACK_DAMAGE)
{
	std::cout
		<< "ClapTrap default parameterized constructor called"
		<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	std::cout
		<< "ClapTrap copy constructor called"
		<< std::endl;

	*this = claptrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	std::cout
		<< "ClapTrap copy assignment operator called"
		<< std::endl;

	if (this != &claptrap)
	{
		_name = claptrap._name;
		_hit_points = claptrap._hit_points;
		_energy_points = claptrap._energy_points;
		_attack_damage = claptrap._attack_damage;
	}

	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout
		<< "ClapTrap destructor called"
		<< std::endl;
}

void ClapTrap::log(const std::string str) const
{
	std::cout << str << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (not _hit_points)
		return log("attack: ClapTrap " + _name + " is dead!");

	if (not _energy_points)
		return log("attack: ClapTrap " + _name + " has no energy!");

	std::cout
		<< "ClapTrap " << _name
		<< " attacks " << (not target.empty() ? target : "unnamed")
		<< ", causing " << _attack_damage << " points of damage!"
		<< std::endl;

	_energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points)
	{
		std::cout
			<< "ClapTrap " << _name
			<< " take a damage of " << amount << " hit points!"
			<< std::endl;

		_hit_points = amount >= _hit_points ? 0 : _hit_points - amount;
	}

	if (not _hit_points)
		return log("takeDamage: ClapTrap " + _name + " is dead!");
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (not _hit_points)
		return log("beRepaired: ClapTrap " + _name + " is dead!");

	if (not _energy_points)
		return log("beRepaired: ClapTrap " + _name + " has no energy!");

	std::cout
		<< "ClapTrap " << _name
		<< " repaired " << amount << " hit points!"
		<< std::endl;

	_hit_points += amount;

	_energy_points--;
}

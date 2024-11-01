/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:03:36 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/01 11:01:42 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) :
	_name("unknow"),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0)
{
	std::cout
		<< "Default constructor called"
		<< std::endl;
}

ClapTrap::ClapTrap(std::string name) :
	_name(name),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0)
{
	std::cout
		<< "Default parameterized constructor called"
		<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	std::cout
		<< "Copy constructor called"
		<< std::endl;

	*this = claptrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	std::cout
		<< "Copy assignment operator called"
		<< std::endl;

	if (this != &claptrap)
	{
		_name = claptrap.get_name();
		_hit_points = claptrap.get_hit_points();
		_energy_points = claptrap.get_hit_points();
		_attack_damage = claptrap.get_attack_damage();
	}

	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout
		<< "Destructor called"
		<< std::endl;
}

void ClapTrap::set_name(std::string name)
{
	_name = name;
}

std::string ClapTrap::get_name(void) const
{
	return _name;
}

void ClapTrap::set_hit_points(unsigned int hit_points)
{
	_hit_points = hit_points;
}

unsigned int ClapTrap::get_hit_points(void) const
{
	return _hit_points;
}

bool ClapTrap::has_hit_points(void) const
{
	if (_hit_points)
		return true;

	std::cout
		<< "ClapTrap " << _name
		<< " is dead!"
		<< std::endl;
	
	return false;
}

void ClapTrap::set_energy_points(unsigned int energy_points)
{
	_energy_points = energy_points;
}

unsigned int ClapTrap::get_energy_points(void) const
{
	return _energy_points;
}

bool ClapTrap::has_energy_points(void) const
{
	if (_energy_points)
		return true;

	std::cout
		<< "ClapTrap " << _name
		<< " has no energy points!"
		<< std::endl;

	return false;
}

void ClapTrap::set_attack_damage(unsigned int attack_damage)
{
	_attack_damage = attack_damage;
}

unsigned int ClapTrap::get_attack_damage(void) const
{
	return _attack_damage;
}

bool ClapTrap::has_attack_damage(void) const
{
	if (_attack_damage)
		return true;

	std::cout
		<< "ClapTrap " << _name
		<< " has no attack damage!"
		<< std::endl;

	return false;
}

void ClapTrap::attack(const std::string &target)
{
	if (not has_hit_points())
		return ;

	if (not has_energy_points())
		return ;

	if (not has_attack_damage())
		return ;

	std::cout
		<< "ClapTrap " << _name
		<< " attacks " << (not target.empty() ? target : "unnamed")
		<< ", causing " << _attack_damage << " points of damage!"
		<< std::endl;

	_energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (not has_hit_points())
		return ;

	std::cout
		<< "ClapTrap " << _name
		<< " take a damage of " << amount << " hit points!"
		<< std::endl;

	set_hit_points(amount >= _hit_points ? 0 : _hit_points - amount);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (not has_hit_points())
		return ;

	if (not has_energy_points())
		return ;

	std::cout
		<< "ClapTrap " << _name
		<< " repaired " << amount << " hit points!"
		<< std::endl;

	_hit_points += amount;

	_energy_points--;
}

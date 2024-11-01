/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:03:36 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/01 16:05:37 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

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

bool ClapTrap::has_hit_points(const std::string class_name) const
{
	if (_hit_points)
		return true;

	std::cout
		<< class_name << " " << _name
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

bool ClapTrap::has_energy_points(const std::string class_name) const
{
	if (_energy_points)
		return true;

	std::cout
		<< class_name << " " << _name
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

bool ClapTrap::has_attack_damage(const std::string class_name) const
{
	if (_attack_damage)
		return true;

	std::cout
		<< class_name << " " << _name
		<< " has no attack damage!"
		<< std::endl;

	return false;
}

void ClapTrap::attack(const std::string &target)
{
	if (not has_hit_points("ClapTrap"))
		return ;

	if (not has_energy_points("ClapTrap"))
		return ;

	if (not has_attack_damage("ClapTrap"))
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
	if (not has_hit_points("ClapTrap"))
		return ;

	std::cout
		<< "ClapTrap " << _name
		<< " take a damage of " << amount << " hit points!"
		<< std::endl;

	set_hit_points(amount >= _hit_points ? 0 : _hit_points - amount);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (not has_hit_points("ClapTrap"))
		return ;

	if (not has_energy_points("ClapTrap"))
		return ;

	std::cout
		<< "ClapTrap " << _name
		<< " repaired " << amount << " hit points!"
		<< std::endl;

	_hit_points += amount;

	_energy_points--;
}

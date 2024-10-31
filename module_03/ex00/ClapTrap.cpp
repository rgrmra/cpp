/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:03:36 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/31 11:37:46 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>

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
		<< "Parameterized constructor called"
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
	std::cout
		<< "ClapTrap " << _name
		<< " has a new name: " << name
		<< std::endl;

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
	if (not _hit_points)
		std::cout
			<< "ClapTrap " << get_name()
			<< " is dead!"
			<< std::endl;

	return _hit_points;
}

void ClapTrap::set_energy_points(unsigned int energy_points)
{
	_energy_points = energy_points;
}

unsigned int ClapTrap::get_energy_points(void) const
{
	if (not _energy_points)
		std::cout
			<< "ClapTrap " << get_name()
			<< " has no energy!"
			<< std::endl;

	return _energy_points;
}

void ClapTrap::set_attack_damage(unsigned int attack_damage)
{
	_attack_damage = attack_damage;
}

unsigned int ClapTrap::get_attack_damage(void) const
{
	if (not _attack_damage)
		std::cout
			<< "ClapTrap " << get_name()
			<< " has no attack damage!"
			<< std::endl;

	return _attack_damage;
}

void ClapTrap::attack(const std::string &target)
{
	if (not get_energy_points())
		return ;

	if (not get_attack_damage())
		return ;

	std::cout
		<< "ClapTrap " << get_name()
		<< " attacks " << (not target.empty() ? target : "unnamed")
		<< ", causing " << _attack_damage << " points of damage!"
		<< std::endl;

	_energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (not get_hit_points())
		return ;

	if (not get_energy_points())
		return ;

	if (amount >= get_hit_points())
	{
		set_hit_points(0);
		static_cast<void>(get_hit_points());
		return ;
	}

	std::cout
		<< "ClapTrap " << get_name()
		<< " take a damage of " << amount << " hit points!"
		<< std::endl;

	_hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (not get_hit_points())
		return ;

	if (not get_energy_points())
		return ;

	std::cout
		<< "ClapTrap " << get_name()
		<< " repaired " << amount << " hit points!"
		<< std::endl;

	_hit_points += amount;

	_energy_points--;
}

void	ClapTrap::status(void)
{
	std::cout
		<< "ClapTrap name: " << _name
		<< ", hit: " << _hit_points
		<< ", energy: " << _energy_points
		<< ", attack: " << _attack_damage << std::endl;
}

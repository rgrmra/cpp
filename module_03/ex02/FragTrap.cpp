/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:22:20 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/01 13:06:01 by rde-mour         ###   ########.org.br   */
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

	set_hit_points(100);
	set_energy_points(100);
	set_attack_damage(30);
}

FragTrap::FragTrap(const std::string name) :
	ClapTrap(name)
{
	std::cout
		<< "FragTrap default parameterized constructor called"
		<< std:: endl;

	set_hit_points(100);
	set_energy_points(100);
	set_attack_damage(30);
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
		set_name(fragtrap.get_name());
		set_hit_points(fragtrap.get_hit_points());
		set_energy_points(fragtrap.get_energy_points());
		set_attack_damage(fragtrap.get_attack_damage());
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
	if (not has_hit_points("FragTrap"))
		return ;

	if (not has_energy_points("FragTrap"))
		return ;

	if (not has_attack_damage("FragTrap"))
		return ;

	std::cout
		<< "FragTrap " << _name
		<< " attacks " << (not target.empty() ? target : "unnamed")
		<< ", causing " << _attack_damage << " points of damage!"
		<< std::endl;

	_energy_points--;
}

void FragTrap::highFivesGuys(void)
{
	if (not has_hit_points("FragTrap"))
		return ;

	if (not has_energy_points("FragTrap"))
		return ;

	std::cout
		<< "FragTrap raises his hand for a high-five!"
		<< std::endl;
}

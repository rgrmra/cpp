/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 22:08:20 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/14 20:57:23 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string name) :
	_name(name),
	_weapon(NULL)
{

}

HumanB::~HumanB(void)
{

}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack(void)
{
	std::cout
		<< _name
		<< " attacks with their "
		<< (_weapon ? _weapon->getType() : "hands")
		<< std::endl;
}

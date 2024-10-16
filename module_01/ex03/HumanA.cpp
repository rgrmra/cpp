/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:31:29 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/14 20:57:11 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name, Weapon &weapon) :
	_name(name),
	_weapon(weapon)
{

}

HumanA::~HumanA(void)
{

}

void HumanA::attack(void)
{
	std::cout
		<< _name
		<< " attacks with their "
		<< _weapon.getType()
		<< std::endl;
}

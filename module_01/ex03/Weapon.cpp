/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:01:14 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/14 20:57:44 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon(const std::string type) :
	_type(type)
{
	
}

Weapon::~Weapon(void)
{
	
}

void Weapon::setType(const std::string type)
{
	_type = type;
}

const std::string &Weapon::getType(void)
{
	return _type;
}

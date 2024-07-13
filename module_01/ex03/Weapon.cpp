/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:01:14 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/12 22:47:11 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon(const std::string type) : _type(type)
{
	
}

Weapon::~Weapon()
{
	
}

void	Weapon::setType(const std::string type)
{
	_type = type;
}

const std::string	&Weapon::getType()
{
	return _type;
}

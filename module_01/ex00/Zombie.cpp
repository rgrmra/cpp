/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:22:53 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/16 16:18:14 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(void) :
	_name("unknown")
{

}

Zombie::~Zombie(void)
{
	std::cout
		<< _name
		<< " was eliminated!"
		<< std::endl;
}

void Zombie::announce(void)
{
	std::cout
		<< _name
		<< ": BraiiiiiiinnnzzzZ..."
		<< std::endl;
}

void Zombie::set_name(std::string name)
{
	_name = name;
}

Zombie *newZombie(std::string name)
{
	Zombie* zombie = new Zombie();

	zombie->set_name(name);

	return zombie;
}

void randomChump(std::string name)
{
	Zombie zombie;

	zombie.set_name(name);

	zombie.announce();
}

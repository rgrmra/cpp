/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:22:53 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/11 20:58:46 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie(void)
{
	std::cout
		<< _name
		<< " was destroyed!"
		<< std::endl;
}

void	Zombie::announce(void)
{
	std::cout
		<< _name
		<< ": BraiiiiiiinnnzzzZ..."
		<< std::endl;
}

Zombie	*newZombie(std::string name)
{
	return new Zombie(name);
}

void	randomChump(std::string name)
{
	Zombie zombie(name);

	zombie.announce();
}

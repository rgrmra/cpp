/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:22:53 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/14 20:27:21 by rde-mour         ###   ########.org.br   */
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

void Zombie::set_name(std::string name)
{
	_name = name;
}

void Zombie::announce(void)
{
	std::cout
		<< _name
		<< ": BraiiiiiiinnnzzzZ..."
		<< std::endl;
}

Zombie *zombieHorde(int N, std::string name)
{
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].set_name(name);

	return horde;
}

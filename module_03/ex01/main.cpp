/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:39:28 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/01 11:02:07 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
	ScavTrap scavtrap("Marvin");

	std::cout << "Messages tests" << std::endl;
	scavtrap.attack("You");
	scavtrap.attack("");

	std::cout << std::endl;
	std::cout << "Health Points tests" << std::endl;

	scavtrap.takeDamage(1);
	scavtrap.beRepaired(2);
	scavtrap.takeDamage(101);
	scavtrap.takeDamage(1);

	std::cout << std::endl;
	std::cout << "Energy tests" << std::endl;

	scavtrap.set_energy_points(0);
	scavtrap.set_hit_points(10);

	scavtrap.attack("You again");
	scavtrap.beRepaired(1);
	scavtrap.attack("A ghost");
	scavtrap.guardGate();

	return EXIT_SUCCESS;
}

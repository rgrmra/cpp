/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:39:28 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/01 13:08:49 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
	ScavTrap scavtrap("Marvin");

	std::cout << "ScavTrap Messages tests" << std::endl;
	scavtrap.attack("You");
	scavtrap.attack("");

	std::cout << std::endl;
	std::cout << "ScavTrap Health Points tests" << std::endl;

	scavtrap.takeDamage(1);
	scavtrap.beRepaired(2);
	scavtrap.takeDamage(101);
	scavtrap.takeDamage(1);

	std::cout << std::endl;
	std::cout << "ScavTrap Energy tests" << std::endl;

	scavtrap.set_energy_points(0);
	scavtrap.set_hit_points(10);

	scavtrap.attack("You again");
	scavtrap.beRepaired(1);
	scavtrap.attack("A ghost");
	scavtrap.guardGate();

	std::cout << std::endl;
	FragTrap fragtrap("Marvin");

	std::cout << "FragTrap Messages tests" << std::endl;
	fragtrap.attack("You");
	fragtrap.attack("");

	std::cout << std::endl;
	std::cout << "FragTrap Health Points tests" << std::endl;

	fragtrap.takeDamage(1);
	fragtrap.beRepaired(2);
	fragtrap.takeDamage(101);
	fragtrap.takeDamage(1);

	std::cout << std::endl;
	std::cout << "FragTrap Energy tests" << std::endl;

	fragtrap.set_energy_points(0);
	fragtrap.set_hit_points(10);

	fragtrap.attack("You again");
	fragtrap.beRepaired(1);
	fragtrap.attack("A ghost");
	fragtrap.highFivesGuys();

	std::cout << std::endl;
	std::cout << "FragTrap High Five" << std::endl;

	fragtrap.set_energy_points(1);
	fragtrap.highFivesGuys();

	return EXIT_SUCCESS;
}

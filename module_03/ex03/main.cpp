/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:39:28 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/01 16:23:45 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
	DiamondTrap diamond("Marvin");
	diamond.whoAmI();
	std::cout << "Hit points: " << diamond.get_hit_points() << std::endl;
	std::cout << "Energy points: " << diamond.get_energy_points() << std::endl;
	std::cout << "Attack damage: " << diamond.get_attack_damage() << std::endl;

	std::cout << std::endl;
	std::cout << "ScavTrap Messages tests" << std::endl;
	diamond.attack("You");
	diamond.attack("");

	std::cout << std::endl;
	std::cout << "ScavTrap Health Points tests" << std::endl;

	diamond.takeDamage(1);
	diamond.beRepaired(2);
	diamond.takeDamage(101);
	diamond.takeDamage(1);

	std::cout << std::endl;
	std::cout << "ScavTrap Energy tests" << std::endl;

	diamond.set_energy_points(0);
	diamond.set_hit_points(10);

	diamond.attack("You again");
	diamond.beRepaired(1);
	diamond.attack("A ghost");
	diamond.guardGate();

	std::cout << std::endl;
	std::cout << "FragTrap High Five" << std::endl;

	diamond.set_energy_points(1);
	diamond.highFivesGuys();

	return EXIT_SUCCESS;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:39:28 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/31 16:07:25 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
	ClapTrap claptrap("Marvin");
	
	std::cout << "Messages tests" << std::endl;
	claptrap.attack("You");
	claptrap.set_attack_damage(2);
	claptrap.attack("");
	claptrap.takeDamage(1);
	claptrap.beRepaired(1);
	
	std::cout << std::endl;
	std::cout << "Health Points tests" << std::endl;
	
	claptrap.takeDamage(1);
	claptrap.beRepaired(2);
	claptrap.takeDamage(10);
	claptrap.takeDamage(1);
	
	std::cout << std::endl;
	std::cout << "Energy tests" << std::endl;
	
	claptrap.set_energy_points(0);
	claptrap.set_hit_points(10);
	
	claptrap.attack("You again");
	claptrap.beRepaired(1);
	claptrap.attack("A ghost");
	
	return EXIT_SUCCESS;
}

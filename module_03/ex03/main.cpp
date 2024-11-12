/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:39:28 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/11 20:01:43 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <cstdlib>

int main(void)
{
	DiamondTrap *cadet = new DiamondTrap("Cadet");

	cadet->whoAmI();
	cadet->attack("Moulinette");
	cadet->takeDamage(90);
	cadet->beRepaired(1);
	cadet->beRepaired(1);
	cadet->beRepaired(1);
	cadet->beRepaired(1);
	cadet->beRepaired(1);
	cadet->beRepaired(1);
	cadet->beRepaired(1);
	cadet->beRepaired(1);
	cadet->beRepaired(1);
	cadet->beRepaired(1);
	cadet->guardGate();
	cadet->highFivesGuys();
	cadet->attack("Moulinette");
	cadet->takeDamage(100);
	cadet->attack("Moulinette");
	cadet->beRepaired(100);
	cadet->highFivesGuys();
	cadet->guardGate();

	delete cadet;
	
	return EXIT_SUCCESS;
}

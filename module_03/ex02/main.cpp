/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:39:28 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/07 20:48:26 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <cstdlib>

int main(void)
{
	FragTrap *cadet = new FragTrap("Cadet");

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
	cadet->highFivesGuys();
	cadet->attack("Moulinette");
	cadet->takeDamage(100);
	cadet->attack("Moulinette");
	cadet->beRepaired(100);
	cadet->highFivesGuys();

	delete cadet;
	
	return EXIT_SUCCESS;
}

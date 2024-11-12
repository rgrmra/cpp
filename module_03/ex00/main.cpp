/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:39:28 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/07 19:11:52 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
	ClapTrap *cadet = new ClapTrap("Cadet");

	cadet->attack("Moulinette");
	cadet->takeDamage(9);
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
	cadet->attack("Moulinette");
	cadet->takeDamage(10);
	cadet->attack("Moulinette");
	cadet->beRepaired(10);

	delete cadet;
	
	return EXIT_SUCCESS;
}

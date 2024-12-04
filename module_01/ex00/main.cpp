/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:35:29 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/28 21:18:28 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <iostream>

int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Usage: brainiz <name>" << std::endl;
		return EXIT_FAILURE;
	}

	std::string name = argv[1];

	Zombie *zombie = newZombie(name);
	zombie->announce();

	delete zombie;

	randomChump(name);

	return EXIT_SUCCESS;
}

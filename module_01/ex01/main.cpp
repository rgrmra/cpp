/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:35:29 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/16 16:27:39 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Usage: brainz <quantity> <name>" << std::endl;
		return EXIT_FAILURE;
	}

	const int N = atoi(argv[1]);

	Zombie* horde = zombieHorde(N, static_cast<std::string>(argv[2]));

	for (int i = 0; i < N; i++)
		horde[i].announce();
	
	delete[] horde;

	return EXIT_SUCCESS;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:35:29 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/17 15:19:48 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 3)
			throw ENOTSUP;

		const int N = atoi(argv[1]);

		if (N < 0 || N > 200 || static_cast<std::string>(argv[1]).length() > 3)
			throw ENOTSUP;
	
		Zombie* horde = zombieHorde(N, static_cast<std::string>(argv[2]));
	
		for (int i = 0; i < N; i++)
			horde[i].announce();
		
		delete[] horde;
	
		return EXIT_SUCCESS;
	}
	catch (int exception) 
	{
		std::cout << "Usage: brainz <quantity[0-200]> <name>" << std::endl;
		return exception;
	}
}

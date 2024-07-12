/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:35:29 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/11 21:37:23 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int	main(void)
{
	static const int	N = 10;
	Zombie	*horde = zombieHorde(N, "Foo");

	for (int i = 0; i < N; i++)
		horde[i].announce();
	
	delete[] horde;

	return (EXIT_SUCCESS);
}

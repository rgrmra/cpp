/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:35:29 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/11 20:52:29 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int	main(void)
{
	Zombie *zombie = newZombie("Foo");

	zombie->announce();
	randomChump("Bar");

	delete zombie;

	return (EXIT_SUCCESS);
}

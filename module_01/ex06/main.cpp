/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:51:37 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/17 14:30:29 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>
#include <string>


int	main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
		return EXIT_FAILURE;

	harl.complain(static_cast<std::string>(argv[1]));

	return EXIT_SUCCESS;
}

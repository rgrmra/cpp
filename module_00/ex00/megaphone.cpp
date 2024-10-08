/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*    Created: 2024/07/01 17:31:36 by rde-mour          #+#    #+#            */
/*   Updated: 2024/10/07 19:04:51 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	for (int i = 1; i < argc; i++)
	{
		std::string	str = argv[i];

		for (size_t j = 0; j < str.length(); j++)
			str.at(j) = static_cast<unsigned char>(toupper(str.at(j)));

		std::cout << str;
	}

	std::cout << std::endl;

	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*    Created: 2024/07/01 17:31:36 by rde-mour          #+#    #+#            */
/*   Updated: 2024/07/01 22:08:31 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>

static std::string	megaphone(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), toupper);
	return str;
}

int	main(int argc, char **argv)
{
	if (std::isless(argc, 2))
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; std::isless(i, argc); ++i)
		std::cout << megaphone(argv[i]);
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}

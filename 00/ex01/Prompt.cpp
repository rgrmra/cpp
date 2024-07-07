/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prompt.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:07:33 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/07 18:04:55 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Prompt.hpp"
#include <cstdio>
#include <iostream>
#include <string>

Prompt::Prompt()
{

}

Prompt::~Prompt()
{

}

bool	invalid(std::string str)
{
	if (str.empty())
	{
		std::clearerr(stdin);
		std::cin.clear();
		return true;
	}
	try {
		if (static_cast<long>(str.find_first_not_of(' ')))
			return false;
	} catch (...) {
		return true;
	}
	return false;
}

std::string	Prompt::getline(std::string str)
{
	std::string input;

	do
	{
		std::cout << str;
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::cout << std::endl;
	}
	while (invalid(input));
	return input;
}

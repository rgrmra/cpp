/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prompt.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:07:33 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/07 21:55:56 by rde-mour         ###   ########.org.br   */
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
		return (true);
	}

	return (str.at(0) == ' ' || static_cast<size_t>(str.find("  ")) > -1);
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

	return (input);
}

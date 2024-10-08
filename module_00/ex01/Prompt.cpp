/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prompt.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:07:33 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/08 17:26:00 by rde-mour         ###   ########.org.br   */
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

bool Prompt::_is_valid_input(std::string str)
{
	if (str.empty())
	{
		std::clearerr(stdin);
		std::cin.clear();
		return false;
	}

	return (str.at(0) != ' ' && static_cast<ssize_t>(str.find("  ")) == -1);
}

std::string Prompt::get_line(std::string str)
{
	std::string input;

	do
	{
		std::cout << str;

		std::getline(std::cin, input);
		if (std::cin.eof())
			std::cout << std::endl;
	}
	while (not _is_valid_input(input));

	return input;
}

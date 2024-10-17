/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:15:03 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/17 14:27:10 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl()
{
	methods[0] = &Harl::debug;
	methods[1] = &Harl::info;
	methods[2] = &Harl::warning;
	methods[3] = &Harl::error;
	methods[4] = &Harl::invalid;
}

Harl::~Harl()
{

}

void Harl::debug(void)
{
	std::cout
		<< PURPLE "[ DEBUG ] " RESET
		<< std::endl
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< std::endl
		<< "I really do!"
		<< std::endl
		<< std::endl;
}

void Harl::info(void)
{
	std::cout
		<< BLUE "[ INFO ] " RESET
		<< std::endl
		<< "I cannot believe adding extra bacon costs more money."
		<< std::endl
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl
		<< std::endl;
}

void Harl::warning(void)
{
	std::cout
		<< YELLOW "[ WARNING ] " RESET
		<< std::endl
		<< "I think I deserve to have some extra bacon for free."
		<< std::endl
		<< "I’ve been coming for years whereas you started working here since last month."
		<< std::endl
		<< std::endl;
}

void Harl::error(void)
{
	std::cout
		<< RED "[ ERROR ] " RESET
		<< std::endl
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl
		<< std::endl;
}

void Harl::invalid(void)
{
	std::cout
		<< GREEN "[ Probably complaining about insignificant problems ]" RESET
		<< std::endl
		<< std::endl;
}

void Harl::complain(std::string level)
{
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	int i;
	for (i = 0; i < 4; i++)
	{
		if (level.compare(levels[i]) != 0)
			continue;
		break;
	}

	(this->*methods[i])();
}

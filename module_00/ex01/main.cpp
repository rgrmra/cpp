/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:23:17 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/12 15:07:58 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Prompt.hpp"
#include <iostream>
#include <ostream>
#include <string>

int	main(void)
{
	PhoneBook	phoneBook;
	Prompt		prompt;
	std::string	input;
	
	do
	{
		std::cout << COLOR "PhoneBook valid commands" RESET << std::endl
			<< COLOR "ADD: " RESET "add new contact" << std::endl
			<< COLOR "SEARCH :" RESET "search a contact" << std::endl
			<< COLOR "EXIT: " RESET "quits PhoneBook" << std::endl << std::endl;
		input = prompt.getline(COLOR"Command: \033[0;m");
		if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.searchContact();
		else if (input != "EXIT")
			std::cout << std::endl << RED "Invalid command!" RESET << std::endl
				<< std::endl;
	} while (input != "EXIT");
}
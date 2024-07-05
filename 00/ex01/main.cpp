/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:23:17 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/05 19:32:15 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Prompt.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook	phone_book;
	Prompt		prompt;
	std::string	input;
	
	do
	{
		input = prompt.getline("Choose: ");
		if (input == "ADD")
			phone_book.add_contact();
		else if (input == "SEARCH")
			phone_book.search_contact();
		else
			std::cout << "Invalid!" << std::endl;
	} while (input != "EXIT");
}

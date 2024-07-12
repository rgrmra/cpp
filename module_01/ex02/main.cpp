/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:57:25 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/11 22:11:46 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>

int	main(void)
{
	std::string	string("HI THIS IS BRAIN");
	std::string *pointer = &string;
	std::string &reference = string;

	std::cout
		<< "Memory address of the string variable "
		<< &string
		<< std::endl;
	std::cout
		<< "Memory address held by string pointer "
		<< pointer
		<< std::endl;
	std::cout
		<< "Memory address held by string reference "
		<< &reference
		<< std::endl;

	std::cout
		<< "Value of the string variable "
		<< string
		<< std::endl;
	std::cout
		<< "Value pointed to string pointer "
		<< *pointer
		<< std::endl;
	std::cout
		<< "Value pointed to string reference "
		<< reference
		<< std::endl;

	return (EXIT_SUCCESS);
}

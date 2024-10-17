/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:57:25 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/17 19:05:49 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>

int	main(void)
{
	const std::string stringVAR("HI THIS IS BRAIN");
	const std::string* stringPTR = &stringVAR;
	const std::string& stringREF = stringVAR;

	std::cout
		<< "The memory address of the string variable "
		<< &stringVAR
		<< std::endl;

	std::cout
		<< "The memory address held by stringPTR "
		<< stringPTR
		<< std::endl;

	std::cout
		<< "The memory address held by stringREF "
		<< &stringREF
		<< std::endl;

	std::cout
		<< "The value of the string variable "
		<< stringVAR
		<< std::endl;

	std::cout
		<< "The value pointed to by stringPTR "
		<< *stringPTR
		<< std::endl;

	std::cout
		<< "The value pointed to by stringREF "
		<< stringREF
		<< std::endl;

	return EXIT_SUCCESS;
}

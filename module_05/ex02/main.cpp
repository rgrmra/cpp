/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:05:47 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/23 15:43:33 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <ostream>

int main(void)
{
	std::cout << "DECLARATIONS:" << std::endl;
	Bureaucrat *president = new Bureaucrat("President", 1);
	std::cout << *president << std::endl;

	Bureaucrat *intern = new Bureaucrat("Intern", 150);
	std::cout << *intern << std::endl;

	std::cout << "\nSHRUBBERY TEST:" << std::endl;
	AForm *form = new ShrubberyCreationForm("file");
	std::cout << *form << std::endl;

	try {
		intern->signForm(*form);
		intern->executeForm(*form);
		president->signForm(*form);
		president->executeForm(*form);

		std::cout << *form << std::endl;

	} catch (std::exception &exception) {
		std::cerr << exception.what() << std::endl;
	}

	delete form;

	std::cout << "\nROBOTOMY 1ST TEST:" << std::endl;
	form = new RobotomyRequestForm("Somebody");
	std::cout << *form << std::endl;

	try {
		intern->signForm(*form);
		intern->executeForm(*form);
		president->signForm(*form);
		president->executeForm(*form);

		std::cout << *form << std::endl;

	} catch (std::exception &exception) {
		std::cerr << exception.what() << std::endl;
	}

	delete form;

	std::cout << "\nROBOTOMY 2ND TEST:" << std::endl;
	form = new RobotomyRequestForm("Somebody");
	std::cout << *form << std::endl;

	try {
		intern->signForm(*form);
		intern->executeForm(*form);
		president->signForm(*form);
		president->executeForm(*form);

		std::cout << *form << std::endl;

	} catch (std::exception &exception) {
		std::cerr << exception.what() << std::endl;
	}

	delete form;

	std::cout << "\nPRESIDENTIAL TEST:" << std::endl;
	form = new PresidentialPardonForm("Someone");
	std::cout << *form << std::endl;

	try {
		intern->signForm(*form);
		intern->executeForm(*form);
		president->signForm(*form);
		president->executeForm(*form);

		std::cout << *form << std::endl;

	} catch (std::exception &exception) {
		std::cerr << exception.what() << std::endl;
	}

	delete form;

	delete president;
	delete intern;

	return  EXIT_SUCCESS;
}

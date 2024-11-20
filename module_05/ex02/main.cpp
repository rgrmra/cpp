/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:05:47 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/20 20:38:06 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <ostream>

int main(void)
{
	try {
		Bureaucrat bureaucrat = Bureaucrat("president", 1);
		std::cout << bureaucrat << std::endl;

		ShrubberyCreationForm form = ShrubberyCreationForm("file");
		std::cout << form << std::endl;

		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	} catch (std::exception &exception) {
		std::cerr << exception.what() << std::endl;
	}


	//std::cout << "1ST TEST" << std::endl;
	//try {
	//	Form form = Form("Application Form", 0, 0);	
	//} catch (std::exception &exception) {
	//	std::cerr << exception.what()<< std::endl;
	//}

	//std::cout << "\n2ND TEST" << std::endl;
	//try {
	//	Form form = Form("Application Form", 151, 151);	
	//} catch (std::exception &exception) {
	//	std::cerr << exception.what()<< std::endl;
	//}

	//std::cout << "\n3RD TEST" << std::endl;
	//try {
	//	Form form = Form("Application Form", 24, 24);	
	//	std::cout << form << std::endl;

	//	Bureaucrat manager = Bureaucrat("Manager", 25);
	//	std::cout << manager << std::endl;

	//	manager.signForm(form);
	// } catch (std::exception &exception) {
	//	 std::cerr << exception.what() << std::endl;
	// }

	//std::cout << "\n4TH TEST" << std::endl;
	//try {
	//	Form form = Form("Application Form", 10, 1);
	//	std::cout << form << std::endl;

	//	Bureaucrat boss = Bureaucrat("Boss", 1);
	//	std::cout << boss << std::endl;

	//	boss.signForm(form);

	//	std::cout << form << std::endl;
	//} catch (std::exception &exception) {
	//	std::cerr << exception.what() << std::endl;
	//}

	return  EXIT_SUCCESS;
}

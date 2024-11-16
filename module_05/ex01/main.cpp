/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:05:47 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/16 11:17:52 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
	std::cout << "1ST TEST" << std::endl;
	try {
		Bureaucrat marvin("Marvin", 2);

		std::cout << "Name: " << marvin.getName() << std::endl;
		std::cout << "Grade: " << marvin.getGrade() << std::endl;
		std::cout << marvin << std::endl;

		marvin.incrementGrade();
		std::cout << "Grade: " << marvin.getGrade() << std::endl;
		marvin.incrementGrade();
	 } catch (std::exception &exception) {
		 std::cerr << exception.what() << std::endl;
	 }

	std::cout << "\n2ND TEST" << std::endl;
	try {
		Bureaucrat cadet("Cadet", 149);
		std::cout << "Name: " << cadet.getName() << std::endl;
		std::cout << "Grade: " << cadet.getGrade() << std::endl;
		std::cout << cadet << std::endl;

		cadet.decrementGrade();
		std::cout << "Grade: " << cadet.getGrade() << std::endl;
		cadet.decrementGrade();
	} catch (std::exception &exception) {
		std::cerr << exception.what() << std::endl;
	}

	std::cout << "\n3RD TEST" << std::endl;
	try {
		Bureaucrat high("High", 0);
	} catch (std::exception &exception) {
		std::cerr << exception.what() << std::endl;
	}

	std::cout << "\n4TH TEST" << std::endl;
	try {
		Bureaucrat low("Low", 151);
	} catch (std::exception &exception) {
		std::cerr << exception.what() << std::endl;
	}

	std::cout << "\n5TH TEST" << std::endl;
	try {
		Bureaucrat test("Bureaucrat", 10);
		while (test.getGrade() > 0)
		{
			std::cout << test << std::endl;
			test.incrementGrade();
		}
	}
	catch (std::exception &exception) {
		std::cerr << exception.what() << std::endl;
	}

	return  EXIT_SUCCESS;
}

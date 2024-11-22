/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:05:47 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/22 17:44:23 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

int main(void)
{
	Intern someRandomIntern;
	AForm *rrf;

	try {
		std::cout << "1ST TEST:" << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;

		std::cout << "\n2ND TEST:" << std::endl;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
		std::cout << *rrf << std::endl;
		delete rrf;

		std::cout << "\n3RD TEST:" << std::endl;
		rrf = someRandomIntern.makeForm("presidential pardon", "Corrupt");
		std::cout << *rrf << std::endl;
		delete rrf;

		std::cout << "\n4TH TEST:" << std::endl;
		rrf = someRandomIntern.makeForm("wrong form", "Wrong");
		std::cout << *rrf << std::endl;
		delete rrf;

	} catch (std::exception &exception) {
		std::cerr << exception.what() << std::endl;
	}

	return  EXIT_SUCCESS;
}

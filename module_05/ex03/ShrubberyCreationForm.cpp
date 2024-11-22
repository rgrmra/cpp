/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:09:54 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/22 18:44:44 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <string>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Shrubbery Creation Form", GRADE_TO_SIGN, GRADE_TO_EXECUTE),
	  _target("unnamed") {

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("Shrubbery Creation Form", GRADE_TO_SIGN, GRADE_TO_EXECUTE),
	  _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm("Shrubbery Creation Form", GRADE_TO_SIGN, GRADE_TO_EXECUTE),
	  _target(src._target) {

	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this == &rhs)
		return *this;

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

}

const char *ShrubberyCreationForm::FileFailedToOpenException::what(void) const throw() {
	return "File failed to open";
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {

	AForm::execute(executor);
	
	static const std::string filename = _target + "_shrubbery";

	std::ofstream fileOut(filename.c_str());

	if (not fileOut)
		throw ShrubberyCreationForm::FileFailedToOpenException();

	fileOut << "               ,@@@@@@@,\n"
		<< "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
		<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
		<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
		<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
		<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
		<< "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
		<< "       |o|        | |         | |\n"
		<< "       |.|        | |         | |\n"
		<< "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_"
		<< std::endl;

	fileOut.close();
}

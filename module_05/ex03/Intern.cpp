/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:12:24 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/22 17:35:40 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern(void) {

}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern &Intern::operator=(const Intern &rhs) {
	if (this == &rhs)
		return *this;

	return *this;
}

Intern::~Intern(void) {

}

static AForm *shrubberyRequestForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

static AForm *robotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

static AForm *presidentialRequestForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string name, const std::string target) {

	static const std::string forms[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	static AForm *(*method[]) (const std::string &target) = {
		&shrubberyRequestForm,
		&robotomyRequestForm,
		&presidentialRequestForm
	};

	for (size_t i = 0; i < forms->length(); i++) {
		if (name.compare(forms[i]) != 0)
			continue ;

		AForm *form = method[i](target);
		std::cout << "Intern creates " << form->getName() << std::endl;

		return form;
	}

	throw InvalidFormException();
}

const char *Intern::InvalidFormException::what() const throw() {
	return "Invalid Form";
}

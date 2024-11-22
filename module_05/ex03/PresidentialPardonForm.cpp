/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:21:01 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/20 20:41:27 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Presidential Pardon Form", GRADE_TO_SING, GRADE_TO_EXECUTE),
	  _target("unammed") {

}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("Presidential Pardon Form", GRADE_TO_SING, GRADE_TO_EXECUTE),
	  _target(target) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm("Presidential Pardon Form", GRADE_TO_SING, GRADE_TO_EXECUTE),
	  _target(src._target) {

	*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {

	if (this == &rhs)
		return *this;

	_target = rhs._target;

	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {

}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {

	AForm::execute(executor);

	std::cout << _target + " has been pardoned by Zaphod Beeblebrox." <<  std::endl;
}

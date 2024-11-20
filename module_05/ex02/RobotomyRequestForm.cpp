/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:10:06 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/20 20:36:42 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy Request Form", GRADE_TO_SIGN, GRADE_TO_EXECUTE),
	  _target("unnamed") {

}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("Robotomy Request Form", GRADE_TO_SIGN, GRADE_TO_EXECUTE),
	  _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm("Robotomy Request Form", GRADE_TO_SIGN, GRADE_TO_EXECUTE),
	  _target(src.getName()) {

	*this = src;
}


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	
	if (this == &rhs)
		return *this;

	_target = rhs._target;

	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {

}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {

	AForm::execute(executor);

	static unsigned int times = 0;

	std::cout << "Starting robotomization..." << std::endl;
	if (times % 2 == 0)
		std::cout << _target << " was successfully robotomized" << std::endl;
	else
	 	std::cout << _target << " was not robotomized" << std::endl;
}

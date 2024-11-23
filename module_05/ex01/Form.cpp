/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:34:55 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/23 15:28:51 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <ostream>

Form::Form(void)
	: _name(""),
	  _gradeToSign(0),
	  _gradeToExecute(0),
	  _signed(false) {

	throw GradeTooHighException();
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name),
	  _gradeToSign(gradeToSign),
	  _gradeToExecute(gradeToExecute),
	  _signed(false) {

	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw GradeTooHighException();

	if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form &form)
	: _name(form._name),
	  _gradeToSign(form._gradeToSign),
	  _gradeToExecute(form._gradeToExecute),
	  _signed(form._signed) {

	*this = form;
}

Form &Form::operator=(const Form &form) {
	if (this == &form)
		return *this;

	_signed = form._signed;

	return *this;
}

Form::~Form(void) {}

std::string Form::getName(void) const {
	return _name;
}

int Form::getGradeToSign(void) const {
	return _gradeToSign;
}

int Form::getGradeToExecute(void) const {
	return _gradeToExecute;
}

bool Form::isSigned(void) const {
	return _signed;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();

	_signed = true;
}

const char *Form::GradeTooHighException::what(void) const throw() {
	return "Form: Grade is too high";
}

const char *Form::GradeTooLowException::what(void) const throw() {
	return "Form: Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	return os << "Form:\t" << form.getName()
		<< "\n\tGrade To Sign: " << form.getGradeToSign()
		<< "\n\tGrade To Execute: " << form.getGradeToExecute()
		<< "\n\tStatus: " << (form.isSigned() ? "Signed" : "Unsigned");
}

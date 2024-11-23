/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:34:55 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/23 16:29:15 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void)
	: _name(""),
	  _gradeToSign(0),
	  _gradeToExecute(0),
	  _signed(false) {

	throw GradeTooHighException();
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name),
	  _gradeToSign(gradeToSign),
	  _gradeToExecute(gradeToExecute),
	  _signed(false) {

	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw GradeTooHighException();

	if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &form)
	: _name(form._name),
	  _gradeToSign(form._gradeToSign),
	  _gradeToExecute(form._gradeToExecute),
	  _signed(form._signed) {

	*this = form;
}

AForm &AForm::operator=(const AForm &form) {
	if (this == &form)
		return *this;

	_signed = form._signed;

	return *this;
}

AForm::~AForm(void) {}

std::string AForm::getName(void) const {
	return _name;
}

int AForm::getGradeToSign(void) const {
	return _gradeToSign;
}

int AForm::getGradeToExecute(void) const {
	return _gradeToExecute;
}

bool AForm::isSigned(void) const {
	return _signed;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();

	_signed = true;
}

void AForm::execute(const Bureaucrat &bureaucrat) const {

	if (not this->isSigned())
		throw FormNotSignedException();

	if (bureaucrat.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();

	this->executeTask();
}

const char *AForm::GradeTooHighException::what(void) const throw() {
	return "AForm: Grade is too high";
}

const char *AForm::GradeTooLowException::what(void) const throw() {
	return "AForm: Grade is too low";
}

const char *AForm::FormNotSignedException::what(void) const throw() {
	return "AForm: Form not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	return os << "AForm:\t" << form.getName()
		<< "\n\tGrade To Sign: " << form.getGradeToSign()
		<< "\n\tGrade To Execute: " << form.getGradeToExecute()
		<< "\n\tStatus: " << (form.isSigned() ? "Signed" : "Unsigned");
}

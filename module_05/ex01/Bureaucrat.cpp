/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:13:26 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/16 11:04:54 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

Bureaucrat::Bureaucrat(void)
	: _name("unknow"),
	  _grade(0) {

	throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: _name(name),
	  _grade(grade) {

	if (_grade > _minGrade)
		throw GradeTooLowException();

	if (_grade < _maxGrade)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
	: _name(bureaucrat._name),
	  _grade(bureaucrat._grade) {

	*this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
	
	if (this == &bureaucrat)
		return *this;

	_grade = bureaucrat._grade;

	return *this;
}

Bureaucrat::~Bureaucrat(void) {}

std::string Bureaucrat::getName(void) const {
	return _name;
}

int Bureaucrat::getGrade(void) const {
	return _grade;
}

void Bureaucrat::incrementGrade(void) {
	if (_grade == _maxGrade)
		throw GradeTooHighException();

	_grade--;
}

void Bureaucrat::decrementGrade(void) {
	if (_grade == _minGrade)
		throw GradeTooLowException();
	
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too Low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
}
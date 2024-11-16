/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:53:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/16 11:32:33 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <ostream>
#include <string>

class Form {
	private:
		const std::string _name;
		const int _gradeTosign;
		const int _gradeToExecute;
		bool _signed;

	protected:
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	public:
		Form(void);
		Form(const std::string &string, int gradeToSign, int gradeToExecute);
		Form(const Form &form);
		Form &operator=(const Form &form);
		~Form(void);

		std::string getName(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		bool IsSigned(void) const;

		void beSigned(Bureaucrat &Bureaucrat);
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif /* FORM_HPP */

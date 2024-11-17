/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:53:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/17 13:07:28 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class Form {
	private:
		static const int _maxGrade = 1;
		static const int _minGrade = 150;
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _signed;

	public:
		Form(void);
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form &form);
		Form &operator=(const Form &form);
		~Form(void);

		std::string getName(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		bool isSigned(void) const;

		void beSigned(Bureaucrat &Bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif /* FORM_HPP */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:53:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/24 14:35:53 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;
class Form;

class AForm {
	private:
		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _signed;

	protected:
		virtual void executeTask(void) const = 0;

	public:
		AForm(void);
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &form);
		AForm &operator=(const AForm &form);
		virtual ~AForm(void);

		std::string getName(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		bool isSigned(void) const;

		void beSigned(Bureaucrat &bureaucrat);

		void execute(const Bureaucrat &bureaucrat) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		
		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif /* AFORM_HPP */

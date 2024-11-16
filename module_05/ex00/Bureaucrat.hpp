/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 22:56:12 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/16 11:18:41 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat {
	private:
		static const int _maxGrade = 1;
		static const int _minGrade = 150;
		const std::string _name;
		int _grade;
	
	protected:
		class GradeTooHighException : public std::exception {
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			virtual const char *what() const throw();
		};

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);
		~Bureaucrat(void);

		std::string getName(void) const;
		int getGrade(void) const;

		void incrementGrade(void);
		void decrementGrade(void);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif /* BUREAUCRAT_HPP */

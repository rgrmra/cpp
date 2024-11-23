/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:58:59 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/23 16:29:51 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <exception>
#include <string>

class ShrubberyCreationForm
	: public AForm {

	private:
		static const int GRADE_TO_SIGN = 145;
		static const int GRADE_TO_EXECUTE = 137;
		const std::string _target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
		~ShrubberyCreationForm(void);

		void executeTask(void) const;

		class FileAlreadyExistsException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};

		class FileFailedToOpenException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
};

#endif /* SHRUBBERYCREATIONFORM_HPP */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:05:16 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/21 20:32:45 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include <string>

class AForm;

class Intern {

	public:
		Intern(void);
		Intern(const Intern &src);
		Intern &operator=(const Intern &rhs);
		~Intern(void);

		AForm *makeForm(const std::string name, const std::string target);

		class InvalidFormException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif /* INTERN_HPP */

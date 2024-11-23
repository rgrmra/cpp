/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:59:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/23 16:30:14 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm
	: public AForm {

	private:
		static const int GRADE_TO_SING = 25;
		static const int GRADE_TO_EXECUTE = 5;
		std::string _target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
		~PresidentialPardonForm(void);

		void executeTask(void) const;
};

#endif /* PRESIDENTIALPARDONFORM_HPP */

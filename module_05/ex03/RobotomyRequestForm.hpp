/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:51:24 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/19 18:03:46 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTYREQUESTFORM_HPP
#define ROBOTYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm 
	: public AForm {

	private:
		static const int GRADE_TO_SIGN = 72;
		static const int GRADE_TO_EXECUTE = 45;
		std::string _target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string targer);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
		~RobotomyRequestForm(void);

		void execute(const Bureaucrat &executor) const;
};

#endif /* ROBOTYREQUESTFORM_HPP */

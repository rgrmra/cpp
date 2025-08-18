/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:12:33 by rde-mour          #+#    #+#             */
/*   Updated: 2025/08/18 09:19:41 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {

	private:
		std::stack<double> stack;

		void push(const std::string &value);
		double pop(void);

		void sum(void);
		void sub(void);
		void mult(void);
		void div(void);

		std::string replace(const std::string &buffer, const char &from, const char &to);

	public:
		RPN(void);
		RPN(const RPN &src);
		RPN &operator=(const RPN &rhs);
		~RPN(void);

		double calculate(const std::string &expression);

};

#endif /* RPN_HPP */

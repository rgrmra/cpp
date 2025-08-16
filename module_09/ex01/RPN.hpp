/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:12:33 by rde-mour          #+#    #+#             */
/*   Updated: 2025/08/16 18:02:28 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {

	private:
		std::stack<std::string> stack;

		long sum(const long &number1, const long &number2);
		long sub(const long &number1, const long &number2);
		long mult(const long &number1, const long &number2);
		long div(const long &number1, const long &number2);

		std::string replace(const std::string &buffer, const char &from, const char &to);

	public:
		RPN(void);
		RPN(const RPN &src);
		RPN &operator=(const RPN &rhs);
		~RPN(void);

		std::pair<bool, std::string> calculate(const std::string &expression);

};

#endif /* RPN_HPP */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:23:42 by rde-mour          #+#    #+#             */
/*   Updated: 2025/08/09 11:01:12 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <list>

class Span {
	private:
		std::list<int> *_list;
		unsigned int _limit;

		Span(void);

	public:
		Span(const unsigned int &limit);
		Span(const Span &src);
		Span &operator=(const Span &rhs);
		~Span(void);

		void addNumber(const int &number);

		int shortestSpan(void);
		int longestSpan(void);
};

#endif /* SPAN_HPP */

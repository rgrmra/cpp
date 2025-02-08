/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:33:48 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/18 18:28:20 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>
#include <cstdlib>
#include <stdexcept>

Span::Span(void)
	: _list(new std::list<int>), _limit(0) {

}

Span::Span(unsigned int limit)
	: _list(new std::list<int>), _limit(limit) {

}

Span::Span(const Span &src)
	: _list(new std::list<int>), _limit(src._limit) {

	*this = src;
}

Span &Span::operator=(const Span &rhs) {

	if (this == &rhs)
		return *this;

	delete _list;

	_list = new std::list<int>;
	_limit = rhs._limit;

	return *this;
}

Span::~Span(void) {

	delete _list;
}

void Span::addNumber(int number) {
	
	if (_list->size() == _limit)
		throw std::runtime_error("Span: Exception: Number of elements exceeded");

	_list->push_front(number);
}

int Span::shortestSpan(void) {

	if (_list->size() < 2)
		throw std::runtime_error("Span: Exception: No span can be found");

	int distance = INT_MAX;

	_list->sort();

	std::list<int>::iterator next = _list->begin();

	for (std::list<int>::iterator prev = next++; next != _list->end(); prev++) {

		if (abs(*next - *prev) < distance)
			distance = abs(*next - *prev);

		next++;
	}

	return distance;
}

int Span::longestSpan(void) {

	if (_list->size() < 2)
		throw std::runtime_error("Span: Exception: No span can be found");

	return abs(*--_list->end() - *_list->begin());
}

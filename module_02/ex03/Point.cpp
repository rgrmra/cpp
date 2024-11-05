/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:38:16 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/05 17:51:52 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

Point::Point(void) :
	_x(Fixed()),
	_y(Fixed())
{
	if (LOGGER)
		std::cout
			<< "Point default constructor called"
			<< std::endl;
}

Point::Point(const float x, const float y) :
	_x(Fixed(x)),
	_y(Fixed(y))
{
	if (LOGGER)
		std::cout
			<< "Point default parameterized constructor called"
			<< std::endl;
}

Point::Point(const Point &point)
{
	if (LOGGER)
		std::cout
			<< "Point copy constructor called"
			<< std::endl;

	*this = point;
}


Point& Point::operator=(const Point &point)
{
	if (LOGGER)
		std::cout
			<< "Point copy assignment operator called"
			<< std::endl;

	if (this == &point)
		return *this;

	const_cast<Fixed&>(_x) = point.getX();
	const_cast<Fixed&>(_y) = point.getY();

	return *this;
}

Point::~Point(void)
{
	if (LOGGER)
		std::cout
			<< "Point destructor called"
			<< std::endl;
}

float Point::getX(void) const
{
	return _x.toFloat();
}

float Point::getY(void) const
{
	return _y.toFloat();
}

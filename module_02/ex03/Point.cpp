/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:38:16 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/30 14:41:23 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) :
	_x(Fixed()),
	_y(Fixed())
{
	
}

Point::Point(const float x, const float y) :
	_x(Fixed(x)),
	_y(Fixed(y))
{

}

Point::Point(const Point &point)
{
	*this = point;
}


Point &Point::operator=(const Point &point)
{
	if (this != &point)
	{
		const_cast<Fixed&>(_x) = point.getX();
		const_cast<Fixed&>(_y) = point.getY();
	}

	return *this;
}

Point::~Point(void)
{

}

float Point::getX(void) const
{
	return _x.toFloat();
}

float Point::getY(void) const
{
	return _y.toFloat();
}

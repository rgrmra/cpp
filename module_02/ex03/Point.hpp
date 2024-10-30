/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:24:24 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/30 13:47:01 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &point);
		Point &operator=(const Point &point);
		~Point(void);

		float getX(void) const;
		float getY(void) const;
};

#endif /* POINT_HPP */

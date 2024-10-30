/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:45:32 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/30 14:15:21 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Point calculate_vector(Point a, Point b)
{
	return Point(b.getX() - a.getX(), b.getY() - a.getY());
}

static double calculate_product(Point u, Point v)
{
	return u.getX() * v.getY() - u.getY() * v.getX();
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point AB = calculate_vector(a, b);
	Point AP = calculate_vector(a, point);

	Point BC = calculate_vector(b, c);
	Point BP = calculate_vector(b, point);

	Point CA = calculate_vector(c, a);
	Point CP = calculate_vector(c, point);

	double dAB = calculate_product(AB, AP);
	double dBC = calculate_product(BC, BP);
	double dCA = calculate_product(CA, CP);

	return (dAB > 0 && dBC > 0 && dCA > 0) || (dAB < 0 && dBC < 0 && dCA < 0);
}

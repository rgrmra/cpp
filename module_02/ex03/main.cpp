/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:21:46 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/04 15:08:12 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cstdlib>
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

static void checker(const bool value)
{
	if (value)
		std::cout << "The point is in the triangle" << std::endl;
	else
		std::cout << "The point is not in the triangle" << std::endl;
}

int main(void)
{
	checker(bsp(Point(0, 0), Point(2, 4), Point(0, 4), Point(1, 3)));
	//checker(bsp(Point(0, 0), Point(5, 10), Point(0, 10), Point(10, 10)));
	//checker(bsp(Point(0, 0), Point(5, 10), Point(0, 10), Point(4.9f, 9.9f)));
	//checker(bsp(Point(0, 0), Point(5, 10), Point(0, 10), Point(5, 10)));
	//checker(bsp(Point(-10,-10), Point(10, -10), Point(0, 10), Point(0,5)));

	return EXIT_SUCCESS;
}

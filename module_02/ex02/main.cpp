/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:21:46 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/04 14:46:44 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <string>

static std::string check(const bool value)
{
	return value ? "True" : "False";
}

int	main(void)
{
	Fixed 		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << std::endl;
	std::cout << "basic logic tests:" << std::endl;
	Fixed c(10.0f);
	Fixed d(20);
	Fixed e = 20;

	std::cout << c << " > " << d << "? " << check(c > b) << std::endl;
	std::cout << d << " > " << e << "? " << check(d > e) << std::endl;
	std::cout << d << " > " << c << "? " << check(d > c) << std::endl;
	std::cout << c << " < " << d << "? " << check(c < b) << std::endl;
	std::cout << d << " < " << e << "? " << check(d < e) << std::endl;
	std::cout << d << " < " << c << "? " << check(d < c) << std::endl;
	std::cout << c << " >= " << d << "? " << check(c >= d) << std::endl;
	std::cout << d << " >= " << e << "? " << check(d >= e) << std::endl;
	std::cout << d << " >= " << c << "? " << check(d >= c) << std::endl;
	std::cout << c << " <= " << d << "? " << check(c <= d) << std::endl;
	std::cout << d << " <= " << e << "? " << check(d <= e) << std::endl;
	std::cout << d << " <= " << c << "? " << check(d <= c) << std::endl;
	std::cout << c << " != " << d << "? " << check(c != d) << std::endl;
	std::cout << d << " != " << e << "? " << check(d != e) << std::endl;
	std::cout << c << " == " << d << "? " << check(c == d) << std::endl;
	std::cout << d << " == " << e << "? " << check(d == e) << std::endl;

	std::cout << std::endl;
	std::cout << "basic arithmetic tests:" << std::endl;
	std::cout << c << " - " << d << "? " << c - d  << std::endl;
	std::cout << d << " + " << e << "? " << d + e  << std::endl;
	std::cout << c << " / " << d << "? " << c / d  << std::endl;
	std::cout << d << " * " << e << "? " << d * e  << std::endl;

	std::cout << std::endl;
	std::cout << "pre and pos increment and decrement tests:" << std::endl;
	{ Fixed x(20); Fixed y(20); std::cout << x << " " << y << " x < y++" << "? " << check(x < y++) << std::endl; }
	{ Fixed x(20); Fixed y(20); std::cout << x << " " << y << " x < ++y" << "? " << check(x < ++y) << std::endl; }
	{ Fixed x(20); Fixed y(20); std::cout << x << " " << y << " x < y--" << "? " << check(x > y--) << std::endl; }
	{ Fixed x(20); Fixed y(20); std::cout << x << " " << y << " x < --y" << "? " << check(x > --y) << std::endl; }

	std::cout << std::endl;
	std::cout << "min and max tests:" << std::endl;
	std::cout << "min: " << c << " and " << d << ": " << Fixed::min(c, d) << std::endl;
	std::cout << check(&Fixed::min(c, d) == &c) << std::endl;
	std::cout << "max: " << c << " and " << d << ": " << Fixed::max(c, d) << std::endl;
	std::cout << check(&Fixed::max(c, d) == &d) << std::endl;

	std::cout << std::endl;
	std::cout << "min and max const tests:" << std::endl;
	const Fixed f(10);
	const Fixed g(20);
	std::cout << "min: " << f << ", " << g << ": " << Fixed::min(f, g) << std::endl;
	std::cout << check(&Fixed::min(f, g) == &f) << std::endl;
	std::cout << "max: " << f << ", " << g << ": " << Fixed::max(f, g) << std::endl;
	std::cout << check(&Fixed::max(f, g) == &g) << std::endl;

	return 0;
}

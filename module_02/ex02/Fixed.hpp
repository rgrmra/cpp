/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:37:46 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/29 18:54:09 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
	private:
		int _value;
		static const int _bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed(const int value);
		Fixed(const float value);
		Fixed &operator=(const Fixed &fixed);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const value);
		float toFloat(void) const;
		int toInt(void) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;
		Fixed operator+(const Fixed &fixed);
		Fixed operator-(const Fixed &fixed);
		Fixed operator*(const Fixed &fixed);
		Fixed operator/(const Fixed &fixed);
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);
		static Fixed &min(Fixed &fixed1, Fixed &fixed2);
		static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
		static Fixed &max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream &operator<<(std::ostream &os, const Fixed &value);

#endif /* FIXED_HPP */

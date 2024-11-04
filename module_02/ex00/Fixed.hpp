/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:37:46 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/04 12:13:49 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int _value;
		static const int _bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &src);
		Fixed& operator=(const Fixed &rhs);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif /* FIXED_HPP */

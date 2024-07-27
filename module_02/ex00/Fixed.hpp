/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:37:46 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/24 19:47:39 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int	_value;
		static const int _bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const value);
};

#endif

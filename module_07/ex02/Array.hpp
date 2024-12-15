/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:10:25 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/15 19:04:27 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <ostream>

template <typename T>
class Array {
	private:
		T *_data;
		unsigned int _size;
	
	public:
		Array(void);
		Array(const unsigned int &size);
		Array(const Array &src);
		Array &operator=(const Array &rhs);
		~Array(void);

		unsigned int size() const;

		T const &operator[](const unsigned int &index) const;
		T &operator[](const unsigned int &index);
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &src);

#include "Array.tpp"

#endif /* ARRAY_HPP */

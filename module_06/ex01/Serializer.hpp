/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:31:51 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/14 20:06:14 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

class Data;

class Serializer {
	private:
		Serializer(void);
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &rhs);

	public:
		~Serializer(void);

		static uintptr_t serialize(Data *ptr);
		static Data *deserializer(uintptr_t raw);
};

#endif /* SERIALIZER_HPP */

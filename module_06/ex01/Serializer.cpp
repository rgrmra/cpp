/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:40:49 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/14 19:58:03 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {

}

Serializer::Serializer(const Serializer &src) {

	*this = src;
}

Serializer &Serializer::operator=(const Serializer &rhs) {

	if (this == &rhs)
		return *this;

	return *this;
}

Serializer::~Serializer(void) {

}


uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserializer(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

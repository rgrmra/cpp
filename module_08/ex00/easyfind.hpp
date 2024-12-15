/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:12:01 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/15 19:50:50 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value) {

	for (typename T::iterator it = container.begin(); it != container.end(); it++) {
		if (*it == value)
			return it;
	}

	throw std::out_of_range("Exception: Easyfind: index out of bounds");
}

#endif /* EASYFIND_HPP */

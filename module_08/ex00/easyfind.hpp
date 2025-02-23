/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:12:01 by rde-mour          #+#    #+#             */
/*   Updated: 2025/02/08 12:08:54 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value) {

	typename T::iterator it = container.begin();
	for (; it != container.end(); it++)
		if (*it == value)
			return it;

	throw std::runtime_error("Exception: Easyfind: Value not Found");
}

#endif /* EASYFIND_HPP */

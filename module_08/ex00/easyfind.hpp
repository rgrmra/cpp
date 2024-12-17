/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:12:01 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/17 19:02:07 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value) {

	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (*it == value)
		return it;

	throw std::runtime_error("Exception: Easyfind: Value not Found");
}

#endif /* EASYFIND_HPP */

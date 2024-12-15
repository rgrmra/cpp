/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:44:47 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/15 16:00:10 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template<typename T, typename F>
void iter(T *array, size_t size, F function) {

	for (size_t i = 0; i < size; i++)
		function(array[i]);
}

template<typename T>
void pow(T &x) {
	
	x *= x;
}

template<typename T>
void print(T &x) {
	
	std::cout << x << std::endl;
}

#endif /* ITER_HPP */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:23:59 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/15 15:58:28 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T &x, T &y) {

	T &z = x;
	x = y;
	y = z;
}

template<typename T>
T min(T &x, T &y) {

	return x < y ? x : y;
}

template<typename T>
T max (T &x, T &y) {

	return x > y ? x : y;
}

#endif /* WHATEVER_HPP */

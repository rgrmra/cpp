/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:42:51 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/18 19:11:02 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include <stack>

template <typename T>
MutantStack<T>::MutantStack(void)
	: std::stack<T>() {

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &src)
	: std::stack<T>(src) {

	*this = src;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &rhs) {

	if (this == &rhs)
		return *this;

	std::stack<T>::operator=(rhs);

	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void) {

}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return std::stack<T>::c.end();
}

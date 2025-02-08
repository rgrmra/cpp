/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:33:18 by rde-mour          #+#    #+#             */
/*   Updated: 2025/01/04 16:16:13 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		MutantStack(void);
		MutantStack(const MutantStack<T> &src);
		MutantStack &operator=(const MutantStack<T> &rhs);
		~MutantStack(void);

		iterator begin(void);
		const_iterator begin(void) const;
		iterator end(void);
		const_iterator end(void) const;

};

#include "MutantStack.tpp"

template <typename T>
void puts(T container) {
	
	std::cout << "[ ";

	typename T::iterator it = container.begin();

	if (container.size()) {
		std::cout << *it;
		it++;
	}

	for (; it != container.end(); it++)
		std::cout << ", " << *it;
	
	std::cout << " ]" << std::endl;
}

#endif /* MUTANTSTACK_HPP */

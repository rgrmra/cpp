/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:34:10 by rde-mour          #+#    #+#             */
/*   Updated: 2025/08/20 09:07:33 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class PmergeMe {

	private:
		std::deque<int> _deque;
		std::vector<int> _vector;

		void parseInput(const std::string &list);

		int jacobSthal(const int &value);

		void insert(const size_t &level);
		void merge(const size_t &level);

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &rhs);
		~PmergeMe(void);

		void sort(const std::string &list);

};

template <typename C>
void print_container(const C &container)
{
    std::cout << "[";
    for (typename C::size_type i = 0; i < container.size(); i++) {
        std::cout << container[i];
        if (i + 1 < container.size())
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

#endif /* PMERGEME_HPP */

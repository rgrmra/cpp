/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:34:10 by rde-mour          #+#    #+#             */
/*   Updated: 2025/08/21 19:10:06 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class PmergeMe {

	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		size_t level;

		void parseInput(const std::string &list);

		std::pair<int, int> jacobSthal(const int &value);

		std::deque<int>::iterator dequeBinarySearch(std::deque<int> &main,
				const int &target, const size_t &length);
		std::vector<int>::iterator vectorBinarySearch(std::vector<int> &main,
				const int &target, const size_t &length);

		void vectorMerge(void);
		void dequeMerge(void);
		void vectorInsert(void);
		void dequeInsert(void);
		void vectorInsertions(std::vector<int> &main, const size_t &index);
		void dequeInsertions(std::deque<int> &main, const size_t &index);

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
    for (typename C::size_type i = 0; i < container.size(); i++) {
        std::cout << container[i];
        if (i + 1 < container.size())
            std::cout << " ";
    }
	std::cout << std::endl;
}

template <typename C>
void print_status(const C &container, const std::string &name,
		const std::pair<std::clock_t, double> &clock) {

	std::cout
		<< "Time to process a range of " << container.size()
		<< " elements with " << name
		<< " : " << std::fixed << std::setprecision(5)
		<< clock.second / CLOCKS_PER_SEC << " us"
		<< std::endl;
}

template <typename C>
bool is_container_ordered(const C &container) {

	for (size_t i = 1; i < container.size(); i++)
		if (container[i - 1] > container[i])
			return false;

	return true;
}

#endif /* PMERGEME_HPP */

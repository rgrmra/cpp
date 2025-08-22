/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:34:10 by rde-mour          #+#    #+#             */
/*   Updated: 2025/08/22 18:39:10 by rde-mour         ###   ########.org.br   */
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

		std::pair<int, int> jacobSthal(const int &value);

		void vectorMerge(void);
		void vectorInsert(void);
		void vectorInsertions(std::vector<int> &main, const size_t &index);
		std::vector<int>::iterator vectorBinarySearch(std::vector<int> &main,
				const int &target, const size_t &length);

		void dequeMerge(void);
		void dequeInsert(void);
		void dequeInsertions(std::deque<int> &main, const size_t &index);
		std::deque<int>::iterator dequeBinarySearch(std::deque<int> &main,
				const int &target, const size_t &length);

		void parseInput(const std::string &list);

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

#endif /* PMERGEME_HPP */

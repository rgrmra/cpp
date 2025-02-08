/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:11:39 by rde-mour          #+#    #+#             */
/*   Updated: 2025/02/08 13:16:27 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <stack>
#include "MutantStack.hpp"

void list_test(void) {
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
	std::cout << *it << std::endl;
	++it;
	}
	puts(mstack);
}

void stack_test(void) {

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		it++;
	}
	std::stack<int> s(mstack);

	puts(mstack);
}

void my_test_add(MutantStack<int> &ms, std::list<int> &l, int value) {

	std::cout << "add: " << value << std::endl;
	ms.push(value);
	l.push_back(value);
}

void my_test_puts(MutantStack<int> &ms, std::list<int> &l) {
	
	puts(ms);
	puts(l);
}

void my_test_pop(MutantStack<int> &ms, std::list<int> &l) {

	std::cout << "pop: " << std::endl;

	if (ms.size())
		ms.pop();
	if (l.size())
		l.pop_back();
}

int main(void) {

	std::cout << "STACK TEST" << std::endl;
	stack_test();

	std::cout << "\nLIST TEST" << std::endl;
	list_test();

	std::cout << "\nMY TEST" << std::endl;
	srand(static_cast<unsigned int>(time(0)));

	MutantStack<int> ms;
	std::list<int> l;
	my_test_add(ms, l, rand() % 200);
	my_test_add(ms, l, rand() % 200);
	my_test_puts(ms, l);
	my_test_pop(ms, l);
	my_test_puts(ms, l);
	my_test_add(ms, l, rand() % 200);
	my_test_puts(ms, l);
	my_test_pop(ms, l);
	my_test_puts(ms, l);
	my_test_pop(ms, l);
	my_test_pop(ms, l);
	my_test_puts(ms, l);
	my_test_add(ms, l, rand() % 200);
	my_test_add(ms, l, rand() % 200);
	my_test_add(ms, l, rand() % 200);
	my_test_add(ms, l, rand() % 200);
	my_test_add(ms, l, rand() % 200);
	my_test_add(ms, l, rand() % 200);
	my_test_puts(ms, l);

	return EXIT_SUCCESS;
}

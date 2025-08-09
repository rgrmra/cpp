/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:11:39 by rde-mour          #+#    #+#             */
/*   Updated: 2025/08/09 14:42:20 by rde-mour         ###   ########.org.br   */
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

void my_test_rputs(MutantStack<int> &ms, std::list<int> &l) {
	
	rputs(ms);
	rputs(l);
}

void my_test_pop(MutantStack<int> &ms, std::list<int> &l) {

	std::cout << "pop: " << std::endl;

	if (ms.size())
		ms.pop();
	if (l.size())
		l.pop_back();
}

void my_test_const_puts(const MutantStack<int> &cms, const std::list<int> &cl) {

	const_puts(cms);
	const_puts(cl);
}

void my_test_const_rputs(const MutantStack<int> &cms, const std::list<int> &cl) {

	const_rputs(cms);
	const_rputs(cl);
}

int main(void) {

	std::cout << "STACK TEST ITERATOR" << std::endl;
	stack_test();

	std::cout << "\nLIST TEST ITERATOR" << std::endl;
	list_test();

	std::cout << "\nMY TEST ITERATOR" << std::endl;
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

	std::cout << "\nMY TEST REVERSE ITERATOR" << std::endl;
	my_test_rputs(ms, l);

	const MutantStack<int> cms(ms);
	const std::list<int> cl(l);

	std::cout << "\nMY TEST CONST ITERATOR" << std::endl;
	my_test_const_puts(cms, cl);

	std::cout << "\nMY TEST CONST REVERSE ITERATOR" << std::endl;
	my_test_const_rputs(cms, cl);

	return EXIT_SUCCESS;
}

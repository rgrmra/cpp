/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:16:41 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/15 15:05:12 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>

int main(void) {

	Base *base = generate();
	Base &ref = *base;

	identify(base);
	identify(ref);

	delete base;

	return EXIT_SUCCESS;
}

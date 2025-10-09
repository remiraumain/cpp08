/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:12:14 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/09 16:48:50 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>

int main()
{
	Span a(10);

	std::srand(std::time(0));
	try
	{
		for (int i = 0; i < 10; i++)
			a.addNumber(std::rand());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Span b(10);
	std::list<int> l;
	for (int i = 0; i < 10; i++)
			l.push_back(i);
	try
	{
		b.addNumbers(l.begin(), l.end());
		std::cout << b.longestSpan() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}

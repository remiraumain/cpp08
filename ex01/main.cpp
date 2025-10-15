/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:12:14 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/15 11:49:54 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>

int main()
{
	std::srand(std::time(0));
	std::cout << "-------Span a-------\n";
	try
	{
		Span a(2);

		for (int i = 0; i < 10; i++)
			a.addNumber(std::rand());

		std::cout << "Shortest: " << a.shortestSpan() << "\n";
		std::cout << "Longest: " << a.longestSpan() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n-------Span b-------\n";
	try
	{
		Span b(5);

		int arr[] = {6, -2147483648, 2147483647, 8, 21};
		std::list<int> l(arr, arr + 5);
		b.addNumbers(l.begin(), l.end());

		std::cout << "Shortest: " << b.shortestSpan() << "\n";
		std::cout << "Longest: " << b.longestSpan() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:37:02 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/09 10:19:17 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> v;
	v.push_back(4);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);

	const std::vector<int> &cv = v;
	try
	{
		std::vector<int>::iterator it = ::easyfind(v, 3);
		std::cout << "vector value found: " << *it << "\n";

		std::vector<int>::const_iterator constIt = ::easyfind(cv, 9);
		std::cout << "vecotr value found: " << *constIt << "\n";
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}


	std::list<int> l;
	l.push_back(4);
	l.push_back(1);
	l.push_back(3);
	l.push_back(2);

	const std::list<int> cl(l.begin(), l.end());
	try
	{
		std::list<int>::iterator it = ::easyfind(l, 20);
		std::cout << "list value found: " << *it << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		l.push_back(20);
		std::list<int>::iterator it = ::easyfind(l, 20);
		std::cout << "list value found: " << *it << "\n";

		std::list<int>::const_iterator constIt = ::easyfind(cl, 20);
		std::cout << "vecotr value found: " << *constIt << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
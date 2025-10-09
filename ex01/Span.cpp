/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:02:14 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/09 11:17:54 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span() : _size(0)
{
	std::cout << "Span constructed\n";
}

Span::Span(const Span &other) : _size(other._size), _numbers(other._numbers)
{
	std::cout << "Span copy-constructed\n";
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_size = other._size;
		_numbers = other._numbers;
	}
	std::cout << "Span copy-assigned\n";
}

Span::~Span()
{
	std::cout << "Span destructed\n";
}

Span::Span(size_t N) : _size(N)
{
	std::cout << "Span constructed\n";
}

void Span::addNumber(int nb)
{
	if (_numbers.size() <= _size)
		_numbers.push_back(nb);
	throw std::length_error("Span: capacity exceeded in addNumber");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:02:14 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/09 16:29:57 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>

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
	return (*this);
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
	if (_numbers.size() + 1 > _size)
		throw std::length_error("Span: capacity exceeded in addNumber");
	_numbers.push_back(nb);
}


size_t Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw std::logic_error("Span: at least 2 numbers required in longestSpan");
	
	std::vector<int>::iterator max = std::max_element(_numbers.begin(), _numbers.end());
	std::vector<int>::iterator min = std::min_element(_numbers.begin(), _numbers.end());
	return (*max - *min);
}
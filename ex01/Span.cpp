/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:02:14 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/15 11:42:18 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>

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
	_numbers.reserve(_size);
}

void Span::addNumber(int nb)
{
	if (_numbers.size() + 1 > _size)
		throw std::length_error("Span: capacity exceeded in addNumber");
	_numbers.push_back(nb);
}


size_t Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Span: at least 2 numbers required in shortestSpan");
	
	std::vector<int> tmp(_numbers);
	std::sort(tmp.begin(), tmp.end());
	long long min = static_cast<long long>(tmp[1]) - static_cast<long long>(tmp[0]);
	for (size_t i = 1; i + 1 < tmp.size(); i++)
	{
		long long diff = static_cast<long long>(tmp[i + 1]) - static_cast<long long>(tmp[i]);
		if (diff < min)
			min = diff;
	}
	return (min);
}

size_t Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Span: at least 2 numbers required in longestSpan");
	
	std::vector<int>::const_iterator max = std::max_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator min = std::min_element(_numbers.begin(), _numbers.end());
	return (static_cast<long long>(*max) - static_cast<long long>(*min));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:49:36 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/15 11:45:31 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <vector>
#include <stdexcept>
#include <iostream>

class Span
{
	public:
		Span();
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		
		Span(std::size_t N);

		void addNumber(int nb);
		template<typename It>
		void addNumbers(It first, It last)
		{
			typedef typename std::iterator_traits<It>::difference_type dType;
			dType nbSize = std::distance(first, last);
			if (nbSize < 0)
				throw std::logic_error("Span: reversed range in addNumbers");
			if (_numbers.size() + static_cast<size_t>(nbSize) > _size)
				throw std::length_error("Span: capacity exceeded in addNumbers");
			
			_numbers.insert(_numbers.end(), first, last);
		}
		
		size_t shortestSpan() const;
		size_t longestSpan() const;
	
	private:
		size_t _size;
		std::vector<int> _numbers;
};
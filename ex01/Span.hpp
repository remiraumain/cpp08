/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:49:36 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/09 16:50:29 by rraumain         ###   ########.fr       */
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
			if (_numbers.size() + nbSize > _size)
				throw std::length_error("Span: capacity exceeded in addNumbers");
				
			_numbers.insert(_numbers.end(), first, last);
		}
		
		size_t shortestSpan(); // 4 8 3 -> 3 4 8 -> 1 -> 1
		size_t longestSpan();
	
	private:
		size_t _size;
		std::vector<int> _numbers;
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:49:36 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/09 11:02:12 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <vector>

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
		void addNumbers(It begin, It last);
		
		size_t shortestSpan();
		size_t longestSpan();
	
	private:
		size_t _size;
		std::vector<int> _numbers;
};
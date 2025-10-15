/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:59:19 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/15 17:17:06 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public :
		typedef std::stack<T, Container> 				base_type;
		typedef typename base_type::container_type		container_type;
		typedef typename container_type::iterator		iterator;
		typedef typename container_type::const_iterator	const_iterator;
		
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack();

		iterator begin();
		iterator end();
		
		const_iterator begin() const;
		const_iterator end() const;
};

#include "MutantStack.tpp"
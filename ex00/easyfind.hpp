/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:37:00 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/09 10:06:33 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T &container,const int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
		return (it);
	throw std::runtime_error("Value iterator not found");
}

template<typename T>
typename T::const_iterator easyfind(const T &container,const int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
		return (it);
	throw std::runtime_error("Value const iterator not found");
}
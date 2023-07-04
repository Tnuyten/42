/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:08:23 by tnuyten           #+#    #+#             */
/*   Updated: 2023/07/02 19:52:04 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <cstddef>
#include <type_traits>

template <typename T>
using Iter = typename T::iterator;

template <typename T>
typename	std::enable_if<
				std::is_same<Iter<T>, decltype(std::declval<T>().begin())>::value,
				Iter<T>
			>::type
easyfind(T& container, int value) {
	Iter<T> it = container.begin();
	Iter<T> end = container.end();

	while (it != end) {
		if (*it == value) {
			return it;
		}
		it++;
	}

	return end;
}

#endif
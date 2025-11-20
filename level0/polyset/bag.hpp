/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bag.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:12:00 by fatkeski          #+#    #+#             */
/*   Updated: 2025/11/19 06:51:05 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// prevents multiple inclusion — once this file is included, subsequent includes are ignored.
// bag data structure, equivalent to a multiset. It stores a value and the count of its occurrences.
// Abstract class (an interface). Anything that implements a bag must support the following 4 operations.
class bag
{
 public:
	virtual void insert (int) = 0;
	virtual void insert (int *, int) = 0;
	virtual void print() const = 0;
	virtual void clear() = 0;
};

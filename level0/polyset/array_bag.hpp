/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_bag.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:39:23 by fatkeski          #+#    #+#             */
/*   Updated: 2025/11/19 06:51:24 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "bag.hpp"

class array_bag : virtual public bag
{
 protected:
	int *data;
	int size;

 public:
	array_bag();
	array_bag(const array_bag &);
	array_bag &operator=(const array_bag &other);
	~array_bag();

	void insert(int);
	void insert(int *, int);
	void print() const;
	void clear();
};

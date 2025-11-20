/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:12:59 by fatkeski          #+#    #+#             */
/*   Updated: 2025/11/19 06:48:15 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

void set::insert (int value)
{
	if(!(this->has(value)))
		bag.insert(value);
}

void set::insert (int *data, int size)
{
	for(int i = 0; i < size; i++)
		this->insert(data[i]);
}
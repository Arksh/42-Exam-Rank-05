/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:27:47 by fatkeski          #+#    #+#             */
/*   Updated: 2025/11/19 06:44:34 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_tree_bag.hpp"

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& source)
{
	if(this != &source)
	{
		tree_bag::operator=(source);
	}
	return(*this);
}

bool searchable_tree_bag::search(node* node, const int value) const
{
	if(node == nullptr)
		return(false);
	if(node->value == value)
		return(true);
	else if(value < node->value)
	{
		return(search(node->l, value));
	}
	else
		return(search(node->r, value));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:26:28 by fatkeski          #+#    #+#             */
/*   Updated: 2025/11/19 06:44:30 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tree_bag.hpp"
#include "searchable_bag.hpp"


class searchable_tree_bag : public tree_bag, public searchable_bag
{
	private:
		bool search(node* node, const int value) const;
	public:
		searchable_tree_bag() {}
		searchable_tree_bag(const searchable_tree_bag& source): tree_bag(source) {}
		searchable_tree_bag& operator=(const searchable_tree_bag& source);
		bool has(int value) const { return(search(this->tree, value ));}
		~searchable_tree_bag() {}
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:42:38 by fatkeski          #+#    #+#             */
/*   Updated: 2025/11/19 06:49:36 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_bag.hpp"

// The "wrapping" operation usually means a class contains another class,
// function, or data to provide an interface.
// WRAPPING BY REFERENCE
class set
{
	private:
		// Reference to a searchable_bag
		searchable_bag& bag;
		// C++98: disable default/copy/assignment by declaring them private and not defining them
		set();
		set(const set& source);
		set& operator=(const set& source);
		
	public:
		// Constructor that initializes the set with a searchable_bag reference
		set(searchable_bag& s_bag) : bag(s_bag) {}

		// Methods that delegate to the underlying searchable_bag
		bool has(int value) const { return(bag.has(value)); }
		void print() const { bag.print(); }
		void clear() { bag.clear(); }
		
		// Methods to insert values ensuring uniqueness
		void insert (int);
		void insert (int *, int);

		const searchable_bag& get_bag() { return(this->bag); }

		~set() {}

};

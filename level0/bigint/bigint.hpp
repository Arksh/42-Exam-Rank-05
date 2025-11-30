/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:17:26 by fatkeski          #+#    #+#             */
/*   Updated: 2025/11/20 08:11:40 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT
#define BIGINT

#include <iostream>
#include <string>
#include <cstdlib>

class bigint
{
	private:
		std::string str;
		
	public:
		bigint() : str("0") {};
		bigint(unsigned int num);
		bigint(const bigint& source) { *this = source; };
		bigint& operator=(const bigint& source);

		std::string getStr() const { return(this->str); };


		// addition
		bigint operator+(const bigint& other)const;
		bigint& operator+=(const bigint& other);

		// increments
		bigint& operator++(); // ++x
		bigint operator++(int); // x++

		// shift with num
		bigint operator<<(unsigned int n)const;
		bigint operator>>(unsigned int n)const;
		bigint& operator<<=(unsigned int n);
		bigint& operator>>=(unsigned int n);

		// shift with object
		bigint operator<<(const bigint& other)const;
		bigint operator>>(const bigint& other)const;
		bigint& operator<<=(const bigint& other);
		bigint& operator>>=(const bigint& other);

		// comparison ==, !=, <, >, <=, >=
		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;
		bool operator<(const bigint& other) const;
		bool operator>(const bigint& other) const;
		bool operator<=(const bigint& other) const;
		bool operator>=(const bigint& other) const;

};

std::ostream& operator<<(std::ostream& output, const bigint& obj);

#endif

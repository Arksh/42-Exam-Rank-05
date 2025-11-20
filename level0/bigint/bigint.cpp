/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:27:29 by fatkeski          #+#    #+#             */
/*   Updated: 2025/11/20 09:32:24 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"
#include <sstream>

bigint::bigint()
{
	this->str = "0";
}

bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	this->str = ss.str();
	// std::cout << "str: " << str << std::endl;
}

bigint::bigint(const bigint& source)
{
	*this = source;
}

bigint& bigint::operator=(const bigint& source)
{
	if(this == &source)
		return*this;
	this->str = source.str;
	return*this;
}

std::string bigint::getStr() const
{
	return(this->str);
}

std::string reverse(const std::string& str)
{
	std::string revStr;
	for(size_t i = str.length(); i > 0; i--)
		revStr.push_back(str[i - 1]);
	return(revStr);
}

std::string addition(const bigint& obj1, const bigint& obj2)
{
	std::string str1 = reverse(obj1.getStr());
	// std::string str1 = obj1.getStr();
	// std::reverse(str1.begin(), str1.end());
	std::string str2 = reverse(obj2.getStr());
	// std::string str2 = obj1.getStr();
	// std::reverse(str2.begin(), str1.end());
	std::string result;

	// Make both strings the same length by appending '0's to the shorter one
	
	while (str1.length() < str2.length())
		str1.push_back('0');
	while (str2.length() < str1.length())
		str2.push_back('0');

	// if(str1.length() > str2.length())
	// {
	// 	int diff = str1.length() - str2.length();
	// 	while(diff > 0)
	// 	{
	// 		str2.push_back('0');
	// 		diff--;
	// 	}
	// }
	// else if(str2.length() > str1.length())
	// {
	// 	int diff = str2.length() - str1.length();
	// 	while(diff > 0)
	// 	{
	// 		str1.push_back('0');
	// 		diff--;
	// 	}
	// }

	int carry = 0;
	int digit1;
	int digit2;
	size_t len = str1.length();
	for(size_t i = 0; i < len; i++)
	{
		digit1 = str1[i] - '0';
		digit2 = str2[i] - '0';
		int res = digit1 + digit2 + carry;
		carry = 0;
		if(res > 9)
			carry = res / 10;
		result.push_back((res % 10) + '0');
	}
	if(carry != 0)
		result.push_back(carry + '0');
	return(reverse(result));
}

bigint bigint::operator+(const bigint& other) const
{
	bigint temp;
	temp.str.clear();
	std::string result = addition(*this, other);
	temp.str = result;

	return(temp);
}

bigint& bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return*this;
}

bigint& bigint::operator++()
{
	*(this) = *(this) + bigint(1);
	return*this;
}

bigint bigint::operator++(int)
{
	bigint temp = *this;
	*(this) = *(this) + bigint(1);
	return(temp);
}


bigint bigint::operator<<(unsigned int n)const
{
	bigint temp = *this;

	temp.str.insert(temp.str.end(), n, '0');
	//std::cout << temp.str << std::endl;
	return(temp);
}

bigint bigint::operator>>(unsigned int n)const
{
	bigint temp = *this;
	size_t len = temp.str.length();
	if(n >= len)
		temp.str = "0";
	else
		temp.str.erase(temp.str.length() - n, n); // first parameter: the starting index where deletion begins, second: how many characters to erase
	return(temp);
}

bigint& bigint::operator<<=(unsigned int n)
{
	*this = *this << n;
	return*this;
}

bigint& bigint::operator>>=(unsigned int n)
{
	*this = *this >> n;
	return*this;
}

unsigned int stringToUINT(std::string str)
{
	std::stringstream ss(str);
	unsigned int res;
	ss >> res;
	return (res);
}

bigint bigint::operator<<(const bigint& other)const
{
	bigint temp;
	temp = *this << stringToUINT(other.str);
	return(temp);
}

bigint bigint::operator>>(const bigint& other)const
{
	bigint temp;
	temp = *this >> stringToUINT(other.str);
	return(temp);
}

bigint& bigint::operator<<=(const bigint& other)
{
	*this = *this << stringToUINT(other.str);
	return*this;
}

bigint& bigint::operator>>=(const bigint& other)
{
	*this = *this >> stringToUINT(other.str);
	return*this;
}


bool bigint::operator==(const bigint& other) const
{
	return (getStr() == other.getStr());
}

bool bigint::operator!=(const bigint& other) const
{
	return (getStr() != other.getStr());
}

bool bigint::operator<(const bigint& other) const
{
	std::string str1 = getStr();
	std::string str2 = other.getStr();

	if(str1.length() != str2.length())
		return(str1.length() < str2.length());
	return(str1 < str2); // lexicographical comparison
}

bool bigint::operator>(const bigint& other) const
{
	return (other < *this);
}

bool bigint::operator<=(const bigint& other) const
{
	return (!(*this > other));
}

bool bigint::operator>=(const bigint& other) const
{
	return (!(*this < other));
}

// non member func
std::ostream& operator<<(std::ostream& output, const bigint& obj)
{
	output << obj.getStr();
	return(output);
}

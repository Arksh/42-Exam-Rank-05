/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:39:15 by fatkeski          #+#    #+#             */
/*   Updated: 2025/11/15 11:01:43 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2& vect2::operator=(const vect2& source)
{
	if(this != &source)
	{
		this->x = source.x;
		this->y = source.y;
	}
	return(*this);
}

int& vect2::operator[](int index)
{
	if(index == 0)
		return(this->x);
	return(this->y);
}

int vect2::operator[](int index) const
{
	if(index == 0)
		return(this->x);
	return(this->y);
}

vect2& vect2::operator*=(int num)
{
	this->x *= num;
	this->y *= num;
	return(*this);
}

vect2& vect2::operator+=(const vect2& obj)
{
	this->x += obj.x;
	this->y += obj.y;
	return(*this);
}

vect2& vect2::operator-=(const vect2& obj)
{
	this->x -= obj.x;
	this->y -= obj.y;
	return(*this);
}

vect2& vect2::operator*=(const vect2& obj)
{
	this->x *= obj.x;
	this->y *= obj.y;
	return(*this);
}

vect2& vect2::operator++()
{
	this->x += 1;
	this->y += 1;
	return(*this);
}

vect2 vect2::operator++(int)
{
	vect2 temp = *this;

	++(*this);
	return(temp);
}

vect2& vect2::operator--()
{
	this->x -= 1;
	this->y -= 1;
	return(*this);
}

vect2 vect2::operator--(int)
{
	vect2 temp = *this;

	--(*this);
	return(temp);
}

bool vect2::operator==(const vect2& obj) const
{
	if((this->x == obj.x) && (this->y == obj.y))
		return(true);
	return(false);
}

bool vect2::operator!=(const vect2& obj) const
{
	return(!(obj == *this));
}


std::ostream& operator<<(std::ostream& os,const vect2& v)
{
	os << "{" << v[0] << ", " << v[1] << "}";
	return(os);
}


vect2 operator*(int num, const vect2& obj)
{
	return vect2(obj[0] * num, obj[1] * num);
}


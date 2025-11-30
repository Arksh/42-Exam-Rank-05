/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:20:54 by fatkeski          #+#    #+#             */
/*   Updated: 2025/11/19 17:37:30 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	private:
		int x;
		int y;
	public:
		vect2() : x(0), y(0) {};
		vect2(int num1, int num2) : x(num1), y(num2) {};
		vect2(const vect2& source) { *this = source; };
		vect2& operator=(const vect2& source);

		// Subscript operators
		int& operator[](int index);
		int operator[](int index) const;

		// Unary minus
		vect2 operator-() const { return vect2(-x, -y); }

		// Scalar multiplication
		vect2 operator*(int num) const { return vect2(x * num, y * num); };
		
		vect2& operator*=(int num);
		
		// Vector operations
		vect2 operator+(const vect2& obj) const { return vect2(x + obj.x, y + obj.y); };
		vect2 operator-(const vect2& obj) const { return vect2(x - obj.x, y - obj.y); };
		vect2 operator*(const vect2& obj) const { return vect2(x * obj.x, y * obj.y); };

		vect2& operator+=(const vect2& obj);
		vect2& operator-=(const vect2& obj);
		vect2& operator*=(const vect2& obj);

		vect2& operator++(); // prefix
		vect2 operator++(int); // postfix
		vect2& operator--();
		vect2 operator--(int);

		bool operator==(const vect2& obj) const;
		bool operator!=(const vect2& obj) const;

		~vect2() {}
};

vect2 operator*(int num, const vect2& obj);

std::ostream& operator<<(std::ostream& os,const vect2& obj);

#endif


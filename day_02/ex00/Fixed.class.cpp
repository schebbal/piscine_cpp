/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Fixed.class.cpp                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/03 16:57:50 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 08:54:44 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.class.hpp"

Fixed::Fixed(void) : _fx(0)
{
	std::cout << "Default constructor called" << std::endl;

	return;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;

	return ;
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fx = rhs.getRawBits();

	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return this->_fx;
}

void Fixed::setRawBits(int const raw)
{
	this->_fx = raw;
}

const int Fixed::_bits = 8;
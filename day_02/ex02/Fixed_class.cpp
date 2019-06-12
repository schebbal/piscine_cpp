/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Fixed_class.cpp                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 09:25:31 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 20:05:36 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Fixed_class.hpp"

int	const	Fixed::_bits = 8;

Fixed::Fixed(void) : _fx(0)
{
	return;
}

Fixed::Fixed(Fixed const &rhs)
{
	*this = rhs;
	return;
}

Fixed::Fixed(int const rhs)
{
	setRawBits(rhs << this->_bits);
	return;
}

Fixed::Fixed(float const rhs)
{
	setRawBits(roundf(rhs * (1 << this->_bits)));
	return;
}

Fixed::~Fixed(void)
{
	return;
}

int		Fixed::getRawBits(void) const
{
	return (this->_fx);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fx = raw;
	return;
}

int		Fixed::toInt(void) const
{
	return (getRawBits() >> this->_bits);
}

float	Fixed::toFloat(void) const
{
    return ((float)getRawBits() / (1 << this->_bits));
}


bool	Fixed::operator>(Fixed const &r) const
{
	return (this->toFloat() > r.toFloat());
}

bool	Fixed::operator<(Fixed const &r) const
{
    return (this->toFloat() < r.toFloat());
}

bool	Fixed::operator>=(Fixed const &r) const
{
    return (this->toFloat() >= r.toFloat());
}

bool	Fixed::operator<=(Fixed const &r) const
{
    return (this->toFloat() <= r.toFloat());
}

bool	Fixed::operator==(Fixed const &r) const
{
    return (this->toFloat() == r.toFloat());
}

bool	Fixed::operator!=(Fixed const &r) const
{
    return (this->toFloat() != r.toFloat());
}


Fixed	&Fixed::operator=(Fixed const &r)
{
	if (this != &r)
		this->_fx = r.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &r) const
{
	return (Fixed(this->_fx + r.getRawBits()));
}

Fixed	Fixed::operator-(Fixed const &r) const
{
	return (Fixed(this->_fx - r.getRawBits()));
}

Fixed	Fixed::operator*(Fixed const &r) const
{
	return (Fixed(this->toFloat() * r.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &r) const 
{
	if (r.toFloat() != 0)
		return (Fixed(this->toFloat() / r.toFloat()));
	else
	{
		std::cout << "Divide by 0 is impossible." << std::endl;
		return (Fixed(0));
	}
}

Fixed	&Fixed::operator++(void)
{
	this->_fx = this->_fx + 1;
	return (*this);
}

Fixed	Fixed::operator++(int rhs)
{
	Fixed fplus(*this);
	(void)rhs;

	this->_fx = this->_fx + 1;
	return (fplus);
}

Fixed	&Fixed::operator--(void)
{
	this->_fx = this->_fx - 1;
	return (*this);
}

Fixed	Fixed::operator--(int rhs)
{
	Fixed fminus(*this);
	(void)rhs;
	
	this->_fx = this->_fx - 1;
	return (fminus);
}

Fixed	&Fixed::min(Fixed &l, Fixed &r)
{
	return ((l.toFloat() < r.toFloat()) ? l : r);
}

Fixed 	&Fixed::max(Fixed &l, Fixed &r)
{
	return ((l.toFloat() > r.toFloat()) ? l : r);
}

Fixed const		&Fixed::min(Fixed const &l, Fixed const &r)
{
	return ((l.toFloat() < r.toFloat()) ? l : r);
}

Fixed const		&Fixed::max(Fixed const &l, Fixed const &r)
{
	return ((l.toFloat() > r.toFloat()) ? l : r);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &r)
{
	o << r.toFloat();
	return (o);
}
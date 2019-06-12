/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   span.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 11:24:49 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/11 15:35:26 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int n): _size(n)
{
	_store.reserve(n);
	return;
}

Span::Span(Span &obj) 
{
	*this = obj;
	return;
}

Span::~Span(void)
{
	return;
}

Span &Span::operator=(Span const &r) 
{
	this->_store = r._store;
	return (*this);
}

void		Span::addNumber(int num)
{
	if (_store.size() < _size)
		_store.push_back(num);
	else
		throw Span::StorageLimitException();
}

int			Span::shortestSpan(void)
{
	if (_store.size() < 1 || _size <= 1)
		throw Span::NotEnoughValuesException();
	std::vector<int>		copy = _store;
	std::sort(copy.begin(), copy.end());
	std::vector<int>::iterator it  = copy.begin();
	std::vector<int>::iterator one = copy.begin();
	std::vector<int>::iterator two = copy.end();
	it++;
	two--;
	unsigned int i = 0;
	
	while (i < (_size - 1))
	{
		if (abs(*one - *it) < abs(*one - *two))
			two = it;
		else if (abs(*two - *it) < abs(*one - *two))
			one = it;
		i++;
		it++;
	}
	return (abs(*one - *two));
}

int			Span::longestSpan(void)
{
	if (_store.size() < 1 || _size <= 1)
		throw Span::NotEnoughValuesException();
	std::vector<int>	copy = _store;
	return(*std::max_element(copy.begin(), copy.end()) - *std::min_element(copy.begin(), copy.end()));
}

/*
** StorageLimitException Nested Class
*/

Span::StorageLimitException::StorageLimitException(void)
{
	return;
}

Span::StorageLimitException::StorageLimitException(StorageLimitException const &obj)
{
	*this = obj;
	return;
}

Span::StorageLimitException::~StorageLimitException(void) throw()
{
	return;
}

Span::StorageLimitException &Span::StorageLimitException::operator=(StorageLimitException const &r) 
{
	(void)r;
	return (*this);
}

const char* Span::StorageLimitException::what() const throw()
{
	return ("Error: Storage capacity is maxed.");
}



/*
** NotEnoughValuesException Nested Class
*/

Span::NotEnoughValuesException::NotEnoughValuesException(void)
{
	return;
}

Span::NotEnoughValuesException::NotEnoughValuesException(NotEnoughValuesException const &obj)
{
	*this = obj;
	return;
}

Span::NotEnoughValuesException::~NotEnoughValuesException(void) throw()
{
	return;
}

Span::NotEnoughValuesException &Span::NotEnoughValuesException::operator=(NotEnoughValuesException const &r) 
{
	(void)r;
	return (*this);
}

const char* Span::NotEnoughValuesException::what() const throw()
{
	return ("Error: Not enough values in storage to determine span");
}
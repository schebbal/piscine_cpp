/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Brain.cpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/03 11:07:47 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 11:27:29 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain( void )
{
}

Brain::~Brain( void )
{
}

std::string		Brain::identify( void ) const
{
	std::stringstream ret;
	ret << this;
	return ret.str();
}
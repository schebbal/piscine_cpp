/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Weapon.cpp                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/03 13:28:11 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 15:49:43 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include "Weapon.hpp"


Weapon::Weapon( std::string str ) : type(str)
{
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}

std::string const &Weapon::getType()
{
	return (this->type);
}

void		Weapon::setType( std::string str )
{
	this->type = str;
}
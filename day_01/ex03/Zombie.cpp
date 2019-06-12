/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Zombie.cpp                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 15:26:15 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 10:21:22 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie()
{
	return;
}

Zombie::~Zombie(void) 
{
	std::cout << this->name << " has died." << std::endl;
	return;
}

void	Zombie::announce()
{
	std::cout << "<" << this->name << " (" << this->type << ")>  Braiiiiiiinnnssss.." << std::endl;
	return;
}
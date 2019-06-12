/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   HumanB.cpp                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/03 14:12:28 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 18:05:12 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string nick) : name(nick)
{
	return;
}

HumanB::~HumanB(void) 
{
	return;
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with " << this->weapon->getType() << std::endl;
	return;
}

void	HumanB::setWeapon(Weapon &weap)
{
	this->weapon = &weap;
	return;
}

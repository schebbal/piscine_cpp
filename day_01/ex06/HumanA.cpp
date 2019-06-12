/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   HumanA.cpp                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/03 11:10:17 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 18:14:07 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include "HumanA.hpp"

HumanA::HumanA( std::string nick, Weapon &weap ) : weapon(weap), name(nick)
{
	return ;
}

HumanA::~HumanA( void )
{
	return ;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with " << this->weapon.getType() << std::endl;
	return;
}
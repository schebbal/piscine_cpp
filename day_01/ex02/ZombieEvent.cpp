/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ZombieEvent.cpp                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 15:26:48 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 09:11:59 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(std::string nick, std::string desc)
{
	this->type = desc;
	newZombie(nick);
	return;
}

ZombieEvent::~ZombieEvent(void) 
{
	std::cout << "All Zombie Events has died ." << std::endl;
	return;
}

void	ZombieEvent::setZombieType(std::string desc)
{
	this->type = desc;
	std::cout << "Zombie type has been set to: " << this->type << std::endl;
	return;
}

Zombie*	ZombieEvent::newZombie(std::string name)
{
	Zombie	*createZombie = new Zombie(name, this->type);
	return (createZombie);
}

Zombie*	ZombieEvent::randomChump()
{
	int i = rand();
	std::string name = " ";

	if (i % 8 == 0)
		name = "Gracia";
	else if (i % 8 == 1)
		name = "Poppuri";
	else if (i % 8 == 2)
		name = "Sadie";
	else if (i % 8 == 3)
		name = "Fae";
	else if (i % 8 == 4)
		name = "Misteltainn";
	else if (i % 8 == 5)
		name = "Nocturna";
	else if (i % 8 == 6)
		name = "Lyra";
	else
		name = "Rhyme";
	Zombie	*createZombie = new Zombie(name, this->type);

	return (createZombie);
}
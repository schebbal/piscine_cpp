/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 15:26:03 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 09:10:33 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int		main()
{
	/* initialize random seed: */
   srand(time(NULL));
   
	std::cout << "Zombie created on Stack" << std::endl;
	Zombie 	Scarmiglione = Zombie("Scarmiglione", "zombie avec une lance et un bouclier");

	std::cout << std::endl << "Zombie Event created on Heap" << std::endl;
	ZombieEvent	*Skagdead = new ZombieEvent("Skagdead", "Celui avec la scie qui peut te tuer en 1 coup");

	std::cout << std::endl << "Zombie type setting to Popstar" << std::endl;
	Skagdead->setZombieType("Popstar");

	std::cout << std::endl << "Zombie Event again with new type" << std::endl;
	Skagdead->newZombie("Skagdead");

	std::cout << std::endl << "Changing zombie type to Assassin" << std::endl;
	Skagdead->setZombieType("Assassin");

	std::cout << std::endl << "Random name Zombie Event with new type" << std::endl;
	Skagdead->randomChump();

	std::cout << std::endl << "Other Zombie on Heap" << std::endl;
	Zombie *Rosa = new Zombie("Rosa", "Evangelica");

	std::cout << std::endl << "All zombies has died : " << std::endl;
	std::cout << std::endl << "			Rosa (Heap), ";
	std::cout << std::endl << "			Zombie Events (Heap), ";
	std::cout << std::endl << "			Scarmiglione (stack)" << std::endl << std::endl;
	delete Rosa;
	delete Skagdead;
	return (0);
}
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ZombieHorde.cpp                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 15:26:48 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 10:13:08 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) : n(N)
{
	const char *names[] = {"Gracia", "Poppuri", "Sadie", "Fae", "Misteltainn", "Noctura", "Lyra", "Rhyme"};
	int i = 0;
	int c;
	this->obj = new Zombie[N];
	srand(time(NULL));
	c = rand() % 8;
	c = rand() % 8;
	c = rand() % 8;
	c = rand() % 8;
	c = rand() % 8;
	c = rand() % 8;
	c = rand() % 8;
	c = rand() % 8;
	while (i < N)
	{
		this->obj[i].type = "Stark";
		this->obj[i].name = names[rand() % 8];
		i++;
	}
	return ;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->obj;
	return ;
}

void ZombieHorde::announce(void)
{
	int i = 0;
	while (i < this->n)
	{
		this->obj[i].announce();
		i++;
	}
}

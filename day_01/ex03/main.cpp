/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 15:26:03 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 10:11:54 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main(void)
{
	ZombieHorde z(10);
	z.announce();
	return (0);
}
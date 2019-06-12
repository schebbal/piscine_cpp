/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Pony.class.cpp                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 15:27:24 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 15:27:27 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Pony.class.hpp"

Pony::Pony(std::string n, std::string c, float s, int a) : name(n), color(c), speed(s), age(a)
{
	std::cout << "Instance created" << std::endl;
	return ;
}

Pony::~Pony(void)
{
	std::cout << "Instance destroyed" << std::endl;
	return ;
}

void Pony::jump(int height)
{
	std::cout << "Pony jumped " << height << " meters heigh" << std::endl;
}
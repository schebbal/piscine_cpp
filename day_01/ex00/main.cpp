/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 15:27:14 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 15:27:17 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Pony.class.hpp"
#include <iomanip>

void ponyOnTheHeap(int del)
{
	Pony *p = new Pony("Pinkie Pie", "pink", 29.30, 2);
	std::cout << std::setw(7) << std::left << "name: " << p->name << std::endl;
	std::cout << std::setw(7) << std::left << "color: " << p->color << std::endl;
	std::cout << std::setw(7) << std::left << "speed: " << p->speed << std::endl;
	std::cout << std::setw(7) << std::left << "age: " << p->age << std::endl;
	p->jump(30);
	if (del == 1)
		delete p;
	std::cout << "getting out of function scope" << std::endl << std::endl;
}

void ponyOnTheStack(void)
{
	Pony p("Rainbow Dash", "blue", 22.65, 3);
	std::cout << std::setw(7) << std::left << "name: " << p.name << std::endl;
	std::cout << std::setw(7) << std::left << "color: " << p.color << std::endl;
	std::cout << std::setw(7) << std::left << "speed: " << p.speed << std::endl;
	std::cout << std::setw(7) << std::left << "age: " << p.age << std::endl;
	p.jump(20);
	std::cout << "getting out of function scope" << std::endl << std::endl;
}

int main(void)
{
	std::cout << "Instance dynamically created and deleted, destructor will be called" << std::endl;
	ponyOnTheHeap(1);
	std::cout << "Instance dynamically created without deleted, destructor will not be called " << std::endl;
	ponyOnTheHeap(0);
	std::cout << "Instance statically created, destructor will be called" << std::endl;
	ponyOnTheStack();
	return (0);
}
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ex01.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 11:21:20 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 11:22:35 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include <iomanip>
#include <iostream>

void memoryLeak()
{
	std::string* panthere = new std::string("String panthere");
	std::cout << *panthere << std::endl;
	delete panthere;
}
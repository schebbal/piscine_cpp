/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/03 11:09:43 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 13:30:30 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Human.hpp"
#include <sstream>

int main()
{
	Human bob;

	std::cout << "Brain’s address in memory, in hexadecimal format : " << bob.identify() << std::endl;
	std::cout << "Human’s address in memory, in hexadecimal format : " << bob.getBrain().identify() << std::endl;

}
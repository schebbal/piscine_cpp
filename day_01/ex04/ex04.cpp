/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ex04.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/03 11:03:17 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 11:03:23 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>

int     main() {

	std::string		brain = "HI THIS IS BRAIN" ;
	std::string      	*ptrBrain = &brain;

	std::string		&refBrain = brain;

	std::cout << "POINTER : " << *ptrBrain << std::endl;
	std::cout << "REFERENCES : " << refBrain << std::endl;

	return 0;
}

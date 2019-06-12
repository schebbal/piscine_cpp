/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Human.cpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/03 11:10:17 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 11:24:40 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human( void )
{
}

Human::~Human( void )
{

}

std::string		 Human::identify( void )
{
	std::stringstream ret;
	ret << &this->_brain;
	return ret.str();
}

Brain		&Human::getBrain( void ) // Renvoie la reference de brain donc cest pareil pas une copie MDR
{
	return this->_brain;
}

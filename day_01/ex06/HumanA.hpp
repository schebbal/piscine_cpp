/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   HumanA.hpp                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/03 13:46:49 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 17:59:18 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <sstream>
#include <string>
#include "Weapon.hpp"

class HumanA
{

	public:

		HumanA(std::string nick, Weapon &weap); 
		~HumanA(void);

		Weapon 		&weapon;
		std::string name;
		
		void	attack( void );

};

#endif
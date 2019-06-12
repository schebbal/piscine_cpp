/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   HumanB.hpp                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/03 11:09:27 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 18:10:10 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <sstream>
#include <string>
#include "Weapon.hpp"

class	HumanB {

	public: 

		HumanB(std::string nick); 
		~HumanB(void);

		Weapon 		*weapon;
		std::string name;
		
		void	attack();
		void	setWeapon(Weapon &weap);
};

#endif
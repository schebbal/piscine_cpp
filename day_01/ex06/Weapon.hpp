/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Weapon.hpp                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/03 13:27:03 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 15:54:26 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {

	public:

		Weapon( std::string str );
		~Weapon( void );
		
		std::string const 	&getType();
		void				setType( std::string str );

		std::string	type;

};

#endif

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Zombie.hpp                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 15:26:32 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 10:07:32 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <istream>

class 	Zombie {

	public:
		
		std::string		name;
		std::string		type;
		
		Zombie( void );
		~Zombie( void );

		void 		announce();
};

#endif
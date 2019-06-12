/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Zombie.hpp                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 15:26:32 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 16:43:02 by schebbal    ###    #+. /#+    ###.fr     */
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

		
		Zombie( std::string name, std::string des );
		~Zombie( void );

		/*	SETTER		*/
		/* 	GETTER		*/
		std::string	getName( void ) const;
		void		setName( std::string name);

		std::string	getType( void ) const;
		void		setType( std::string type);

		void 		announce();
};

#endif
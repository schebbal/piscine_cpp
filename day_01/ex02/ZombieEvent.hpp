/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ZombieEvent.hpp                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 15:26:57 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 16:50:04 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_H
# define ZOMBIE_EVENT_H

#include <istream>
#include "Zombie.hpp"

class 	ZombieEvent {

	public:
		
		std::string		name;
		std::string		type;

		
		ZombieEvent( std::string nick, std::string desc );
		~ZombieEvent( void );

		/*	SETTER		*/
		/* 	GETTER		*/
		std::string		getName( void ) const;
		void			setName( std::string name);

		std::string		getType( void ) const;
		void			setTyoe( std::string type );

		void			setZombieType( std::string type );
		Zombie*         newZombie(std::string name);
        Zombie*         randomChump();
};

#endif
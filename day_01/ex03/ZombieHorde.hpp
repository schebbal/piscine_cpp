/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ZombieHorde.hpp                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 15:26:57 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 10:03:28 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_H
# define ZOMBIE_HORDE_H

#include <istream>
#include "Zombie.hpp"

class 	ZombieHorde {

	public:
		
		Zombie *obj;
		int n;

		ZombieHorde(int N);
		~ZombieHorde(void);

		void announce(void);
};

#endif
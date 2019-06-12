/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Pony.class.hpp                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 15:27:35 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 15:27:37 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PONY_H
# define PONY_H

#include <iostream>

class Pony
{
	public:
		std::string	name;
		std::string color;
		float 		speed;
		int	  		age;

		void jump(int height);
		Pony(std::string n, std::string c, float s, int a);
		~Pony(void);
};

#endif
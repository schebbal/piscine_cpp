/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Human.hpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/03 11:09:27 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 11:23:51 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <iostream>
#include "Brain.hpp"

class Human{
    
	public:
		Human( void );
		~Human( void);
		Brain &getBrain( void );
		std::string	identify( void );

	private:
		Brain	_brain;
};

#endif
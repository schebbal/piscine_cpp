/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   easyfind.hpp                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 09:14:17 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/11 12:12:05 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>
#include <list>

template< typename T >
void    easyfind( T & list, int n)
{
    std::list<int>::const_iterator			it;
	std::list<int>::const_iterator			ite = list.end();

	try
	{
       for (it = list.begin(); it != ite; ++it )
       {
            if (*it == n)
            {
                std::cout << *it << std::endl;
                break;
            }         
       }
       if (*it != n)
            std::cout << "Occurence not found !" << std::endl;
    
	}
	catch (std::exception& e)
	{
		throw std::exception();
	}
}

#endif

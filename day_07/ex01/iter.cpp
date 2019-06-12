/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   iter.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/10 16:02:54 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 16:41:47 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string>
#include <iostream>

template<typename T>
void			iter(T *array, size_t len, void (*func)(T &))
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		(*func)(array[i]);
		i++;
	}
}

template<typename T>
void			print(T &data)
{
	std::cout << data << std::endl;
}

int main( void )
{
	int				array_ints[] = { 8, 18, 22, 444, 99, 8888 };
	std::string		array_strings[] = { "abcd", "efgh", "ijkl"};

	iter<int>(array_ints, 6 , &print<int>);
	iter<std::string>(array_strings, 3, &print<std::string>);

	return (0);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   megaphone.cpp                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/01 08:55:17 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/01 10:18:53 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <stdio.h>

int	main( int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (argc > 1)
	{
		while (j < argc)
		{
			i = 0;
			while (argv[j][i])
			{
				std::cout << (char)toupper(argv[j][i]);
				i++;
			}
			j++;
		}
		std::cout << std::endl;
	} else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}

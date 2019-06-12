/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/10 17:03:01 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/11 10:04:45 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include <string>
#include <iostream>
#include <exception>
#include "Array.tpp"

int				main(void)
{
	Array<int>		array1(20);
	Array<int>		array2;

	std::cout << "First array1(20) size: " << array1.size() << std::endl;
	std::cout << "Empty array2 size:     " << array2.size() << std::endl;

	array1[10] = 42;
	std::cout << "array1[10] : " << array1[10] << std::endl;
	
	array1[11] = 84;
	std::cout << "array1[11] : " << array1[11] << std::endl;

	array2 = array1;
	std::cout << "Copying array1 in array2..." << std::endl;
	array1[10] = 0;
	array1[11] = 0;
	std::cout << "array1[10] : " << array1[10] << std::endl;
	std::cout << "array1[11] : " << array1[11] << std::endl;
	std::cout << "array2[10] : " << array2[10] << std::endl;
	std::cout << "array2[11] : " << array2[11] << std::endl;

	std::cout << "Trying to set array1[21]" << std::endl;
	try {
		array1[21] = 42;
		std::cout << "SUCCESS, but was not expected !" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "ERROR (expected): " << e.what() << std::endl;
	}

	return (0);
}
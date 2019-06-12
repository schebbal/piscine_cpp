/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 11:21:22 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/11 16:15:36 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>
#include "span.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << "******* Class store 5 ints ********" << std::endl;
    Span sp(5);
    try {
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(110);
	}
    catch (Span::StorageLimitException &e)
	{
		std::cout << e.what() << std::endl;
	}

    try {
        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span:  " << sp.longestSpan() << std::endl;
    }
    catch (Span::NotEnoughValuesException &e)
	{
		std::cout << e.what() << std::endl;
	}

    std::cout << std::endl;
    std::cout << "***** Attempting to add a new number if there are already 5 " << std::endl;
    try {
        sp.addNumber(13);
	}
    catch (Span::StorageLimitException &e)
	{
		std::cout << e.what() << std::endl;
	}

    std::cout << std::endl;
    std::cout << "***** Only one int stored *************" << std::endl;
    Span sp3(1);
    try {
        sp3.addNumber(13);
	}
    catch (Span::StorageLimitException &e)
	{
		std::cout << e.what() << std::endl;
	}
    try {
        std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
    }
    catch (Span::NotEnoughValuesException &e)
	{
		std::cout << e.what() << std::endl;
	}
    try {
        std::cout << "longest span:  " << sp3.longestSpan() << std::endl;
    }
    catch (Span::NotEnoughValuesException &e)
	{
		std::cout << e.what() << std::endl;
	}

    
    std::cout << std::endl;
    std::cout << "***** No int stored *************" << std::endl;
    Span sp4(1);
    try {
        //sp4.addNumber(13);
	}
    catch (Span::StorageLimitException &e)
	{
		std::cout << e.what() << std::endl;
	}
    try {
        std::cout << "shortest span: " << sp4.shortestSpan() << std::endl;
    }
    catch (Span::NotEnoughValuesException &e)
	{
		std::cout << e.what() << std::endl;
	}
    try {
        std::cout << "longest span:  " << sp4.longestSpan() << std::endl;
    }
    catch (Span::NotEnoughValuesException &e)
	{
		std::cout << e.what() << std::endl;
	}

    std::cout << std::endl;
    std::cout << "******* Class store 15 000 ints ********" << std::endl;
    Span sp2(15000);
	try {
		for (int i = 0; i < 15000; ++i)
		{
			sp2.addNumber(i * 10);
		}
	}
	catch (std::overflow_error e) {

		std::cout << e.what() << std::endl;
	}

    try {
	    std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
	    std::cout << "longest span:  " << sp2.longestSpan() << std::endl;
    }
    catch (Span::NotEnoughValuesException &e)
	{
		std::cout << e.what() << std::endl;
	}

}
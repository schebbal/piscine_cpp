/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 15:01:41 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 17:28:14 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << ">>>>>>>>>>>>>>> Test increment" << std::endl;
    try
    {
        Bureaucrat    test("Max", 150);
        std::cout << test << std::endl;
        test.incrementGrade();
        std::cout << "Increment to : " << std::endl;
        std::cout << test << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "ERROR : " << e.what() << std::endl;
    }

    std::cout << ">>>>>>>>>>>>>>> Test decrement" << std::endl;
    try
    {
        Bureaucrat    test("Thomas", 1);
        std::cout << test << std::endl;
        test.decrementGrade();
        std::cout << "Decrement to : " << std::endl;
        std::cout << test << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "ERROR : " << e.what() << std::endl;
    }
    
    std::cout << ">>>>>>>>>>>>>>> Test lowest grade" << std::endl;
    try
    {
        Bureaucrat    test("Yves", 150);
        std::cout << test << std::endl;
        test.decrementGrade();
        std::cout << "Decrement to : " << std::endl;
        std::cout << test << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "ERROR : " << e.what() << std::endl;
    }

    std::cout << ">>>>>>>>>>>>>>> Test highest grade" << std::endl;
    try
    {
        Bureaucrat    test("Bernard", 0);
        std::cout << test << std::endl;
        test.decrementGrade();
        std::cout << "Decrement to : " << std::endl;
        std::cout << test << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "ERROR : " << e.what() << std::endl;
    }

    return (0);
}
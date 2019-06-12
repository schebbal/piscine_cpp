/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 15:01:41 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 19:19:26 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
    std::cout << std::endl << "************ Forms ************" << std::endl;


    Bureaucrat Buro1 = Bureaucrat("Thoms", 1);
    std::cout << Buro1;
    Bureaucrat Buro2 = Bureaucrat("Yves", 150);
    std::cout << Buro2;
    Bureaucrat Buro3 = Bureaucrat("Bernard", 34);
    std::cout << Buro3;

    Form Form1;
    std::cout << std::endl << Form1;
    Form Form2;
    Form Form3;
    
    std::cout << std::endl;
    
    try
    {
        Buro1.signForm(Form1);
    }
    catch (Form::GradeTooLowException e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Buro1.signForm(Form1);
    }
    catch (Form::GradeTooLowException e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
 	   Buro2.signForm(Form2);
	}
	catch (Form::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}

    try
    {
 	   Form2.beSigned(Buro2);
	}
	catch (Form::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout << std::endl;
	try
	{
	    Form3.beSigned(Buro3);	}
	catch (Form::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
    return (0);
}
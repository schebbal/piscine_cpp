/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ShrubberyCreationForm.cpp                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/09 15:58:45 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 19:24:32 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form()
{

}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form()
{
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : Form()
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
    
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if (this != &rhs)
		return *this;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string name = this->getTarget() + "_shrubbery";
	const char *fileName = name.c_str();
	if (executor.getGrade() <= 137 && this->getSign() == true)
	{
		std::ofstream ofs(fileName);
		if (ofs)
		{
			ofs << "    O    " << std::endl 
                << "   OOO   " << std::endl 
                << "  OOOOO  " << std::endl 
                << " OOOOOOO " << std::endl 
                << "OOOOOOOOO" << std::endl 
                << "    |    " << std::endl 
                << " XXXXXXX " << std::endl;
		}
		ofs.close();
	}
	else if (this->getSign() == false)
		std::cout << "The form isn't signed yet." << std::endl;
	else
		//throw 
		Form::GradeTooLowException();
}

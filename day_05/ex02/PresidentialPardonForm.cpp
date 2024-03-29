/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   PresidentialPardonForm.cpp                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/09 17:46:41 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 17:47:25 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm( void ) : Form()
{

}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form()
{
	this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : Form()
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{

}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if (this != &rhs)
		return *this;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= 5 && this->getSign() == true)
		std::cout << this->getTarget() << " has been pardonned by Zafod Beeblebrox." << std::endl;
	else if (this->getSign() == false)
		std::cout << "The form isn't signed yet." << std::endl;
	else
		throw Form::GradeTooLowException();
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Form.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 18:11:02 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 19:22:52 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Form.hpp"

Form::Form() : _name("Billing"), _sigGrade(12), _excGrade(6), _signed(false)
{
	return;
}

Form::Form(std::string const name, int sigGrade, int excGrade): _name(name), _sigGrade(sigGrade), _excGrade(excGrade)
{
	if (excGrade < 1 || excGrade < 1)
		throw Form::GradeTooHighException();
	else if (excGrade > 150 || excGrade > 150)
		throw Form::GradeTooLowException();
	return;
}

Form::Form(Form &src) : _sigGrade(src._sigGrade), _excGrade(src._excGrade)
{
	*this = src;
	return;
}

Form::~Form(void)
{
    return ;
}

Form  &Form::operator=(const Form &rhs)
{
    if (this != &rhs)
    {
        this->_signed = rhs._signed;
    }
    return (*this);
}

void	Form::beSigned(Bureaucrat &r)
{
	if (r.getGrade() > this->_sigGrade)
	{
		std::cout << "<Bureaucrat " << r.getName() << "> cannot sign <" << this->_name 
				  << "> because his grade <" << r.getGrade() << "> is lower than requirement grade <"
				  << this->_sigGrade << ">" << std::endl;
		Form::GradeTooLowException::GradeTooLowException();
	}
	else if (this->_signed == 1)
		std::cout << "<Bureaucrat " << r.getName() << " cannot sign " << this->_name << " because the form is already signed." << std::endl;
	else
		std::cout << "<Bureaucrat " << r.getName() << " signs " << this->_name << "." << std::endl;
		this->setSigned();
}

int Form::getExecutionGrade( void ) const
{
	return _excGrade;
}

Form::GradeTooLowException::GradeTooLowException(void)
{
    return ;
}

Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException &src)
{
    *this = src;
    return ;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw()
{
    return ;
}

Form::GradeTooLowException    &Form::GradeTooLowException::operator= (const GradeTooLowException &rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

const char  *Form::GradeTooLowException::what() const throw()
{
    return ("150 is the lowest grade possible !");
}

Form::GradeTooHighException::GradeTooHighException(void)
{
    return ;
}

Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException &src)
{
    *this = src;
    return ;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw()
{
    return ;
}

Form::GradeTooHighException &Form::GradeTooHighException::operator= (const GradeTooHighException &rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

const char  *Form::GradeTooHighException::what() const throw()
{
    return ("1 is the highest grade possible !");
}

std::string			Form::getName(void) const
{
	return (this->_name);
}

bool				Form::getSigned(void) const
{
	return (this->_signed);
}

int					Form::getExcGrade(void) const
{
	return (this->_excGrade);
}

int					Form::getSigGrade(void) const
{
	return	(this->_sigGrade);
}

void	Form::setSigned() {

	this->_signed = 1;
}

std::string Form::getTarget(void) const
{
	return this->_target;
}

void Form::setTarget( std::string target)
{
	_target = target;
}

bool Form::getSign() const
{
	return _signed;
}


void Form::setSign( bool boolean )
{
	_signed = boolean;
}


std::ostream    &operator<< (std::ostream &o, const Form &rhs)
{
    o << rhs.getName() << "Form Details:  " << std::endl
    << "          Form name: " << rhs.getName() << std::endl
    << "          Signing Grade Requirement: " << rhs.getSigGrade() << std::endl
    << "          Execution Grade Requirement: " << rhs.getExcGrade() << std::endl;
    return (o);
}
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Bureaucrat.cpp                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 11:15:27 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 15:06:36 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
    this->_grade = 1;
    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    *this = src;
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else
    {
      this->_grade = grade;
    }
    return ;
}

Bureaucrat::~Bureaucrat(void)
{
    return ;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    if (this != &rhs)
    {
        this->_grade = rhs._grade;
    }
    return (*this);
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
{
    return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException &src)
{
    *this = src;
    return ;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
    return ;
}

Bureaucrat::GradeTooLowException    &Bureaucrat::GradeTooLowException::operator= (const GradeTooLowException &rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

const char  *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("150 is the lowest grade possible !");
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
{
    return ;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException &src)
{
    *this = src;
    return ;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{
    return ;
}

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator= (const GradeTooHighException &rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

const char  *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("1 is the highest grade possible !");
}

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void    Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else
    {
        this->_grade = grade;
    }
    return ;
}

void    Bureaucrat::incrementGrade(void)
{
    if (this->_grade <= 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else
    {
        this->_grade -= 1;
    }
    return ;
}

void    Bureaucrat::decrementGrade(void)
{
    if (this->_grade >= 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else
    {
        this->_grade += 1;
    }
    return ;
}

void	Bureaucrat::signForm(Form & src) {

	if (this->_grade <= src.getSigGrade() && src.getSigned() == 0) {
		std::cout << "<Bureaucrat " << this->_name << "> signs <" << src.getName() << ">" << std::endl;
		src.setSigned();
	}
	else if (this->_grade > src.getSigGrade()) {
		std::cout << "<Bureaucrat " << this->_name << "> cannot sign <" << src.getName() << "> because his grade is too low." << std::endl;
	}
	else if (src.getSigned() == 1) {
		std::cout << "<Bureaucrat " << this->_name << "> cannot sign <" << src.getName() << "> because the form is already signed." << std::endl;
	}
}


std::ostream    &operator<< (std::ostream &o, const Bureaucrat &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return (o);
}
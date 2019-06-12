/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Bureaucrat.hpp                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 11:44:01 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 12:24:33 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"

class Form;
class Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade;

public:
    Bureaucrat(void);
	Bureaucrat(std::string, int grade);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat(void);

	Bureaucrat		& operator=(Bureaucrat const & right);

    class  GradeTooLowException: public  std::exception
    {
    public:
        GradeTooLowException( void );
        GradeTooLowException( const GradeTooLowException & src);
        ~GradeTooLowException( void ) throw();

        GradeTooLowException & operator=(const GradeTooLowException & rhs);

        const  char     *what() const throw();

    };

    class  GradeTooHighException: public  std::exception
    {
    public:
        GradeTooHighException( void );
        GradeTooHighException( const GradeTooHighException & src);
        ~GradeTooHighException( void ) throw();

        GradeTooHighException & operator=(const GradeTooHighException & rhs);

        const  char     *what() const throw();
    };

    std::string     getName(void) const;
    void            setName(std::string src);
    
    int             getGrade(void) const;
    void            setGrade(int const raw);

    void            incrementGrade(void);
    void            decrementGrade(void);
    
    void			signForm(Form &);

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
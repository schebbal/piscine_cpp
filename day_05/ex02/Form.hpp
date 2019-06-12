/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Form.hpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 18:12:08 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 18:56:36 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string       _name;
    const int               _sigGrade;
    const int               _excGrade;
    bool                    _signed;
    std::string             _target;

public:
    Form(void);
	Form(std::string const name, int siggrade, int excgrade);
    Form(Form &obj);
	Form(Form const & src);
	~Form(void);

	Form		    & operator=(Form const & rhs);

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
    
    int             getSigGrade(void) const;
    void            setSigGrade(int const raw);

    int             getExcGrade(void) const;
    void            setExcGrade(int const raw);

    bool            getSigned(void) const;
    void            setSigned(void);
    
    int             getExecutionGrade( void ) const;

    bool            getSign( void ) const;
	void            setSign( bool boolean );
	void            setTarget( std::string target );
	std::string     getTarget(void) const;
    void            beSigned(Bureaucrat &rhs);   
    virtual void    execute( Bureaucrat const & ) const = 0;
      
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif
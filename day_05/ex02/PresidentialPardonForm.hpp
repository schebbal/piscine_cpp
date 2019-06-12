/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   PresidentialPardonForm.hpp                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/09 17:46:24 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 17:46:30 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
    PresidentialPardonForm( void );
    PresidentialPardonForm( std::string target );
    PresidentialPardonForm( PresidentialPardonForm const & src );
    void execute(Bureaucrat const & executor) const;
    ~PresidentialPardonForm();
    
    PresidentialPardonForm & operator=( PresidentialPardonForm const & rhs );
};

#endif

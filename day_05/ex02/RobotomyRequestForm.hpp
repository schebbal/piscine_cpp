/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   RobotomyRequestForm.hpp                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/09 17:40:17 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 17:40:25 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef  ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
    RobotomyRequestForm( void );
    RobotomyRequestForm( std::string target );
    RobotomyRequestForm( RobotomyRequestForm const & src );
    void execute(Bureaucrat const & executor) const;
    ~RobotomyRequestForm();
    
    RobotomyRequestForm & operator=( RobotomyRequestForm const & rhs );
};

#endif

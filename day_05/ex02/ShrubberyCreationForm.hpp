/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ShrubberyCreationForm.hpp                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/09 15:58:41 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 16:03:43 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( ShrubberyCreationForm const & src );
	void execute(Bureaucrat const & executor) const;
	~ShrubberyCreationForm();
	
	ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs );
};

#endif

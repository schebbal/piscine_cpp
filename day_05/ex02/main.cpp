/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 15:01:41 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 20:11:35 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{

   std::cout << "-----Test 1-------" << std::endl;
   try
   {
       Bureaucrat bureaucrat("Babel", 10);
       ShrubberyCreationForm invoice("facture");
       invoice.beSigned(bureaucrat);
       invoice.execute(bureaucrat);
   }
   catch (Bureaucrat::GradeTooLowException &e)
   {
       std::cout << "GradeTooLowException Bureaucrat" << std::endl;
   }
   catch (Bureaucrat::GradeTooHighException &e)
   {
       std::cout << "GradeTooHighException Bureaucrat" << std::endl;
   }
   catch (Form::GradeTooLowException &e)
   {
       std::cout << "GradeTooLowException Form" << std::endl;
   }
   catch (Form::GradeTooHighException &e)
   {
       std::cout << "GradeTooHighException Form" << std::endl;
   }

   std::cout << "------Test 2-------" << std::endl;
   try
   {
       Bureaucrat bureaucrat("Babel", 10);
       RobotomyRequestForm invoice("facture1");
       invoice.beSigned(bureaucrat);
       invoice.execute(bureaucrat);
   }
   catch (Bureaucrat::GradeTooLowException &e)
   {
       std::cout << "GradeTooLowException Bureaucrat" << std::endl;
   }
   catch (Bureaucrat::GradeTooHighException &e)
   {
       std::cout << "GradeTooHighException Bureaucrat" << std::endl;
   }
   catch (Form::GradeTooLowException &e)
   {
       std::cout << "GradeTooLowException Form" << std::endl;
   }
   catch (Form::GradeTooHighException &e)
   {
       std::cout << "GradeTooHighException Form" << std::endl;
   }

   std::cout << "-----Test 3--------" << std::endl;
   try
   {
       Bureaucrat bureaucrat("Babel", 3);
       PresidentialPardonForm invoice("facture1");
       invoice.beSigned(bureaucrat);
       invoice.execute(bureaucrat);
   }
   catch (Bureaucrat::GradeTooLowException &e)
   {
       std::cout << "GradeTooLowException Bureaucrat" << std::endl;
   }
   catch (Bureaucrat::GradeTooHighException &e)
   {
       std::cout << "GradeTooHighException Bureaucrat" << std::endl;
   }
   catch (Form::GradeTooLowException &e)
   {
       std::cout << "GradeTooLowException Form" << std::endl;
   }
   catch (Form::GradeTooHighException &e)
   {
       std::cout << "GradeTooHighException Form" << std::endl;
   }

   std::cout << "-----Test 4--------" << std::endl;
   try
   {
       Bureaucrat bureaucrat("Babel", 6);
       PresidentialPardonForm invoice("facture");
       invoice.beSigned(bureaucrat);
       bureaucrat.incrementGrade();
       std::cout << bureaucrat;
       bureaucrat.executeForm(invoice);
   }
   catch (Bureaucrat::GradeTooLowException &e)
   {
       std::cout << "GradeTooLowException Bureaucrat" << std::endl;
   }
   catch (Bureaucrat::GradeTooHighException &e)
   {
       std::cout << "GradeTooHighException Bureaucrat" << std::endl;
   }
   catch (Form::GradeTooLowException &e)
   {
       std::cout << "GradeTooLowException Form" << std::endl;
   }
   catch (Form::GradeTooHighException &e)
   {
       std::cout << "GradeTooHighException Form" << std::endl;
   }
    
   return 0;
}
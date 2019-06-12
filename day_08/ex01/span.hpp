/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   span.hpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 11:23:08 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/11 15:02:34 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#define SPAN_HPP
#ifndef SPAN_HHPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <exception>
#include <vector>

class Span
{
	public:

		Span(void);
		Span(unsigned int n);
		Span(Span &obj);

		virtual ~Span(void);
        
		Span &operator=(Span const &r);
	
		class StorageLimitException : public std::exception
		{
			public:
				
				StorageLimitException(void);
				StorageLimitException(StorageLimitException const &obj);
				virtual ~StorageLimitException(void) throw();
				StorageLimitException &operator=(StorageLimitException const &r);
				virtual const char* what() const throw();
		};
	
		class NotEnoughValuesException : public std::exception
		{
			public:
				
				NotEnoughValuesException(void);
				NotEnoughValuesException(NotEnoughValuesException const &obj);
				virtual ~NotEnoughValuesException(void) throw();
				NotEnoughValuesException &operator=(NotEnoughValuesException const &r);
				virtual const char* what() const throw();
		};
	
		void			addNumber(int num);
		int				shortestSpan(void);
		int				longestSpan(void);	
     
	private:
		
		std::vector<int>	_store;
		unsigned int		_size;

}; 

#endif

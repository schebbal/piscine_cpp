/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mutantstack.hpp                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:27:51 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 14:36:44 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stack>

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


template <typename T>
class MutantStack : public std::stack<T>
{
	private:
		typedef    std::stack<T> base;

	public:
		MutantStack(void) {}
		~MutantStack(void) {}
		MutantStack(MutantStack const & o): base(o) {}
		typedef typename base::container_type::iterator iterator;
		using		base::operator=;

		iterator	begin() { return base::c.begin(); }
		iterator	end() { return base::c.end() ; }
};


#endif

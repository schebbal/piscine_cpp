/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Fixed.class.hpp                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/03 17:03:08 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 08:53:50 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed & operator=(Fixed const &rhs);

		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int _fx;
		static const int _bits;
};

#endif

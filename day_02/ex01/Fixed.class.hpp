/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Fixed.class.hpp                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 09:14:23 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 09:14:39 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(int const n);
		Fixed(float const z);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed & operator=(Fixed const &rhs);

		int     getRawBits(void) const;
		void    setRawBits(int const raw);
		float	toFloat( void ) const;
		int	    toInt( void ) const;

	private:
		int _fx;
		static const int _bits;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
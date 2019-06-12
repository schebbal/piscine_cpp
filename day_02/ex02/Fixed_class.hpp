/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Fixed_class.hpp                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 09:26:15 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 10:15:43 by schebbal    ###    #+. /#+    ###.fr     */
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
    Fixed(const Fixed &other);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed(void);
    Fixed               &operator=(const Fixed &rhs);
    Fixed               &operator++(void);
    Fixed               &operator--(void);
    Fixed               operator++(int);
    Fixed               operator--(int);
    bool                operator>(const Fixed &rhs) const;
    bool                operator<(const Fixed &rhs) const;
    bool                operator>=(const Fixed &rhs) const;
    bool                operator<=(const Fixed &rhs) const;
    bool                operator==(const Fixed &rhs) const;
    bool                operator!=(const Fixed &rhs) const;
    Fixed               operator+(const Fixed &rhs) const;
    Fixed               operator-(const Fixed &rhs) const;
    Fixed               operator*(const Fixed &rhs) const;
    Fixed               operator/(const Fixed &rhs) const;
    int                 getRawBits(void) const;
    void                setRawBits(int const);
    int                 toInt(void) const;
    float               toFloat(void) const;
    static Fixed        &min(Fixed &a, Fixed &b);
    const static Fixed  &min(const Fixed &a, const Fixed &b);
    static Fixed        &max(Fixed &a, Fixed &b);
    const static Fixed  &max(const Fixed &a, const Fixed &b);

	private:
		int _fx;
		static const int _bits;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
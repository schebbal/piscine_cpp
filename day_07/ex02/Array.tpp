/* **************************************************************************** #
*                                                           LE - /             *
*                                                               /              *
*    Array.tpp                                        .::    .:/ .      .::    *
*                                                  +:+:+   +:    +:  +:+:+     *
*    By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+      *
*                                                  #+#   #+    #+    #+#       *
*    Created: 2019/04/10 16:48:46 by schebbal     #+#   ##    ##    #+#        *
*    Updated: 2019/04/10 17:07:17 by schebbal    ###    #+. /#+    ###.fr      *
*                                                          /                   *
*                                                         /                    *
* **************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <exception>

template<typename T>
class Array
{
	private:
		unsigned int			_size;
		T						*_myArray;

	public:
		class					OutOfRangeException: public std::exception
		{
			public:
				OutOfRangeException(void) {}
				~OutOfRangeException(void) throw() {}
				char const		*what(void) const throw() 
				{ 
					return ("Out of range");
				}
		};

		Array<T>(void)
		{
			_size = 0;
			_myArray = NULL;

		}

		Array<T>(unsigned int n)
		{
			_size = n;
			_myArray = new T[n];
		}

		~Array<T>(void)
		{
			delete (_myArray);
		}

		Array<T>(Array<T> const &src)
		{
			*this = src;
		}

		Array<T>				&operator=(Array<T> const &rhs)
		{
			delete (_myArray);
			_size = rhs._size;
			_myArray = new T[_size];

			for (unsigned int i = 0; i < _size; i++)
				_myArray[i] = rhs._myArray[i];
			return (*this);
		}
		
		T						&operator[](unsigned int i) throw(OutOfRangeException)
		{
			if (!_myArray || i >= _size)
				throw (OutOfRangeException());
			return (_myArray[i]);
		}

		unsigned int			size(void) const
		{
			return (_size);
		}
};

#endif

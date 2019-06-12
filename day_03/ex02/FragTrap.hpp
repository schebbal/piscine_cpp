/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   FragTrap.hpp                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 09:34:28 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 23:02:03 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"
# include <string>

class FragTrap: public ClapTrap
{
	private:
		static unsigned int (FragTrap::*_attacks[])(std::string const &target);

	public:

		FragTrap(std::string name);
		~FragTrap(void);
		FragTrap(FragTrap const &src);

		FragTrap		&operator=(FragTrap const &rhs);

		void			rangedAttack(std::string const & target) const;
		void			meleeAttack(std::string const & target) const;

		void			sunblaster(std::string const & target);
		void			wildPulsar(std::string const & target);
		void			bubblegun(std::string const & target);
		void			flowerBouquet(std::string const & target);
		void			theDrumstick(std::string const & target);
		void			vaulthunter_dot_exe(std::string const & target);
};

#endif
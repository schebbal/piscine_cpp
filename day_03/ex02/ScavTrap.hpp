/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ScavTrap.hpp                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 14:43:46 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 23:02:29 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"
# include <string>

class ScavTrap: public ClapTrap
{
    private:
		static std::string			_challenges[];
        
    public:
        
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap(ScavTrap const &src);

		ScavTrap		&operator=(ScavTrap const &rhs);

		void			rangedAttack(std::string const & target) const;
		void			meleeAttack(std::string const & target) const;

		void			foodfight(std::string const & target);
		void			hugFloran(std::string const & target);
		void			playMusic(std::string const & target);
		void			danceWithApex(std::string const & target);
		void			playStarbound(std::string const & target);
		void			challengeNewcomer(std::string const & target);
};

#endif
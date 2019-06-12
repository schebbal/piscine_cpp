/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   FragTrap.hpp                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 09:34:28 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 12:05:42 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <string>

class FragTrap
{
	private:
		static int					_attack_number;
		unsigned int				_hitPoints;
		unsigned int				_energyPoints;
		unsigned int				_level;

		static unsigned int const	_maxHitPoints;
		static unsigned int const	_maxEnergyPoints;
		static unsigned int const	_armorDamageReduction;
		
		std::string					_name;

		static unsigned int (FragTrap::*_attacks[])(std::string const &target);

	public:
		static unsigned int const	meleeAttackDamage;
		static unsigned int const	rangedAttackDamage;

		FragTrap(std::string name);
		~FragTrap(void);
		FragTrap(FragTrap const &src);

		FragTrap		&operator=(FragTrap const &rhs);

		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		unsigned int	vaulthunter_dot_exe(std::string const &target);

		unsigned int	clapInTheBox(std::string const &target);
		unsigned int	laserInferno(std::string const &target);
		unsigned int	torgueFiesta(std::string const &target);
		unsigned int	pirateShipMode(std::string const &target);
		unsigned int	oneShotWonder(std::string const &target);

		std::string		&getName(void);
};

#endif
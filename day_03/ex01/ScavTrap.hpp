/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ScavTrap.hpp                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 14:43:46 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 21:33:47 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <string>

class ScavTrap
{
    private:
		static int					_challenge_number;
		unsigned int				_hitPoints;
		unsigned int				_energyPoints;
		unsigned int				_level;

		static unsigned int const	_maxHitPoints;
		static unsigned int const	_maxEnergyPoints;
		static unsigned int const	_armorDamageReduction;
		
		std::string					_name;

		static std::string			_challenges[];
        
    public:
        static unsigned int const	meleeAttackDamage;
		static unsigned int const	rangedAttackDamage;
        
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap(ScavTrap const &src);

		ScavTrap		&operator=(ScavTrap const &rhs);

		void	rangedAttack(std::string const &target);
		void	meleeAttack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	challengeNewcomer(void);

		void	StonehengeDefensive(std::string const &target);
		void	ChargeAssault(std::string const &target);
		void	PipelineDestruction(std::string const &target);
		void	FacelessSoldier(std::string const &target);
		void 	BunkerBuster(std::string const &target);

		std::string		&getName(void);
};

#endif
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ClapTrap.hpp                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 09:34:28 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 22:49:16 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>

class ClapTrap
{
protected:
	unsigned int	_hitPoints;
	unsigned int	_maxHitPoints;
	unsigned int	_energyPoints;
	unsigned int	_maxEnergyPoints;
	unsigned int	_level;
	std::string		_name;
	unsigned int	_meleeAttackDamage;
	unsigned int	_energyAttackDamage;
	unsigned int	_rangedAttackDamage;
	unsigned int	_armorDamageReduction;

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & src);
	~ClapTrap(void);

	ClapTrap		& operator=(ClapTrap const & right);

	unsigned int	getHitPoints(void) const;
	unsigned int	getMaxHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getMaxEnergyPoints(void) const;
	unsigned int	getLevel(void) const;
	std::string		getName(void) const;
	unsigned int	getMeleeAttackDamage(void) const;
	unsigned int	getEnergyAttackDamage(void) const;
	unsigned int	getRangedAttackDamage(void) const;
	unsigned int	getArmorDamageReduction(void) const;

	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

};

#endif
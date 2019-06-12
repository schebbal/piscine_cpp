/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   FragTrap.cpp                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 09:35:27 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 16:25:44 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include "FragTrap.hpp"

unsigned int const	FragTrap::_maxHitPoints = 100;
unsigned int const	FragTrap::_maxEnergyPoints = 100;
unsigned int const	FragTrap::_armorDamageReduction = 5;

unsigned int const	FragTrap::meleeAttackDamage = 30;
unsigned int const	FragTrap::rangedAttackDamage = 20;

int					FragTrap::_attack_number = 5;
unsigned int (FragTrap::*FragTrap::_attacks[])(std::string const &target) = {
	&FragTrap::clapInTheBox,
	&FragTrap::laserInferno,
	&FragTrap::torgueFiesta,
	&FragTrap::pirateShipMode,
	&FragTrap::oneShotWonder
};

FragTrap::FragTrap(std::string name): _name(name)
{
	srand(time(NULL));
	this->_hitPoints = _maxHitPoints;
	this->_energyPoints = _maxEnergyPoints;
	this->_level = 1;
	std::cout << "FR4G-TP <" << _name;
	if (name.compare("Brick") == 0)
		std::cout << ">, your robot Number One";
	if (name.compare("Kule") == 0)
		std::cout << ">, your robot Number Tow";
	std::cout << std:: endl;
}

FragTrap::FragTrap(FragTrap const &src)
{
	*this = src;
	std::cout << "FR4G-TP <" << _name << ">, your robot"
		<< std:: endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FR4G-TP <" << this->_name << ">. I'm dead" << std::endl;
}

FragTrap		&FragTrap::operator=(FragTrap const	&rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_level = rhs._level;
	}
	return (*this);
}

void			FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP <" << this->_name
		<< "> attacks <" << target
		<< "> at range, causing <" 
		<< this->rangedAttackDamage << "> points of damage !" << std::endl;
}

void			FragTrap::meleeAttack(std::string const	&target)
{
	std::cout << "FR4G-TP <" << this->_name
		<< "> attacks <" << target
		<< "> at range, causing <" << this->meleeAttackDamage
		<< "> points of damage !" << std::endl;
}

void			FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
		std::cout << "FR4G-TP <" << this->_name << ">. " << "I'm dead !!!!!!!" << std::endl;
	amount -= _armorDamageReduction;
	if (amount > this->_hitPoints)
		amount = this->_hitPoints;
	this->_hitPoints -= amount;
	std::cout << "FR4G-TP <" << _name
		<< "> took " << amount
		<< " damages and now has " << this->_hitPoints
		<< " hitPoints." << std::endl;
}

void			FragTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints >= amount)
	{
		if (this->_hitPoints + amount > 100)
			amount = 100 - this->_hitPoints;
		this->_energyPoints -= amount;
		this->_hitPoints += amount;
		std::cout << "FR4G-TP <" << this->_name << "> "
			<< amount
			<< " hitPoints repaired. Now has " << this->_hitPoints
			<< " hitPoints and " <<	this->_energyPoints
			<< " energy points" << std::endl;
	}
	else
		std::cout << "FR4G-TP Out of energy" << std::endl;
}

unsigned int	FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	int			random;

	if (this->_energyPoints >= 25)
	{
		this->_energyPoints -= 25;
		random = rand() % _attack_number;
		return ((this->*_attacks[random])(target));
	}
	else
		std::cout << "FR4G-TP <" << this->_name << ">. " << "Out of fuel" << std::endl;
	return (0);
}

unsigned int	FragTrap::clapInTheBox(std::string const &target)
{
	std::cout << "FR4G-TP <" << this->_name
		<< "> use the attack ClapInTheBox, he hold a bomb <" << target
		<< ">" << std::endl;
	return (30);
}

unsigned int	FragTrap::laserInferno(std::string const &target)
{
	std::cout << "FR4G-TP <" << this->_name
		<< "> use the attack LaserInferno, he shoots laser <"
		<< target << ">" << std::endl;
	return (50);
}

unsigned int	FragTrap::torgueFiesta(std::string const &target)
{
	std::cout << "FR4G-TP <" << this->_name
		<< "> use the attack torgueFiesta <"
		<< target << ">" << std::endl;
	return (50);
}

unsigned int	FragTrap::pirateShipMode(std::string const &target)
{
	std::cout << "FR4G-TP <" << this->_name
		<< "> use the attack pirateShipMode <"
		<< target << ">"
		<< std::endl;
	return(15);
}

unsigned int	FragTrap::oneShotWonder(std::string const &target)
{
	std::cout << "FR4G-TP <" << this->_name
		<< "> use the attack oneShotWonder <"
		<< target << ">"
		<< std::endl;
	return(70);
}

std::string		&FragTrap::getName(void)
{
	return (this->_name);
}
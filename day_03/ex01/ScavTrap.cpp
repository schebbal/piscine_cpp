/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ScavTrap.cpp                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 14:43:37 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 21:33:49 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include "ScavTrap.hpp"

unsigned int const	ScavTrap::_maxHitPoints = 100;
unsigned int const	ScavTrap::_maxEnergyPoints = 50;
unsigned int const	ScavTrap::_armorDamageReduction = 3;

unsigned int const	ScavTrap::meleeAttackDamage = 20;
unsigned int const	ScavTrap::rangedAttackDamage = 15;

int					ScavTrap::_challenge_number = 5;

std::string			ScavTrap::_challenges[] = {
	"Protect Stonehenge who should not be touched. WALRUS will then appear in the northeast with the wave of helicopters.",
	//"Stonehenge Defensive",
	"Destroy the third wave of enemies using air-to-air (AAM) missiles, the Ace will then appear in the northwest along with the fourth wave.",
	//"Charge Assault",
	"Destroy all the oil structures before the end of the clock to bring GAZELLE to the north with the drones.",
	//"Pipeline Destruction",
	"Eliminate the majority of unmarked enemies as well as all radar installations. SPIDER will be visible to the east of the map.",
	//"Faceless Soldier",
	"Destroy the missile silos quickly, COMET will fly west after the mission objective update."
	//"Bunker Buster"
};

ScavTrap::ScavTrap(std::string name): _name(name)
{
	srand(time(NULL));
	this->_hitPoints = _maxHitPoints;
	this->_energyPoints = _maxEnergyPoints;
	this->_level = 1;
	std::cout << "FR4G-TP <" << _name;
	if (name.compare("Brick") == 0)
		std::cout << ">, your robot Number One !";
	if (name.compare("Kule") == 0)
		std::cout << ">, your robot Number Tow !";
	if (name.compare("Apex") == 0)
		std::cout << ">, your robot Number Tree for more challenges !";
	std::cout << std:: endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	*this = src;
	std::cout << "FR4G-TP <" << _name << ">, your robot for more challenges !"
		<< std:: endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "FR4G-TP <" << this->_name << ">. I'm dead" << std::endl;
}

ScavTrap		&ScavTrap::operator=(ScavTrap const	&rhs)
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

void	ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP <" << this->_name
		<< "> attacks <" << target
		<< "> at range, causing <" 
		<< this->rangedAttackDamage << "> points of damage !" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const	&target)
{
	std::cout << "FR4G-TP <" << this->_name
		<< "> attacks <" << target
		<< "> at range, causing <" << this->meleeAttackDamage
		<< "> points of damage !" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
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

void	ScavTrap::beRepaired(unsigned int amount)
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

void	ScavTrap::challengeNewcomer(void)
{
	int			random;

	random = rand() % _challenge_number;
	std::cout  << "FR4G-TP <" << this->_name << ">, your mission : " << _challenges[random]  << std::endl;
}

std::string		&ScavTrap::getName(void)
{
	return (this->_name);
}
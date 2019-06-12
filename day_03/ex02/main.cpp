/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 09:35:57 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 23:01:28 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <time.h>

int main( void )
{
	srand(time(0));

	FragTrap brick("Brick");
	FragTrap kule("Kule");
	FragTrap human("Human");

	brick.meleeAttack(kule.getName());
	kule.takeDamage(brick.getMeleeAttackDamage());

	kule.rangedAttack(human.getName());
	human.takeDamage(kule.getRangedAttackDamage());

	kule.vaulthunter_dot_exe(brick.getName());
	brick.takeDamage(kule.getEnergyAttackDamage());

	human.vaulthunter_dot_exe(kule.getName());
	kule.takeDamage(human.getEnergyAttackDamage());

	kule.vaulthunter_dot_exe(human.getName());
	human.takeDamage(kule.getEnergyAttackDamage());

	brick.vaulthunter_dot_exe(kule.getName());
	kule.takeDamage(brick.getEnergyAttackDamage());

	brick.beRepaired(12);

	std::cout << brick.getName() << " has " << brick.getHitPoints() << " health left." << std::endl;
	std::cout << kule.getName() << " has " << kule.getHitPoints() << " health left." << std::endl;
	std::cout << human.getName() << " has " << human.getHitPoints() << " health left." << std::endl;

	ScavTrap apex("Apex");
	ScavTrap novakid("Novakid");

	apex.challengeNewcomer(kule.getName());
	novakid.challengeNewcomer(human.getName());
	apex.challengeNewcomer(brick.getName());
	novakid.challengeNewcomer(apex.getName());

	apex.rangedAttack(brick.getName());
	brick.takeDamage(apex.getRangedAttackDamage());

	human.vaulthunter_dot_exe(novakid.getName());
	novakid.takeDamage(human.getEnergyAttackDamage());

	novakid.meleeAttack(apex.getName());
	apex.takeDamage(novakid.getMeleeAttackDamage());

	std::cout << brick.getName() << " has " << brick.getHitPoints() << " health left." << std::endl;
	std::cout << kule.getName() << " has " << kule.getHitPoints() << " health left." << std::endl;
	std::cout << human.getName() << " has " << human.getHitPoints() << " health left." << std::endl;
	std::cout << apex.getName() << " has " << apex.getHitPoints() << " health left." << std::endl;
	std::cout << novakid.getName() << " has " << novakid.getHitPoints() << " health left." << std::endl;

}
/*

	//brick.challengeNewcomer();
	//apex.challengeNewcomer();
	kule.takeDamage(200);
}
*/
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 09:35:57 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 15:49:25 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "FragTrap.hpp"

int				main(void)
{
	FragTrap	brick("Brick");
	FragTrap	kule("Kule");

	brick.rangedAttack("Kule");
	kule.takeDamage(brick.rangedAttackDamage);

	kule.meleeAttack("Brick");
	brick.takeDamage(kule.meleeAttackDamage);

	brick.meleeAttack("Kule");
	kule.takeDamage(brick.meleeAttackDamage);

	kule.rangedAttack("Brick");
	brick.takeDamage(kule.rangedAttackDamage);

	kule.beRepaired(50);

	kule.rangedAttack("Brick");
	brick.takeDamage(kule.rangedAttackDamage);

	brick.takeDamage(kule.vaulthunter_dot_exe("Brick"));
	brick.takeDamage(kule.vaulthunter_dot_exe("Brick"));
	brick.takeDamage(kule.vaulthunter_dot_exe("Brick"));
	brick.takeDamage(kule.vaulthunter_dot_exe("Brick"));

	kule.takeDamage(200);
}
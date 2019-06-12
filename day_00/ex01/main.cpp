/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/01 11:27:25 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/01 15:45:18 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Phonebook.class.hpp"

bool forever = true;

std::string	getMaxSize(std::string str)
{
	if (str.size() > 10)
	{
		str = str.substr(0, 9);
		str.append(".");
	}
	return (str);
}

Phonebook	prompt(Phonebook list)
{
	std::string buff;

	std::cout << "Login ?" << std::endl;
	std::cin >> buff;
	list.setLogin(buff);
	std::cout << "Nom ?" << std::endl;
	std::cin >> buff;
	list.setNom(buff);
	std::cout << "Prenom ?" << std::endl;
	std::cin >> buff;
	list.setPrenom(buff);
	std::cout << "Nickname ?" << std::endl;
	std::cin >> buff;
	list.setNickname(buff);
	std::cout << "Code Postal ?" << std::endl;
	std::cin >> buff;
	list.setCodepostal(buff);
	std::cout << "Mail ?" << std::endl;
	std::cin >> buff;
	list.setMail(buff);
	std::cout << "Telephone ?" << std::endl;
	std::cin >> buff;
	list.setTelephone(buff);
	std::cout << "Date de naissance ?" << std::endl;
	std::cin >> buff;
	list.setDaten(buff);
	std::cout << "Plat favorit ?" << std::endl;
	std::cin >> buff;
	list.setMeal(buff);
	std::cout << "Couleur favorite ?" << std::endl;
	std::cin >> buff;
	list.setCouleur(buff);
	std::cout << "Secret le plus noir ?" << std::endl;
	std::cin >> buff;
	list.setSecret(buff);
	return (list);
}

void		ft_search(Phonebook *list)
{
	int		j;
	int		i;
	std::string	buff;

	i = 0;
	j = -1;
	std::cout << std::setw(10) << std::right << "Index";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "First name";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "Last name";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "Nickname" ;
	std::cout << "|" << std::endl;
	while (i != 8 && !list[i].getLogin().empty())
	{
		std::cout << std::setw(10) << std::right << i;
		std::cout << "|";
		std::cout << std::setw(10) << std::right << getMaxSize(list[i].getPrenom());
		std::cout << "|";
		std::cout << std::setw(10) << std::right << getMaxSize(list[i].getNom());
		std::cout << "|";
		std::cout << std::setw(10) << std::right << getMaxSize(list[i].getNickname());
		std::cout << "|" << std::endl;
		i++;
	}
	std::cout << "Votre index ?" << std::endl;
	std::cin >> buff;
	if (buff.compare("0") == 0)
		j = 0;
	if (buff.compare("1") == 0)
		j = 1;
	if (buff.compare("2") == 0)
		j = 2;
	if (buff.compare("3") == 0)
		j = 3;
	if (buff.compare("4") == 0)
		j = 4;
	if (buff.compare("5") == 0)
		j = 5;
	if (buff.compare("6") == 0)
		j = 6;
	if (buff.compare("7") == 0)
		j = 7;
	if (j == -1 || list[j].getLogin().empty() )
		std::cout << "ERREUR" << std::endl;
	else
	{
		std::cout << std::setw(17) << std::left << "First Name : ";
		std::cout << list[j].getPrenom() << std::endl;
		std::cout << std::setw(17) << std::left << "Last Name : ";
		std::cout << list[j].getNom() << std::endl;
		std::cout << std::setw(17) << std::left << "Nickname : ";
		std::cout << list[j].getNickname() << std::endl;
		std::cout << std::setw(17) << std::left << "Login : ";
		std::cout << list[j].getLogin() << std::endl;
		std::cout << std::setw(17) << std::left << "Postal Adress : ";
		std::cout << list[j].getCodepostal() << std::endl;
		std::cout << std::setw(17) << std::left << "Mail : ";
		std::cout << list[j].getMail() << std::endl;
		std::cout << std::setw(17) << std::left << "Phone : ";
		std::cout << list[j].getTelephone() << std::endl;
		std::cout << std::setw(17) << std::left << "Birthday Date : ";
		std::cout << list[j].getDaten() << std::endl;
		std::cout << std::setw(17) << std::left << "Birthday Date : ";
		std::cout << list[j].getDaten() << std::endl;
		std::cout << std::setw(17) << std::left << "Favorit Meal : ";
		std::cout << list[j].getMail() << std::endl;
		std::cout << std::setw(17) << std::left << "Favorite Color : ";
		std::cout << list[j].getCouleur() << std::endl;
		std::cout << std::setw(17) << std::left << "Darkest Secret : ";
		std::cout << list[j].getSecret() << std::endl;
	}
}

int main (void) 
{

    Phonebook	list[8];
	int			i;
	std::string buff;


	while (forever)
	{
        std::cout << "Please type ADD, SEARCH or EXIT : " << std::endl; 
		std::cin >> std::uppercase >> buff;
		if (buff.compare("ADD") == 0)
		{
			i = 0;
			while (i < 8)
			{
				if (list[i].getLogin().empty())
				{
					list[i] = prompt(list[i]);
					break ;
				}
				i++;
			}
			if (i == 8)
				std::cout << "Too many entry" << std::endl;
		}
		if (buff.compare("SEARCH") == 0)
		{
			ft_search(list);
		}
		if (buff.compare("EXIT") == 0)
		{
			break ;
		}
    }

    return (0);
}     
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Phonebook.class.cpp                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/01 13:29:38 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/01 13:40:58 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.class.hpp" 

Phonebook::Phonebook( void )
{
	return;
}

Phonebook::~Phonebook (void)
{
	return;
}

std::string	Phonebook::getLogin( void ) const
{
	return (this->_login);
}

void		Phonebook::setLogin( std::string buff )
{
	this->_login = buff;
}

std::string	Phonebook::getNom( void ) const
{
	return (this->_nom);
}

void		Phonebook::setNom( std::string buff )
{
	this->_nom = buff;
}

std::string	Phonebook::getNickname( void ) const
{
	return (this->_nickname);
}

void		Phonebook::setNickname( std::string buff )
{
	this->_nickname = buff;
}

std::string	Phonebook::getPrenom( void ) const
{
	return (this->_prenom);
}

void		Phonebook::setPrenom( std::string buff )
{
	this->_prenom = buff;
}

std::string	Phonebook::getCodepostal( void ) const
{
	return (this->_codepostal);
}

void		Phonebook::setCodepostal( std::string buff )
{
	this->_codepostal = buff;
}

std::string	Phonebook::getMail( void ) const
{
	return (this->_mail);
}

void		Phonebook::setMail( std::string buff )
{
	this->_mail = buff;
}

std::string	Phonebook::getTelephone( void ) const
{
	return (this->_telephone);
}

void		Phonebook::setTelephone( std::string buff )
{
	this->_telephone = buff;
}

std::string	Phonebook::getDaten( void ) const
{
	return (this->_daten);
}

void		Phonebook::setDaten( std::string buff )
{
	this->_daten = buff;
}

std::string	Phonebook::getMeal( void ) const
{
	return (this->_meal);
}

void		Phonebook::setMeal( std::string buff )
{
	this->_meal = buff;
}

std::string	Phonebook::getCouleur( void ) const
{
	return (this->_couleur);
}

void		Phonebook::setCouleur( std::string buff )
{
	this->_couleur = buff;
}

std::string	Phonebook::getSecret( void ) const
{
	return (this->_secret);
}

void		Phonebook::setSecret( std::string buff )
{
	this->_secret = buff;
}
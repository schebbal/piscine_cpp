/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Phonebook.class.hpp                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/01 10:44:10 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/01 14:00:45 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include <istream>

class Phonebook {

	private:
		
		std::string		_login;
		std::string		_prenom;
		std::string		_nom;
		std::string		_nickname;
		std::string		_codepostal;
		std::string		_mail;
		std::string		_telephone;
		std::string		_daten;
		std::string		_meal;
		std::string		_couleur;
		std::string		_secret;

	public:
		
		Phonebook( void );
		~Phonebook( void );

		/*	SETTER		*/
		/* 	GETTER		*/
		std::string		getLogin( void ) const;
		void			setLogin( std::string buff);

		std::string		getNom( void ) const;
		void			setNom( std::string buff);

		std::string		getPrenom( void ) const;
		void			setPrenom( std::string buff);

		std::string		getNickname( void ) const;
		void			setNickname( std::string buff);

		std::string		getCodepostal( void ) const;
		void			setCodepostal( std::string buff);

		std::string		getMail( void ) const;
		void			setMail( std::string buff);

		std::string		getTelephone( void ) const;
		void			setTelephone( std::string buff);

		std::string		getDaten( void ) const;
		void			setDaten( std::string buff);

		std::string		getMeal( void ) const;
		void			setMeal( std::string buff);

		std::string		getCouleur( void ) const;
		void			setCouleur( std::string buff);

		std::string		getSecret( void ) const;
		void			setSecret( std::string buff);
};

#endif

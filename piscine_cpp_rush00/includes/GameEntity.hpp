/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   GameEntity.hpp                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 00:57:33 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 00:57:37 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GAMEENTITY_HPP
# define GAMEENTITY_HPP

# include <string>
# include <iostream>
# include <unistd.h>
# include <ncurses.h>

class GameEntity {

    public:

        GameEntity( void );
        GameEntity( int posX, int posY, char token, int _movingRate );
        GameEntity( std::string type, std::string name, int posX, int posY, char token, int _movingRate );
        GameEntity( GameEntity const & g );
        ~GameEntity( void );

        static int      get_nbInst( void );
        std::string     getName( void ) const;
        std::string     getType( void ) const;
        int             getPosX( void ) const;
        int             getPosY( void ) const;
        char            getToken( void ) const;
        int             getMovingRate( void ) const;

        GameEntity &    operator=( GameEntity const & f) ;

    protected:

        std::string     _type;
        std::string     _name;
        int             _posX;
        int             _posY;
        char            _token;
        int             _movingRate;
        static int      _nbInst;
};

#endif
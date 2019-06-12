/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Missile.hpp                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 00:57:33 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 00:57:37 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MISSILE_HPP
# define MISSILE_HPP

# include <string>
# include <iostream>
# include <ncurses.h>
# include "GameEntity.hpp"

class Missile : public GameEntity {

    public:

        Missile( void );
        Missile( int posX, int posY, char token, int movingRate );
        Missile( int posX, int posY, char token, int movingRate, WINDOW* win );
        Missile( std::string type, std::string name, int posX, int posY, char token, int movingRate );
        Missile( Missile const & g );
        ~Missile( void );

        Missile &       operator=(Missile const & f);

        static int      get_nbInst();
        
        void            move( WINDOW* win, int whiles, int dirX, int dirY );

    private:

        static int      _nbInst;
};

std::ostream &          operator<<(std::ostream &os, Missile &m);

#endif
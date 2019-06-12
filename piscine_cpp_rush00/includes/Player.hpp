/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Player.hpp                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 00:57:33 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 00:57:37 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <string>
# include <iostream>
# include <unistd.h>
# include <ncurses.h>
# include "GameEntity.hpp"
# include "Missile.hpp"
# include "Enemy.hpp"

# define SHOOTING_MOVING_RATE 10

class Player : public GameEntity {
    
    public:
    
        Player( void );
        Player( int posX, int posY, char token );
        Player( int posX, int posY, char token, WINDOW* win );
        Player( std::string type, std::string name, int posX, int posY, char token );
        Player( Player const & g );
        ~Player( void );

        Player &        operator=( Player const & f );

        bool            move( int keyCode, WINDOW * win, Enemy * enemies, int nbEnemies);
        void            shoot( int keyCode, WINDOW * win );
        void            deleteMissile( int i );

        Missile *       getMissiles( void );
        int             getNbMissiles( void );

    private:

        Missile *       _missiles;
        int             _nbMissiles;

};

std::ostream &          operator<<( std::ostream &os, Player &g );

#endif
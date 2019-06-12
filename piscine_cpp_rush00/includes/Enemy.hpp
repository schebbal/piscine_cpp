/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Enemy.hpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 00:57:33 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 00:57:37 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

# include <string>
# include <iostream>
# include <unistd.h>
# include <ncurses.h>
# include "GameEntity.hpp"
# include "Missile.hpp"

# define SHOOTING_RATE 3000
# define MISSILE_MOVING_RATE 50
# define MOVING_RATE 200

class                   Enemy : public GameEntity {

    public:

        Enemy( void );
        Enemy( int posX, int posY, char token, int shootingRate, int movingRate );
        Enemy( std::string type, std::string name, int posX, int posY, char token, int shootingRate, int movingRate );
        Enemy( Enemy const & g );
        ~Enemy( void );

        Enemy &         operator=(Enemy const & f);
        bool            checkForDestruction();
        void            deleteMissile(int j);
        void            move(WINDOW* win, int whiles);
        void            shoot(WINDOW* win, int whiles);

        static int      get_nbInst( void );
        int             getNbMissiles( void ) const;
        Missile *       getMissiles( void );

    private:

        static int      _nbInst;

    protected:

        int             _shootingRate;
        Missile         _missiles[10];
        int             _nbMissiles;
};

std::ostream &          operator<<( std::ostream &os, Enemy &e );

#endif
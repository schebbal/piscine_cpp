/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Game.hpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 00:57:33 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 00:57:37 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include <string>
# include <iostream>
# include <unistd.h>
# include <ncurses.h>
# include "Player.hpp"
# include "Enemy.hpp"

# define HEIGHT 60
# define WIDTH 150
# define WXPOS ((COLS - WIDTH) / 2)
# define WYPOS ((LINES - HEIGHT) / 2)

class Game {

    public:

        Game( void );
        Game( Game const & g );
        ~Game( void );

        Game &      operator=(Game const & f);

        int         getTimeStart( void ) const;
        int         getTimePlayed( void ) const;
        int         getTimeLastSpawn( void ) const;
        void        setTimePlayed( void );
        int         getScore( void ) const;
        void        setScore( int n );
        int         getHeight( void ) const;
        int         getWidth( void ) const;
        int         getNbEnemies( void ) const;
        WINDOW *    getWin( void ) const;
        Player *    getPlayer( void ) const;
        Enemy  *    getEnemies( void );
        void        addNormalShip(int posX, int posY);
        void        spawnEnemies( void );
        void        deleteEnemy( int ennIndex );

    private:

        int         _nbEnemies;
        int         _timeStart;
        int         _timePlayed;
        int         _timeLastSpawn;
        int         _score;
        Enemy  *    _enemies;
        Player *    _player;
        WINDOW *    _win;

        void        _deleteEnemy( int ennIndex );
};

std::ostream &      operator<<( std::ostream &os, Game &g );


#endif
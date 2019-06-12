/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   NormalShip.hpp                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 00:57:33 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 00:57:37 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef NORMALSHIP_HPP
#define NORMALSHIP_HPP

# include <string>
# include <iostream>
# include <unistd.h>
# include <ncurses.h>
# include "Enemy.hpp"

class                   NormalShip : public Enemy {

    public:

        NormalShip( void );
        NormalShip( int posX, int posY );
        NormalShip( int posX, int posY, WINDOW * win );
        NormalShip( NormalShip const & g );
        ~NormalShip( void );

        NormalShip &    operator=(NormalShip const & f);

        static int      get_nbInst();

        void            move( WINDOW* win, int whiles );
        void            shoot( WINDOW * win, int whiles );

    private:

        static int _nbInst;
};

#endif
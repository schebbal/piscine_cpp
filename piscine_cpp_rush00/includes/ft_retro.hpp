/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_retro.hpp                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 00:57:33 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/07 18:51:24 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_RETRO_HPP 
#define FT_RETRO_HPP 

# include <string>
# include <iostream>
# include <unistd.h>
# include <ncurses.h>
# include "GameEntity.hpp"
# include "Game.hpp"
# include "Missile.hpp"
# include "Player.hpp"
# include "Enemy.hpp"
# include "NormalShip.hpp"

# define HEIGHT 60
# define WIDTH 150
# define HEIGHT_M 10
# define WIDTH_M 30
# define ENTER 10
# define ESCAPE 27
# define GREY 20

WINDOW *        createNewwin(int height, int width, int starty, int startx);
void            launchGame( void );
void            init_curses( void );
void            background( WINDOW *Game_window );


#endif

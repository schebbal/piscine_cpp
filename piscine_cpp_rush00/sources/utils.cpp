/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.cpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 00:57:33 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/06 20:05:04 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_retro.hpp"

WINDOW *            createNewwin( int height, int width, int starty, int startx )
{
    WINDOW *        local_win = newwin(height, width, starty, startx);
    wrefresh(local_win);
    return local_win;
}

void                destroyWin( WINDOW *local_win ) {
    wrefresh(local_win);
    delwin(local_win);
}

void                init_curses()
{
    initscr();
    curs_set(0);
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    start_color();
    init_color(GREY, 255, 255, 255);
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_BLUE, COLOR_WHITE);
    init_pair(3, COLOR_RED, COLOR_WHITE);
    init_pair(4, GREY, COLOR_BLACK);
}

void background(WINDOW *Game_window)
{
   static int slower = 0 + 1;

   static int ySquare = rand() % 44 + 1;
   static int xSquare = 30;

   static int yTree = rand() % 44 + 1;
   static int xTree = 70;

   static int yTreeOne = rand() % 44 + 1;
   static int xTreeOne = 120;

   mvwprintw(Game_window, ySquare, xSquare, "/---\\ ");
   mvwprintw(Game_window, ySquare + 1, xSquare, "|   | ");
   mvwprintw(Game_window, ySquare + 2, xSquare, "|   | ");
   mvwprintw(Game_window, ySquare + 3, xSquare, "\\---/ ");

   mvwprintw(Game_window, yTree, xTree, "&&&&& ");
   mvwprintw(Game_window, yTree + 1, xTree, "  {}  ");
   mvwprintw(Game_window, yTree + 2, xTree, "  ||  ");

   mvwprintw(Game_window, yTreeOne, xTreeOne, "&&&&& ");
   mvwprintw(Game_window, yTreeOne + 1, xTreeOne, "  {}  ");
   mvwprintw(Game_window, yTreeOne + 2, xTreeOne, "  ||  ");

   if (slower % 132 == 0)
   {
       xSquare--;
       xTree--;
       xTreeOne--;
   }
   if (xSquare < 1)
   {
       mvwprintw(Game_window, ySquare, xSquare, "      ");
       mvwprintw(Game_window, ySquare + 1, xSquare, "      ");
       mvwprintw(Game_window, ySquare + 2, xSquare, "      ");
       mvwprintw(Game_window, ySquare + 3, xSquare, "      ");
       ySquare = rand() % 55 + 1;
       xSquare = WIDTH - 15;
   }
   if (xTree < 2)
   {
       mvwprintw(Game_window, yTree, xTree, "      ");
       mvwprintw(Game_window, yTree + 1, xTree, "      ");
       mvwprintw(Game_window, yTree + 2, xTree, "      ");
       yTree = rand() % 55 + 1;
       xTree = WIDTH - 12;
   }
   if (xTreeOne < 2)
   {
       mvwprintw(Game_window, yTreeOne, xTreeOne, "      ");
       mvwprintw(Game_window, yTreeOne + 1, xTreeOne, "      ");
       mvwprintw(Game_window, yTreeOne + 2, xTreeOne, "      ");
       yTreeOne = rand() % 55 + 1;
       xTreeOne = WIDTH - 12;
   }
   if (slower > 100000)
       slower = 0;
   slower++;
}
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm.cpp                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 00:57:33 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/07 19:50:26 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_retro.hpp"

void                print_menu(WINDOW *menu_win, int highlight, int n_choices)
{   
    std::string choices[] = {
                        "GAME START",
                        "Exit",
    };
    int x, y, i;
    x = 2;
    y = 2;
    box(menu_win, 0, 0);
    for (i = 0; i < n_choices; ++i)
    {   if (highlight == i + 1)
        {
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, y, x, "%s", choices[i].c_str());
            wattroff(menu_win, A_REVERSE);
        }
        else
            mvwprintw(menu_win, y, x, "%s", choices[i].c_str());
        ++y;
    }
    wrefresh(menu_win);
}

void                launcher(void)
{
    std::string     choices[] = {
                        "GAME START",
                        "Exit",
    };
    int startx = 0;
    int starty = 0;
    int n_choices = 2;
    WINDOW *menu_win;
    init_curses();
    bkgd(COLOR_PAIR(2));
    int highlight = 1;
    int choice = 0;
    int c;
    char msg[]="Use arrow keys to go up and down, Press enter to select a choice";
    startx = (COLS - WIDTH_M) / 2;
    starty = (LINES - HEIGHT_M) / 2;
    
	mvprintw(10, COLS / 2 - 32, "  .d888 888                             888                    ");
	mvprintw(11, COLS / 2 - 32, " d88P'  888                             888                    ");
	mvprintw(12, COLS / 2 - 32, " 888    888                             888                    ");
	mvprintw(13, COLS / 2 - 32, " 888888 888888          888d888 .d88b.  888888 888d888 .d88b.  ");
	mvprintw(14, COLS / 2 - 32, " 888    888             888P'  d8P  Y8b 888    888P'  d88..88b ");
	mvprintw(15, COLS / 2 - 32, " 888    888             888    88888888 888    888    888  888 ");
	mvprintw(16, COLS / 2 - 32, " 888    Y88b.           888    Y8b.     Y88b.  888    Y88..88P ");
	mvprintw(17, COLS / 2 - 32, " 888     'Y888 88888888 888     'Y8888   'Y888 888     'Y88P'  ");

	menu_win = createNewwin(HEIGHT_M, WIDTH_M, starty, startx);
    keypad(menu_win, TRUE);
    start_color();
    init_pair(1, COLOR_RED,COLOR_BLACK);
    mvprintw(0, COLS / 2 - strlen(msg) / 2, msg);
    mvchgat(0, 0, -1, A_BLINK, 1, NULL);
    refresh();
    print_menu(menu_win, highlight, n_choices);
    while(1)
    {   c = wgetch(menu_win);
        switch(c)
        {   case KEY_UP:
            if (highlight == 1)
                highlight = n_choices;
            else
                --highlight;
            break;
            case KEY_DOWN:
            if (highlight == n_choices)
                highlight = 1;
            else
                ++highlight;
            break;
            case ENTER:
            choice = highlight;
            break;
            default:
            refresh();
            break;
        }
        print_menu(menu_win, highlight, n_choices);
        if(choice == 1 || choice == 2 )
            break;
    }
    mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, &choices[choice - 1]);
    clrtoeol();
    refresh();
    clear();
    endwin();
    if (choice == 1)
        launchGame();
}


int main()
{
	launcher();
	return 0;
}
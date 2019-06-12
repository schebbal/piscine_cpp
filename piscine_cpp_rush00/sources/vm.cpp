/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm.cpp                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 00:57:33 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/06 18:21:33 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_retro.hpp"

void            launchGame( void ) {
    int             ch;
    unsigned int    whiles = 0;
    bool            flag = true;

    char msg[] = "Press <ESCAPE> key to exit";
    srand(time(0));
    init_curses();
    bkgd(COLOR_PAIR(2));
    start_color();
    init_pair(1, COLOR_RED,COLOR_BLACK);
    mvprintw(0, COLS / 2 - strlen(msg) / 2, msg);
    mvchgat(0, 0, -1, A_BLINK, 1, NULL);
    refresh();
    Game *      game = new Game();
    timeout(1);
    while((ch = getch()) != ESCAPE && flag)
    {
        //  setup backgroud
        wattron(game->getWin(), COLOR_PAIR(4));
        background(game->getWin());
        wattroff(game->getWin(), COLOR_PAIR(4));

        //  frames count
        if (++whiles > 2147483000)
            whiles = 0;
        
        //  player movement & shoot
        Player* player = game->getPlayer();
        player->shoot(ch, game->getWin());

        //  all 10 frames
        if (!(++whiles % 10)) {

            // move ennemies
            Enemy * enemies = game->getEnemies();
            int i = game->getNbEnemies();
            //  forEach ennemy do:
            while (--i >= 0) {
                if (enemies[i].checkForDestruction()) {
                    enemies[i].move(game->getWin(), whiles);
                } else
                    game->deleteEnemy(i);
                enemies = game->getEnemies();
            }
            // move player's missiles and check places with ennemies
            int j = player->getNbMissiles();
            Missile * missiles = player->getMissiles();
            while (--j >= 0) {

                enemies = game->getEnemies();
                missiles[j].move(game->getWin(), whiles, 1, 0);
                i = game->getNbEnemies();
                if (missiles[j].getPosX() > WIDTH - 3) {
                    mvwaddch(game->getWin(), missiles[j].getPosY(), missiles[j].getPosX(), ' ');
                    player->deleteMissile(j);
                } else {
                    while (--i >= 0){
                        int mx = missiles[j].getPosX(), my = missiles[j].getPosY();
                        if ( mx == enemies[i].getPosX() && my == enemies[i].getPosY() ) {
                            game->deleteEnemy(i);
                            player->deleteMissile(j);
                            mvwaddch(game->getWin(), my, mx, ' ');
                            game->setScore(game->getScore() + 5);
                            break;
                        }
                    }
                }
            }
        }

        if (!player->move(ch, game->getWin(), game->getEnemies(), game->getNbEnemies())) {
            delete game;
            break;
        };

        game->setTimePlayed();
        mvprintw(LINES - 2, 1, "Time : %d", game->getTimePlayed());
        mvprintw(LINES - 4, 1, "Score : %d", game->getScore());
        //mvprintw(LINES - 3, 1, "Time Started : %d", game->getTimeStart());
        //mvprintw(LINES - 4, 1, "Time Spawned : %d", game->getTimeLastSpawn());
        wrefresh( game->getWin() );
        if (!(game->getTimePlayed() % 1) && game->getTimePlayed() > game->getTimeLastSpawn()) {
            game->spawnEnemies();
            game->setScore(game->getScore() + 1);
            game->spawnEnemies();
            game->setScore(game->getScore() + 1);
            game->spawnEnemies();
            game->setScore(game->getScore() + 1);
            game->spawnEnemies();
            game->setScore(game->getScore() + 1);
            game->spawnEnemies();
            game->setScore(game->getScore() + 1);
        }
    }
    endwin();
}
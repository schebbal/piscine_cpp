/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Player.cpp                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 00:57:33 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 00:57:37 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Player.hpp"
#include "Game.hpp"
#include <ncurses.h>

// /////////////////////////////////// Members

bool                Player::move( int keyCode, WINDOW * win, Enemy * enemies, int nbEnemies ) {
    switch(keyCode)
    {
        case KEY_LEFT:
            if (this->_posX > 1) {
                mvwaddch(win, this->_posY, this->_posX--, ' ');
                mvwaddch(win, this->_posY, --(this->_posX), this->_token);
            }
            break;
        case KEY_RIGHT:
            if (this->_posX < WIDTH - 3) {
                mvwaddch(win, this->_posY, this->_posX++, ' ');
                mvwaddch(win, this->_posY, ++(this->_posX), this->_token);
            }
            break;
        case KEY_UP:
            if (this->_posY > 1){
                mvwaddch(win, this->_posY--, this->_posX, ' ');
                mvwaddch(win, this->_posY, this->_posX, this->_token);
            }
            break;
        case KEY_DOWN:
            if (this->_posY < HEIGHT - 3){
                mvwaddch(win, this->_posY++, this->_posX, ' ');
                mvwaddch(win, this->_posY, this->_posX, this->_token);
            }
            break;
    }

    while (--nbEnemies >= 0) {
        if (    this->_posY == enemies[nbEnemies].getPosY()
             && this->_posX == enemies[nbEnemies].getPosX() ) {
            return false;
        }
    }
 
    return true;
}

void                Player::shoot( int keyCode, WINDOW * win ) {
    if (keyCode == 32) {
        Missile * nMissiles = new Missile[this->_nbMissiles + 1];
        int i = -1;
        while (++i < this->_nbMissiles)
            nMissiles[i] = this->_missiles[i];
        this->_nbMissiles++;
        nMissiles[this->_nbMissiles - 1] = Missile(this->_posX + 1, this->_posY, '*', SHOOTING_MOVING_RATE, win);
        delete [] this->_missiles;
        this->_missiles = nMissiles;
    }
    return;
}

void                Player::deleteMissile( int i ) {
    this->_missiles[i] = this->_missiles[--(this->_nbMissiles)];
    return;
}

// /////////////////////////////////// Constructors/Destructors

Player::Player( void ) : GameEntity(), _nbMissiles(0) {
    return;
}

Player::Player( int posX, int posY, char token ) : GameEntity( posX, posY, token, 0 ), _nbMissiles(0) {
    return;
}

Player::Player( int posX, int posY, char token, WINDOW* win ) : GameEntity( posX, posY, token, 0 ), _nbMissiles(0) {
    mvwaddch(win, this->_posY, this->_posX, this->_token);
    mvwaddch(win, this->_posY, this->_posX, this->_token);
    this->_missiles = new Missile[10];
    return;
}

Player::Player( std::string type, std::string name, int posX, int posY, char token ) : GameEntity( type, name, posX, posY, token, 0 ), _nbMissiles(0) {
    return;
}

Player::~Player( void ) {
    if (this->_missiles) {
        delete [] this->_missiles;
    }
    return;
}

Player::Player( Player const & g ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = g;
    return;
}

// /////////////////////////////////// Getters/Setters

int                 Player::getNbMissiles( void ) {
    return this->_nbMissiles;
}

Missile *          Player::getMissiles( void ) {
    return this->_missiles;
}

// /////////////////////////////////// Operator overloads

Player &                Player::operator=( Player const & g ) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &g) {
        this->_type = g.getType();
        this->_name = g.getName();
        this->_posX = g.getPosX();
        this->_posY = g.getPosY();
        this->_token = g.getToken();
        this->_movingRate = g.getMovingRate();
    }
    return *this;
}

std::ostream &          operator<<( std::ostream &os, Player &p ) {
    os
    << "/........./" << std::endl
    << "Player : "  << std::endl
    << "_nbMissiles : " << p.getNbMissiles() << std::endl
    << "_missiles : " <<std::endl;
    int i = -1;
    while(++i < p.getNbMissiles()) {
        os << p.getMissiles()[i];
    }
    return os;
}
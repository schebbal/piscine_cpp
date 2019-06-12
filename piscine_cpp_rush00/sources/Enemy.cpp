/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Enemy.cpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 00:57:33 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/07 18:16:05 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "ft_retro.hpp"

int Enemy::_nbInst = 0;

// /////////////////////////////////// Members

void                Enemy::deleteMissile( int j ) {
    this->_missiles[j] = this->_missiles[--this->_nbMissiles];
    return;
}

bool                Enemy::checkForDestruction(  ) {
    if (this->_posX > 0 && this->_posY > 0 && this->_posX < WIDTH && this->_posY < HEIGHT)
        return true;
    else
        return false;
}

void                Enemy::move( WINDOW* win, int whiles ) {
    // change position of this Enemy depending on its movingRate.
    if (this->_posX > 0 && !(whiles % this->_movingRate)) {
        mvwaddch(win, this->_posY, this->_posX--, ' ');
        mvwaddch(win, this->_posY, --this->_posX, this->_token);
    }
    return;
}

void                Enemy::shoot( WINDOW * win, int whiles ) {
    // create a Missile at certain position from this ship, with certain token, at a certain shootingRate. But not yet for this normalShip
    if (!(whiles % this->_shootingRate)) {
        this->_missiles[this->_nbMissiles] = Missile(this->_posX - 1, this->_posY, '-', MISSILE_MOVING_RATE, win);
        this->_nbMissiles++;

    }
    return;
}

// /////////////////////////////////// Constructors/Destructors

Enemy::Enemy() : GameEntity(), _shootingRate(SHOOTING_RATE), _nbMissiles(0) {
    _nbInst++;
    return;
}

Enemy::Enemy(int posX, int posY, char token, int shootingRate, int movingRate) :
    GameEntity(posX, posY, token, movingRate), _shootingRate(shootingRate), _nbMissiles(0) {
    _nbInst++;
    return;
}

Enemy::Enemy(std::string type, std::string name, int posX, int posY, char token, int shootingRate, int movingRate) :
    GameEntity(type, name, posX, posY, token, movingRate),
    _shootingRate(shootingRate), _nbMissiles(0) {
    _nbInst++;
    return;
}

Enemy::Enemy( Enemy const & g ) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = g;
    return;
}

Enemy::~Enemy( void ) {
    _nbInst--;
    return;
} 

// /////////////////////////////////// Getters/Setters

int Enemy::get_nbInst( void ) {
    return Enemy::_nbInst;
}

Missile *          Enemy::getMissiles( void ) {
    return this->_missiles;
}

int                 Enemy::getNbMissiles( void ) const {
    return this->_nbMissiles;
}


// /////////////////////////////////// Operator overloads

Enemy &             Enemy::operator=(Enemy const & g){
    // std::cout << "Assignation operator called" << std::endl;
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

std::ostream &      operator<<(std::ostream &os, Enemy &e) {
    os
    << "/xxxxxxxxxx/" << std::endl
    << "Enemy : "  << std::endl
    << "posX : " << e.getPosX() << std::endl
    << "posY : " << e.getPosY() << std::endl
    << "token : " << e.getToken() << std::endl
    << "_nbMissiles : " << e.getNbMissiles() << std::endl
    << "_missiles : " <<std::endl;
    int i = -1;
    while(++i < e.getNbMissiles()) {
        os << e.getMissiles()[i];
    }
    return os;
}

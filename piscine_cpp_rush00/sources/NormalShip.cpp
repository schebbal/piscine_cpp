/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   NormalShip.cpp                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 00:57:33 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 00:57:37 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "NormalShip.hpp"

int                 NormalShip::_nbInst = 0;

// /////////////////////////////////// Members

void                NormalShip::move( WINDOW* win, int whiles ) {
    // change position of this NormalShip depending on its movingRate.
    (void)win;
    if (this->_posX > 0 && !(whiles % this->_movingRate)) {
        mvwaddch(win, this->_posY, this->_posX--, ' ');
        mvwaddch(win, this->_posY, --this->_posX, this->_token);
    }
    return;
}

void                NormalShip::shoot( WINDOW * win, int whiles ) {
    // create a Missile at certain position from this ship, with certain token, at a certain shootingRate. But not yet for this normalShip
    if (!(whiles % this->_shootingRate)) {
        this->_missiles[this->_nbMissiles] = Missile(this->_posX - 1, this->_posY, '-', MISSILE_MOVING_RATE, win);
        this->_nbMissiles++;
    
    }
    return;
}

// /////////////////////////////////// Constructors/Destructors

NormalShip::NormalShip( void ) : Enemy() {
    _nbInst++;
    return;
}

NormalShip::NormalShip( int posX, int posY ) : Enemy( "normalShip", "normalShip", posX, posY, 'X', SHOOTING_RATE, MOVING_RATE ) {
    _nbInst++;
    return;
}
NormalShip::NormalShip( int posX, int posY, WINDOW* win ) : Enemy( "normalShip", "normalShip", posX, posY, 'X', SHOOTING_RATE, MOVING_RATE ) {
    _nbInst++;
    mvwaddch(win, this->_posY, this->_posX, this->_token);
    return;
}

NormalShip::~NormalShip( void ) {
    _nbInst--;
    // std::cout << "Destructor called on " << this << std::endl;
    return;
}

NormalShip::NormalShip( NormalShip const & g ) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = g;
    return;
}

// /////////////////////////////////// Getters/Setters 

int                 NormalShip::get_nbInst( void ) {
    return NormalShip::_nbInst;
}

// /////////////////////////////////// Operator overload 

NormalShip &        NormalShip::operator=( NormalShip const & g ) {
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

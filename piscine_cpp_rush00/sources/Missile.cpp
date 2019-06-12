/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Missile.cpp                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 00:57:33 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 00:57:37 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Missile.hpp"
#include "ft_retro.hpp"

int Missile::_nbInst = 0;

// /////////////////////////////////// Members

void            Missile::move( WINDOW* win, int whiles, int dirX, int dirY ) {
    if (win && !(whiles % this->_movingRate)) {
        mvwaddch(win, this->_posY, this->_posX, ' ');
        this->_posX += dirX;
        this->_posY += dirY;
        mvwaddch(win, this->_posY, this->_posX, this->_token);
    }
}

// /////////////////////////////////// Constructors/Destructors

Missile::Missile( void ) : GameEntity() {
    _nbInst++;
    return;
}

Missile::Missile( int posX, int posY, char token, int movingRate ) :
    GameEntity( posX, posY, token, movingRate ) {
    _nbInst++;
    return;
}

Missile::Missile( int posX, int posY, char token, int movingRate, WINDOW* win ) :
    GameEntity( posX, posY, token, movingRate ) {
    _nbInst++;
    mvwaddch(win, this->_posY, this->_posX, token);
    return;
}

Missile::Missile( std::string type, std::string name, int posX, int posY, char token, int movingRate ) :
    GameEntity( type, name, posX, posY, token, movingRate ) {
    _nbInst++;
    return;
}

Missile::~Missile( void ) {
    _nbInst--;
    // std::cout << "Missile destroyed " << this << std::endl;
    return;
}

Missile::Missile( Missile const & g ) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = g;
    return;
}

// /////////////////////////////////// Getters/Setters 

int Missile::get_nbInst( void ) {
    return Missile::_nbInst;
}

// /////////////////////////////////// Operator overload 

Missile &       Missile::operator=( Missile const & g ) {
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

std::ostream &  operator<<( std::ostream &os, Missile &m ) {
    os << "/**********/" <<std::endl
        << "Missile : " << std::endl
        << "posX : " << m.getPosX() << std::endl
        << "posY : " << m.getPosY() << std::endl
        << "token : " << m.getToken() << std::endl
        << "movingRate : " << m.getMovingRate() << std::endl;
    return os;
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   GameEntity.cpp                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 00:57:33 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 00:57:37 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "GameEntity.hpp"

int GameEntity::_nbInst = 0;

// /////////////////////////////////// Constructors/Destructors

GameEntity::GameEntity( void ) :
    _type("default"), _name("default"), _posX(1), _posY(1), _token('?'), _movingRate(10) {
    _nbInst++;
    return;
}

GameEntity::GameEntity( int posX, int posY, char token, int movingRate ) :
    _type("default"), _name("default"), _posX(posX), _posY(posY), _token(token), _movingRate(movingRate){
    _nbInst++;
    return;
}

GameEntity::GameEntity( std::string type, std::string name, int posX, int posY, char token, int movingRate ) :
    _type(type), _name(name), _posX(posX), _posY(posY), _token(token), _movingRate(movingRate) {
    _nbInst++;
    return;
}

GameEntity::~GameEntity( void ) {
    _nbInst--;
    return;
}

GameEntity::GameEntity( GameEntity const & g ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = g;
    return;
}

// /////////////////////////////////// Getters/Setters 

int                 GameEntity::get_nbInst( void ) {
    return GameEntity::_nbInst;
}

std::string         GameEntity::getType( void ) const {
    return this->_type;
}

std::string         GameEntity::getName( void ) const {
    return this->_name;
}

int                 GameEntity::getPosX( void ) const {
    return this->_posX;
}

int                 GameEntity::getPosY( void ) const {
    return this->_posY;
}

char                GameEntity::getToken( void ) const {
    return this->_token;
}

int                 GameEntity::getMovingRate( void ) const {
    return this->_movingRate;
}

// /////////////////////////////////// Operator overload 

GameEntity &        GameEntity::operator=( GameEntity const & f ) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &f) {
        this->_type = f.getType();
        this->_name = f.getName();
        this->_posX = f.getPosX();
        this->_posY = f.getPosY();
        this->_token = f.getToken();
        this->_movingRate = f.getMovingRate();
    }
    return *this;
}
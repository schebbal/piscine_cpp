/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Game.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 00:57:33 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 00:57:37 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_retro.hpp"

// /////////////////////////////////// Members

void            Game::deleteEnemy( int j ) {
    this->_enemies[j] = this->_enemies[--this->_nbEnemies];
    Enemy * nEnemies = new NormalShip[this->_nbEnemies];
    int i = -1;
    while (++i < this->_nbEnemies){
        nEnemies[i] = this->_enemies[i];
    }
    delete [] this->_enemies;
    this->_enemies = nEnemies;
    return;
}

void            Game::addNormalShip( int posX, int posY ) {
    Enemy * nEnemies = new NormalShip[this->_nbEnemies + 1];
    int i = -1;
    while (++i < this->_nbEnemies)
        nEnemies[i] = this->_enemies[i]; 
    this->_nbEnemies++;
    nEnemies[this->_nbEnemies - 1] = NormalShip(posX, posY);
    delete [] this->_enemies;
    this->_enemies = nEnemies;
    return;
}

void            Game::spawnEnemies( void ) {
    int randX, randY;

    randX = rand() % 5 + (WIDTH - 5);
    randY = rand() % (HEIGHT - 3) + 1;
    this->addNormalShip(randX, randY);
    this->_timeLastSpawn = this->_timePlayed;
    return;
}

// /////////////////////////////////// Constructors/Destructors

Game::Game( void ) :
    _nbEnemies(0),
    _timeStart(time(0)),
    _timePlayed(time(0)),
    _timeLastSpawn(0),
    _score(0),
    _enemies(nullptr),
    _win(createNewwin(HEIGHT, WIDTH, WYPOS, WXPOS)) {
    this->_player = new Player(1, 1, '0', this->_win);
    this->_enemies = new Enemy[5];
    this->_nbEnemies += 5;
    this->_enemies[0] = NormalShip(WIDTH - 3, 1, this->_win);
    this->_enemies[1] = NormalShip(WIDTH - 3, 4, this->_win);
    this->_enemies[2] = NormalShip(WIDTH - 3, 7, this->_win);
    this->_enemies[3] = NormalShip(WIDTH - 3, 10, this->_win);
    this->_enemies[4] = NormalShip(WIDTH - 3, 13, this->_win);
    return;
}

Game::Game( Game const & g ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = g;
    return;
}

Game::~Game( void ) {
    delete [] this->_enemies;
    delete this->_player;
    return;
}

// /////////////////////////////////// Getters/Setters

int             Game::getNbEnemies( void ) const {
    return this->_nbEnemies;
}

void            Game::setTimePlayed( void ) {
    this->_timePlayed = time(0) - this->_timeStart;
}

int             Game::getTimeStart( void ) const {
    return this->_timeStart;
}

int             Game::getTimePlayed( void ) const {
    return this->_timePlayed;
}

int             Game::getTimeLastSpawn( void ) const {
    return this->_timeLastSpawn;
}

int             Game::getScore( void ) const {
    return this->_score;
}
void             Game::setScore( int n ) {
    this->_score = n;
}

WINDOW *        Game::getWin( void ) const {
    return this->_win;
}

Player *        Game::getPlayer( void ) const {
    return this->_player;
}

Enemy *         Game::getEnemies( void ) {
    return this->_enemies;
}

// /////////////////////////////////// Operator overloads

Game &          Game::operator=(Game const & g) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &g) {
        this->_timeStart = g._timeStart;
        this->_timePlayed = g._timePlayed;
        this->_timeLastSpawn = g._timeLastSpawn;
        this->_nbEnemies = g._nbEnemies;
        this->_score = g._score;
        this->_player = g._player;
        int i = -1;
        while (++i < Enemy::get_nbInst())
            this->_enemies[i] = g._enemies[i];
    }
    return *this;
}

std::ostream &  operator<<(std::ostream &os, Game &g) {
    os
    << "/----------/" << std::endl
    << "Game : " << std::endl
    << "_timeStart : " << g.getTimeStart() << std::endl
    << "_timePlayed : " << g.getTimePlayed() << std::endl
    << "_score : " << g.getScore() << std::endl
    << "_player : " << g.getPlayer() << std::endl;
    return os;
}
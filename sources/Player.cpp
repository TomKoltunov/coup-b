/**
 * @file Player.cpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Implementation code file of "Player.hpp" file
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Player.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace coup
{
    Player::Player(Game* game, const string& name)
    {
        this->_game = game;
        this->_name = name;
        this->_money = 0;
        this->_isInGame = true;
    }

    void Player::income()
    {
        this->_money = this->_money + 1;
    }

    void Player::foreign_aid()
    {
        this->_money = this->_money + 1;
    }

    void Player::coup(Player& other)
    {
        other._isInGame = false;
    }

    string Player::role()
    {
        return this->_name;
    }

    int Player::coins() const
    {
        return this->_money;
    }
}
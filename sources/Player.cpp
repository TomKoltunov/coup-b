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
        this->blocked = NULL;
        this->last = 0;
        this->toTake = 0;
        if (this->_game->players().size() >= 6)
        {
            throw invalid_argument{"There is no place to add this player to this game"};
        }
        else 
        {
            this->_game->_turns.push_back(this);
        }
    }

    void Player::income()
    {
        if (this->coins() >= 10)
        {
            throw invalid_argument{"Must perform 'coup' on some player in this game"};
        }
        else if (this != this->_game->nextPlaying())
        {
            throw invalid_argument{"It's not 'this' player's turn to play"};
        }
        else
        {
            this->_money = this->_money + 1;
            last = INCOME;
            this->_game->nowPlaying = this->_game->nowPlaying + 1; 
        }
    }

    void Player::foreign_aid()
    {
        if (this->coins() >= 10)
        {
            throw invalid_argument{"Must perform 'coup' on some player in this game"};
        }
        else if (this != this->_game->nextPlaying())
        {
            throw invalid_argument{"It's not 'this' player's turn to play"};
        }
        else
        {
            this->_money = this->_money + 2;
            last = FOREIN_AID;
            this->_game->nowPlaying = this->_game->nowPlaying + 1; 
        }
    }

    void Player::coup(Player& other)
    {
        if (this->coins() >= 10)
        {
            throw invalid_argument{"Must perform 'coup' on some player in this game"};
        }
        else if (this->coins() < 3)
        {
            throw invalid_argument{"'this' doesn't have enough money to perform 'coup' on 'other''"};
        }
        else if (this != this->_game->nextPlaying())
        {
            throw invalid_argument{"It's not 'this' player's turn to play"};
        }
        else
        {
            other._isInGame = false;
            this->_money = this->_money - 7;
            last = COUP;
            this->_game->nowPlaying = this->_game->nowPlaying + 1; 
        }   
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
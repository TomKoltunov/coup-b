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

const int SIX = 6;
const int SEVEN = 7;
const int TEN = 10;

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
        if (this->_game->players().size() >= SIX)
        {
            throw invalid_argument{"There is no place to add this player to this game"};
        }
        if (this->_game->hasBegan)
        {
            throw invalid_argument{"Unable to add new player in a middle of a game"};
        }
        this->_game->_turns.push_back(this);
    }

    void Player::income()
    {
        if (!(this->_game->hasBegan))
        {
            if (this->_game->players().size() < 2)
            {
                throw invalid_argument{"Should be at least 2 players in order to perform 'coup'"};
            }
            this->_game->hasBegan = true;
            if (this->_money >= TEN)
            {
                throw invalid_argument{"Must perform 'coup' on some player in this game"};
            }
            if (this != this->_game->nextPlaying())
            {
                throw invalid_argument{"It's not 'this' player's turn to play"};
            }
            this->_money = this->_money + 1;
            last = INCOME;
            this->_game->nowPlaying = this->_game->nowPlaying + 1;
        }
        else 
        {
            if (this->_money >= TEN)
            {   
                throw invalid_argument{"Must perform 'coup' on some player in this game"};
            }
            if (this != this->_game->nextPlaying())
            {
                throw invalid_argument{"It's not 'this' player's turn to play"};
            }
            if (this->_game->players().size() < 2)
            {
                throw invalid_argument{"Should be at least 2 players in order to perform 'coup'"};
            }
            this->_money = this->_money + 1;
            last = INCOME;
            this->_game->nowPlaying = this->_game->nowPlaying + 1; 
        }
    }

    void Player::foreign_aid()
    {
        if (!(this->_game->hasBegan))
        {
            if (this->_game->players().size() < 2)
            {
                throw invalid_argument{"Should be at least 2 players in order to perform 'coup'"};
            }
            this->_game->hasBegan = true;
            if (this->_money >= TEN)
            {
                throw invalid_argument{"Must perform 'coup' on some player in this game"};
            }
            if (this != this->_game->nextPlaying())
            {
                throw invalid_argument{"It's not 'this' player's turn to play"};
            }
            this->_money = this->_money + 2;
            last = FOREIN_AID;
            this->_game->nowPlaying = this->_game->nowPlaying + 1;
        }
        else 
        {
            if (this->_money >= TEN)
            {
                throw invalid_argument{"Must perform 'coup' on some player in this game"};
            }
            if (this != this->_game->nextPlaying())
            {
                throw invalid_argument{"It's not 'this' player's turn to play"};
            }
            if (this->_game->players().size() < 2)
            {
                throw invalid_argument{"Should be at least 2 players in order to perform 'coup'"};
            }
            this->_money = this->_money + 2;
            last = FOREIN_AID;
            this->_game->nowPlaying = this->_game->nowPlaying + 1;
        }
    }

    void Player::coup(Player& other)
    {
        if (!(this->_game->hasBegan))
        {
            if (this->_game->players().size() < 2)
            {
                throw invalid_argument{"Should be at least 2 players in order to perform 'coup'"};
            }
            this->_game->hasBegan = true;
            if (!(other._isInGame))
            {
                throw invalid_argument{"'other' doesn't playing in this game anymore"};
            }
            if (this->_money < SEVEN)
            {
                throw invalid_argument{"'this' doesn't have enough money to perform 'coup' on 'other''"};
            }
            if (this != this->_game->nextPlaying())
            {
                throw invalid_argument{"It's not 'this' player's turn to play"};
            }
            other._isInGame = false;
            this->_game->nowPlaying = this->_game->nowPlaying + 1; 
            this->_money = this->_money - SEVEN;
            last = COUP;
        }
        else 
        {
            if (!(other._isInGame))
            {
                throw invalid_argument{"'other' doesn't playing in this game anymore"};
            }
            if (this->_money < SEVEN)
            {
                throw invalid_argument{"'this' doesn't have enough money to perform 'coup' on 'other''"};
            }
            if (this != this->_game->nextPlaying())
            {
                throw invalid_argument{"It's not 'this' player's turn to play"};
            }
            if (this->_game->players().size() < 2)
            {
                throw invalid_argument{"Should be at least 2 players in order to perform 'coup'"};
            }
            other._isInGame = false;
            this->_game->nowPlaying = this->_game->nowPlaying + 1; 
            this->_money = this->_money - SEVEN;
            last = COUP;
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
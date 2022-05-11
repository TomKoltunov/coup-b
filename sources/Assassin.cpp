/**
 * @file Assassin.cpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Implementation code file of "Assassin.hpp" file
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Assassin.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace coup
{
    /*
    The constructor named "Assassin" recieves a 'Game' object reference called "game" which represents the game that the created 
    player (Assassin) participates and a string called "name" which represents the players's (Assassin's) name.
    Since each 'Assassin' object is a 'Player' object so the constructor inherites from 'Player' and thus it firstly creates
    'Player' object by using 'Player' class constructor (which by the way recieves the same parameters as the 'Assassin' constructor).
    This way each 'Assassin' instance has all the 'Player' methods and since all 'Player's attributes are 'protected' access level 
    (and as said 'Assassin' inherites from 'Player') - each 'Assassin' instance have also this attributes.
    */
    Assassin::Assassin(Game& game, const string& name) : Player(&game, name) 
    {

    }

    /*
    The method named "role" recieves no parameters and is overridden from the 'Player' class (since 'Assassin' inherites from 'Player').
    The function will return a string which represents the players' role which in this case is 'Assassin'.
    */
    string Assassin::role()
    {
        return "Assassin";
    }

    /*
    The method named "coup" recieves a 'Player' object reference called 'other' which represents the player that the assassin will
    dismiss by paying 3 coins and is overridden from the 'Player' class (since 'Assassin' inherites from 'Player') - in order to
    dismiss 'other' the assassin has to pay 3 coins (while all other roles have to pay 7 coins to do it).
    This method's execution can be blocked by the 'Contessa' role - in this case 'other' will return to the game.
    */
    void Assassin::coup(Player& other)
    {
        if (!(other._isInGame))
        {
            throw invalid_argument{"'other' doesn't playing in this game anymore"};
        }
        else if (this != this->_game->nextPlaying())
        {
            throw invalid_argument{"It's not 'this' player's turn to play"};
        }
        // else if (this->_game->players().size() < 2)
        // {
        //     throw invalid_argument{"Should be at least 2 players in order to perform 'coup'"};
        // }
        else if (this->_money >= 7)
        {
            this->_money = this->_money - 7;
            last = Move::COUP;
        }
        else if ((this->_money >= 3) && (this->_money < 7))
        {
            blocked = &other;
            this->_money =this->_money - 3;
            last = Move::ASSASSINCOUP;
        }
        else 
        {
            throw invalid_argument{"'this' player doesn't have enough money to perform Assassin's 'coup'"};
        }
        other._isInGame = false;
        this->_game->nowPlaying = this->_game->nowPlaying + 1; 
    }
} 

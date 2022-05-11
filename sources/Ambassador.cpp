/**
 * @file Ambassador.cpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Implementation code file of "Ambassador.hpp" file
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Ambassador.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace coup
{
    /*
    The constructor named "Ambassador" recieves a 'Game' object reference called "game" which represents the game that the created 
    player (Ambassador) participates and a string called "name" which represents the players's (Ambassador's) name.
    Since each 'Ambassador' object is a 'Player' object so the constructor inherites from 'Player' and thus it firstly creates
    'Player' object by using 'Player' class constructor (which by the way recieves the same parameters as the 'Ambassador' constructor).
    This way each 'Ambassador' instance has all the 'Player' methods and since all 'Player's attributes are 'protected' access level 
    (and as said 'Ambassador' inherites from 'Player') - each 'Ambassador' instance have also this attributes.
    */
    Ambassador::Ambassador(Game& game, const string& name) : Player(&game, name) 
    {

    }

    /*
    The method named "role" recieves no parameters and is overridden from the 'Player' class (since 'Ambassador' inherites from 'Player').
    The function will return a string which represents the players' role which in this case is 'Ambassador'.
    */
    string Ambassador::role()
    {
        return "Ambassador";
    }

    /*
    The method named "transfer" recieves a 'Player' object reference called 'player1' which represents the player that the ambassador
    is taking a coin from and a 'Player' object reference called 'player2' which represents the player that the ambassador
    is giving the coin to.
    */
    void Ambassador::transfer(Player& player1, Player& player2)
    {
        if (this->coins() >= 10)
        {
            throw invalid_argument{"Must perform 'coup' on some player in this game"};
        }
        else if (this != this->_game->nextPlaying())
        {
            throw invalid_argument{"It's not 'this' player's turn to play"};
        }
        else if (player1._money > 0)
        {
            player1._money = player1._money - 1;
            player2._money = player2._money + 1;
            last = TRANSFER;
            this->_game->nowPlaying = this->_game->nowPlaying + 1; 
        }
        else
        {
            throw invalid_argument{"'player1' doesn't have any money to transfer"};
        }
    }

    /*
    The method named "block" recives a 'Player' object reference called 'player' which represents the player that the ambassador 
    prevents from taking 2 coins from other player. 'player's role can only be 'Captain'
    */
    void Ambassador::block(Player& player)
    {
        if (player.last == STEAL)
        {
            player._money = player._money - player.toTake;
            player.blocked->_money = player.blocked->_money + player.toTake;
        }
        else
        {
            throw invalid_argument{"Unable to do it"};
        }
    }
} 

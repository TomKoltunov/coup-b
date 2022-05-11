/**
 * @file Contessa.cpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Implementation code file of "Contessa.hpp" file
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Contessa.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace coup
{
    /*
    The constructor named "Contessa" recieves a 'Game' object reference called "game" which represents the game that the created 
    player (Contessa) participates and a string called "name" which represents the players's (Contessa's) name.
    Since each 'Contessa' object is a 'Player' object so the constructor inherites from 'Player' and thus it firstly creates
    'Player' object by using 'Player' class constructor (which by the way recieves the same parameters as the 'Contessa' constructor).
    This way each 'Contessa' instance has all the 'Player' methods and since all 'Player's attributes are 'protected' access level 
    (and as said 'Contessa' inherites from 'Player') - each 'Contessa' instance have also this attributes.
    */
    Contessa::Contessa(Game& game, const string& name) : Player(&game, name)
    {

    }

    /*
    The method named "role" recieves no parameters and is overridden from the 'Player' class (since 'Contessa' inherites from 'Player').
    The function will return a string which represents the players' role which in this case is 'Contessa'.
    */
    string Contessa::role()
    {
        return "Contessa";
    }

    void Contessa::block(Player& player)
    {
        if (player.last == Move::ASSASSINCOUP)
        {
            player.blocked->_isInGame = true;
        }
        else
        {
            throw invalid_argument{"Unable to do it"};
        }
    }
} 

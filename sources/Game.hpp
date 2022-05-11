/**
 * @file Game.hpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Headers file for 'Game' objects
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include "Player.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Move
{
    INCOME = 1,
    FOREIN_AID = 2,
    TAX = 3,
    TRANSFER = 4,
    STEAL = 5,
    ASSASSINCOUP = 6,
    COUP = 7
};

namespace coup
{
    class Player;

    class Game
    {
        public:
            Game();
            vector<Player*> _turns;
            size_t nowPlaying;
            Player* nextPlaying();
            string turn();
            vector<string> players();
            string winner();
    };
}
/**
 * @file Player.hpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Headers file for 'Player' objects
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include "Game.hpp"
#include <iostream>
#include <string>

using namespace std;

#define INCOME 1
#define FOREIN_AID 2
#define TAX 3
#define TRANSFER 4
#define STEAL 5
#define ASSASSIN_COUP 6
#define COUP 7

namespace coup
{
    class Game;
    
    class Player
    {
        public:
            Game *_game;
            string _name;
            int _money;
            bool _isInGame;
            Player *blocked;
            int last;
            int toTake;
            Player(Game *game, const string &name);
            void income();
            void foreign_aid();
            virtual void coup(Player& other);
            virtual string role();
            int coins() const;
    };
} 

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

namespace coup
{
    class Player
    {
        public:
            Game* _game;
            string _name;
            int _money;
            bool _isInGame;
            Player(Game* game, const string& name);
            void income();
            void foreign_aid();
            virtual void coup(Player& other);
            virtual string role();
            int coins() const;
    };
} 
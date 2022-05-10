/**
 * @file Ambassador.hpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Headers file for 'Ambassador' objects
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Player.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace coup
{
    class Ambassador : public Player
    {
        public:
            Ambassador(Game& game, const string& name);
            string role();
            void transfer(Player& player1, Player& player2);
            void block(Player& player);
    };
}
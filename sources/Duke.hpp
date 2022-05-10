/**
 * @file Duke.hpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Headers file for 'Duke' objects
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
    class Duke : public Player
    {
        public:
            Duke(Game& game, const string& name);
            string role();
            void tax();
            void block(Player& player);
    };
}
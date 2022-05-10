/**
 * @file Captain.hpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Headers file for 'Captain' objects
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
    class Captain : public Player
    {
        public:
            Captain(Game& game, const string& name);
            string role();
            void steal(Player& player);
            void block(Player& player);
    };
}
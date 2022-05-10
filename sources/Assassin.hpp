/**
 * @file Assassin.hpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Headers file for 'Assassin' objects
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
    class Assassin : public Player
    {
        public:
            Assassin(Game& game, const string& name);
            string role();
            void coup(Player& other);
    };
}
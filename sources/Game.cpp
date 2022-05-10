/**
 * @file Game.cpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Implementation code file of "Game.hpp" file
 * @version 0.1
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Game.hpp"
#include <vector>
#include <string>
#include <vector>

using namespace std;

Game::Game()
{
    
}

string Game::turn()
{
    
    return " ";
}

vector<string> Game::players()
{
    vector<string> vec;
    
    return vec;
}

string Game::winner()
{
    if (this->players().size() > 1) 
    {
        throw invalid_argument{"There is still no winner in this game"};
    }
    else 
    {
        return " ";
    }
}
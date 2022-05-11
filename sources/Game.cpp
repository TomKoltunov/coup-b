/**
 * @file Game.cpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Implementation code file of "Game.hpp" file
 * @version 0.1
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Game.hpp"
using namespace std;

namespace coup
{
    Game::Game()
    {
        this->nowPlaying = 0;
    }

    string Game::turn()
    {
        return this->nextPlaying()->_name;
    }   

    vector<string> Game::players()
    {
        vector<string> vec(this->_turns.size());
        for (size_t i = 0; i < _turns.size(); i++)
        {
            if (this->_turns[i]->_isInGame)
            {
                vec[i] = this->_turns[i]->_name;
            }
        }
        return vec;
    }

    string Game::winner()
    {
        if (this->players().size() == 1) 
        {
            return this->nextPlaying()->_name;
        }
        else 
        {
            throw invalid_argument{"There is still no winner in this game"};
        }
    }

    Player* Game:: nextPlaying()
    {
        size_t size = this->_turns.size();
        if ((!(this->_turns[nowPlaying]->_isInGame) && nowPlaying == (size - 1)) || (nowPlaying >= size))
        {
            nowPlaying = 0;
        }
        for (size_t i = nowPlaying; i < size; i++)
        {
            if (this->_turns[i]->_isInGame)
            {
                nowPlaying = i;
                break;
            }
        }
        ///////////////////////////////////////////////////////////////////////////
        if (!(this->_turns[nowPlaying]->_isInGame) && nowPlaying != (size - 1))
        {
            for (size_t i = nowPlaying; i < size; i++)
            {
                if (this->_turns[i]->_isInGame)
                {
                    nowPlaying = i;
                    break;
                }
            }
        }
        ////////////////////////////////////////////////////////////////////////////
        return this->_turns[nowPlaying];
    }

    void Game::insert(Player *player)
    {
        if (this->players().size() >= 6)
        {
            throw invalid_argument{""};
        }
        this->_turns.push_back(player);
    }
}
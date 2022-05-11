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
        this->hasBegan = false;
    }

    string Game::turn()
    {
        return this->nextPlaying()->_name;
    }   

    vector<string> Game::players()
    {
        vector<string> vec;
        for (size_t i = 0; i < this->_turns.size(); i++)
        {
            if (this->_turns[i]->_isInGame)
            {
                vec.push_back(this->_turns[i]->_name);
            }
        }
        return vec;
    }

    string Game::winner()
    {
        if (!this->hasBegan)
        {
            throw invalid_argument{"no winner"};
        }
        if (this->players().size() > 1)
        {
            throw invalid_argument{"There is still no winner in this game"};
        }
        return this->nextPlaying()->_name;
    }

    Player* Game:: nextPlaying()
    {
        size_t size = this->_turns.size();
        if (this->nowPlaying >= size)
        {
            this->nowPlaying = 0;
        }
        if (((!(this->_turns[nowPlaying]->_isInGame)) && (this->nowPlaying == (size - 1))))
        {
            this->nowPlaying = 0;
        }
 
        for (size_t i = nowPlaying; i < size; i++)
        {
            if (this->_turns[i]->_isInGame)
            {
                this->nowPlaying = i;
                break;
            }
        }
        ///////////////////////////////////////////////////////////////////////////
        if (!(this->_turns[nowPlaying]->_isInGame))
        {
            for (size_t i = 0; i < size; i++)
            {
                if (this->_turns[i]->_isInGame)
                {
                    this->nowPlaying = i;
                    break;
                }
            }
        }
        ////////////////////////////////////////////////////////////////////////////
        return this->_turns[nowPlaying];
    }
}
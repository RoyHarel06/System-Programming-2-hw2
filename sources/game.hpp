#pragma once

#include "player.hpp"
#include <queue>

namespace ariel
{
    class Game
    {
        private:
            Player player1;
            Player player2;
            int turn;
            int draw_counter;
            queue<std::string> log;
            bool game_ended;
            
        public:
            Game(Player p1, Player p2);
            
            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
    };
}
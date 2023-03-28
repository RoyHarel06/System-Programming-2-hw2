#pragma once

#include "card.hpp"

#include <string>
#include <queue>
using namespace std;

namespace ariel
{
    class Player
    {
        private:
            string name;
            queue<Card> hand;
            queue<Card> cards_won;

        public:
            Player(string name);

            string getName();

            int stacksize();
            int cardesTaken();

            void addCardToHand(const Card& card);
            const Card& playTopCardFromHand();
            bool hasCardsInHand();
    };
}
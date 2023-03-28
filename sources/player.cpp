#include "player.hpp"

namespace ariel
{
    Player::Player(string name) {
        this->name = name;
    }
    string Player::getName() {
        return this->name;
    }

    void Player::addCardToHand(const Card& card)
    {
        hand.push(card);
    }

    Card& Player::playTopCardFromHand()
    {
        if (!hand.empty())
        {
            Card ret = hand.front();
            hand.pop();
            return ret;
        }

        return NULL;
    }

    const Card& Player::getTopCard()
    {
        return ;
    }

    bool Player::hasCards()
    {
        return !hand.empty();
    }
}
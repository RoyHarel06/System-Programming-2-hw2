#pragma once

#include "card.hpp"
#include <stdexcept>

namespace ariel
{
    Card::Card(int value, char suit) {
        this->value = value;
        this->suit = suit;
    }
    int Card::getValue() {
        return this->value;
    }
    std::string Card::getSuitName() {
        switch(suit) {
            case 'h':
                return "Hearts";
            case 's':
                return "Spades";
            case 'd':
                return "Diamonds";
            case 'c':
                return "Clubs";
            default:
                throw std::logic_error("Invalid suit.");
        }
    }

    bool Card::operator==(const Card& other) const {
        return value == other.value;
    }
    bool Card::operator>(const Card& other) const {
        if (value == 1 && other.value != 2)
            return true;
        return value > other.value;
    }
    bool Card::operator<(const Card& other) const {
        if (value != 2 && other.value == 1)
            return true;
        return value < other.value;
    }
}
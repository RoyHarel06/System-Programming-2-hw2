#pragma once

#include <string>

namespace ariel
{
    class Card
    {
        private:
            int value;
            char suit;
            
        public:
            Card(int value, char suit);
            int getValue();
            std::string getSuitName();

            // Operators are used to compare two card's values!
            bool operator==(const Card& other) const;
            bool operator>(const Card& other) const;
            bool operator<(const Card& other) const;
    };
}
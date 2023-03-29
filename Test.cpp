#include "../doctest.h"

#include "player.hpp"
#include "game.hpp"
#include "card.hpp"

using namespace ariel;

TEST_CASE("Game Initialization Test") {
    Player player1("Roy");
    Player player2("Dan");

    Game game(player1, player2);

    CHECK(player1.stacksize() == 26);
    CHECK(player2.stacksize() == 26);
    CHECK(player1.cardesTaken() == 0);
    CHECK(player2.cardesTaken() == 0);
}
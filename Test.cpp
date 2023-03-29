#include "../doctest.h"

#include "player.hpp"
#include "game.hpp"
#include "card.hpp"

using namespace ariel;

TEST_CASE("Card Initialization") {
    Card ace(1, "Clubs");

    CHECK(ace.getSuit() == "Clubs");
    CHECK(ace.getValue() == 1);
}

TEST_CASE("Card Initialization - Invalid Suit") {
    CHECK_THROWS(Card{1, "bla"});
}

TEST_CASE("Card Initialization - Invalid Value") {
    CHECK_THROWS(Card{52, "Hearts"});
}

TEST_CASE("Card Operator Logic - Ace Wins All But 2") {
    Card ace(1, "Clubs");

    for (int i = 3; i <= 13; i++)
    {
        Card temp(i, "Hearts");
        CHECK(temp < ace);
    }
    
    Card two(2, "Hearts");
    CHECK(two > ace);
}

TEST_CASE("Player Initialization") {
    Player player("Roy");

    CHECK(player.getName() == "Roy");
    CHECK(player.stacksize() == 0);
    CHECK(player.cardesTaken() == 0);
}

TEST_CASE("Game Initialization - Empty Player Name") {
    Player player1("");
    Player player2("Dan");

    CHECK_THROWS(Game{player1, player2});
    CHECK_THROWS(Game{player2, player1});
}

TEST_CASE("Game Initialization - Both Same Player") {
    Player player("Roy");

    CHECK_THROWS(Game{player, player});
}

TEST_CASE("Game Initialization - Has Cards Before Game") {
    Player player1("Roy");
    Player player2("Dan");

    player1.addCardToHand(Card(2, "Hearts"));

    CHECK_THROWS(Game{player1, player2});
    CHECK_THROWS(Game{player2, player1});
}

TEST_CASE("Game Initialization - Starting Values") {
    Player player1("Roy");
    Player player2("Dan");

    CHECK(player1.stacksize() == 26);
    CHECK(player2.stacksize() == 26);
    CHECK(player1.cardesTaken() == 0);
    CHECK(player2.cardesTaken() == 0);
}

TEST_CASE("Game Turn - Cards were Taken") {
    Player player1("Roy");
    Player player2("Dan");

    Game game(player1, player2);

    game.playTurn();

    CHECK(player1.cardesTaken() + player2.cardesTaken() > 0);
    CHECK(player1.cardesTaken() + player2.cardesTaken() == 52 - player1.stacksize() - player2.stacksize());
}

TEST_CASE("Game Ends After at Most 26 Turns") {
    Player player1("Roy");
    Player player2("Dan");

    Game game(player1, player2);

    game.playAll();

    CHECK(game.getNumberOfTurns() <= 26);
}

TEST_CASE("Game End - All Cards Were Taken") {
    Player player1("Roy");
    Player player2("Dan");

    Game game(player1, player2);

    game.playAll();

    CHECK(player1.cardesTaken() + player2.cardesTaken() == 52);
}

TEST_CASE("Game End - All Cards Were Used") {
    Player player1("Roy");
    Player player2("Dan");

    Game game(player1, player2);

    game.playAll();

    CHECK(player1.stacksize() == 0);
    CHECK(player2.stacksize() == 0);
}

TEST_CASE("Game End - Correct Winner") {
    Player player1("Roy");
    Player player2("Dan");

    Game game(player1, player2);

    game.playAll();

    if (game.getWinner() == player1.getName())
        CHECK(player1.cardesTaken() > player2.cardesTaken());
    else if (game.getWinner() == player2.getName())
        CHECK(player2.cardesTaken() > player1.cardesTaken());
    else
        CHECK(player2.cardesTaken() == player1.cardesTaken());
}

TEST_CASE("Print Winner - Before Game Start") {
    Player player1("Roy");
    Player player2("Dan");

    Game game(player1, player2);

    CHECK_THROWS(game.printWiner());
}

TEST_CASE("Print Winner - Before Game End") {
    Player player1("Roy");
    Player player2("Dan");

    Game game(player1, player2);

    game.playTurn();

    CHECK_THROWS(game.printWiner());
}

TEST_CASE("Print Last Turn - Before Game Start") {
    Player player1("Roy");
    Player player2("Dan");

    Game game(player1, player2);

    CHECK_THROWS(game.printLastTurn());
}

TEST_CASE("Print Log - Before Game Start") {
    Player player1("Roy");
    Player player2("Dan");

    Game game(player1, player2);

    CHECK_THROWS(game.printLog());
}

TEST_CASE("Print Stats - Before Game Start") {
    Player player1("Roy");
    Player player2("Dan");

    Game game(player1, player2);

    CHECK_THROWS(game.printStats());
}

TEST_CASE("Play Turn - Game Ended") {
    Player player1("Roy");
    Player player2("Dan");

    Game game(player1, player2);

    game.playAll();
    
    CHECK_THROWS(game.playTurn());
}
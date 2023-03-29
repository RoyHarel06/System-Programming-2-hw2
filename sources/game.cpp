#include "game.hpp"

#include <iostream>

namespace ariel
{
    Game::Game(Player player1, Player player2): player1(player1), player2(player2) {
        if (player1.getName().empty())
            throw std::invalid_argument("Player 1 has no name.");
        if (player2.getName().empty())
            throw std::invalid_argument("Player 2 has no name.");

        if (player1.getName() == player2.getName())
            throw std::invalid_argument("Same player.");

        if (player1.stacksize() != 0 || player1.cardesTaken() != 0)
            throw std::invalid_argument("Player 1 has cards.");
        if (player2.stacksize() != 0 || player1.cardesTaken() != 0)
            throw std::invalid_argument("Player 2 has cards.");

        

        this->turn = 0;
        this->draw_counter = 0;
        this->game_ended = false;
    }

    int Game::getNumberOfTurns() {
        return turn;
    }

    /*
     * plays the next turn in the game and logs the results.
     */
    void Game::playTurn() {
        // TODO: in part b!
    }

    /*
     * playes the game untill the end.
     */
    void Game::playAll() {
        //while (game_ended == false) {
        //    playTurn();
        //}
    }

    /*
     * prints the name of the winning player.
     */
    void Game::printWiner() {
        if (turn == 0)
            cout << "The game hasn't started yet.\n";
        else if (game_ended == false)
            cout << "The game hasn't ended yet!\n";
        else if (player1.stacksize() > player2.stacksize())
            cout << player1.getName() << " won!\n";
        else
            cout << player2.getName() << " won!\n";
    }

    /*
     * print the last turn stats. For example:
     * 1) Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
     * 2) Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds.
     *    Draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
     */
    void Game::printLastTurn() {
        //cout << log.back() << "\n";
    }

    /*
     * prints all the turns played one line per turn (same format as game.printLastTurn()).
     */
    void Game::printLog() {
        /*cout << "Game log:\n";
        while (!log.empty()) {
            cout << log.front() << "\n";
            log.pop();
        }*/
    }

    /*
     * for each player prints basic statistics: win rate, cards won, <other stats you want to print>.
     * Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws.)
     */
    void Game::printStats() {
        if (turn == 0)
            cout << "The game hasn't started yet.\n";
        else {
            cout << player1.getName() << "'s stats:\n";
            cout << "Win rate: " << (player1.cardesTaken() / 26) * 100 << "%\n";
            cout << "Cards won: " << player1.cardesTaken() << "\n\n";

            cout << player2.getName() << "'s stats:\n";
            cout << "Win rate: " << (player2.cardesTaken() / 26) * 100 << "%\n";
            cout << "Cards won: " << player2.cardesTaken() << "\n\n";
        
            cout << "Draw rate: " << ((double)draw_counter / turn) * 100 << "%\n";
            cout << "Draw counter: " << draw_counter << "\n";
        }
    }
}
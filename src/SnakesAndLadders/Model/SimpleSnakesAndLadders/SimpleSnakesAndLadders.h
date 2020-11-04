#ifndef MIDTERM_SIMPLESNAKESANDLADDERS_H
#define MIDTERM_SIMPLESNAKESANDLADDERS_H

#include "../SnakesAndLaddersModel.h"
#include "Board/Board.h"
#include "Board/BoardBuilder.h"
#include "Player/Player.h"
class SimpleSnakesAndLadders : public SnakesAndLaddersModel {
private:
    Board board;

    bool activeGame;
    int numPlayers;
    Player **players;   // Array of player pointers
public:
    explicit SimpleSnakesAndLadders(DE1SoCfpga* de1SoCfpga, const Board& board, int numPlayers);
    ~SimpleSnakesAndLadders();

    // From SnakesAndLadderModel
    bool IsGameOver();
    int GetWinner();
    int GetPlayerPosition(int playerNumber);
    int GetNumberOfPlayers();
    int SnakeLadderDestinationAt(int tile);
    bool IsSnakeLadderAt(int tile);
    int MovePlayer(int playerNumber);
};


#endif//MIDTERM_SIMPLESNAKESANDLADDERS_H

#include "SimpleSnakesAndLadders.h"

#include "Board/BoardBuilder.h"
#include "Player/ComPlayer.h"

SimpleSnakesAndLadders::SimpleSnakesAndLadders(DE1SoCfpga * de1SoCfpga, const Board& board, int numPlayers) : board(board) {
    this->numPlayers = numPlayers;
    this->players = new Player*[numPlayers];
    this->activeGame = true;

    // Assign players
    this->players[0] = new Player(de1SoCfpga);
    for (int i = 1; i < numPlayers; i++) {
        this->players[i] = new ComPlayer(de1SoCfpga);
    }
}

SimpleSnakesAndLadders::~SimpleSnakesAndLadders() {
    for (int i = 0; i < this->numPlayers; i++) {
        delete players[i];
    }

    delete[] this->players;
}

bool SimpleSnakesAndLadders::IsGameOver() {
    return !this->activeGame;
}

int SimpleSnakesAndLadders::GetWinner() {
    for (int i = 0; i < numPlayers; i++) {
        if (players[i]->GetPosition() >= board.GetSize()) {
            return i;
        }
    }
    return -1;
}

int SimpleSnakesAndLadders::GetNumberOfPlayers() {
    return this->numPlayers;
}

int SimpleSnakesAndLadders::GetPlayerPosition(int playerNumber) {
    return this->players[playerNumber]->GetPosition();
}

int SimpleSnakesAndLadders::SnakeLadderDestinationAt(int tile) {
    return this->board.GetSnakeLadderDestinationAt(tile);
}

bool SimpleSnakesAndLadders::IsSnakeLadderAt(int tile) {
    return this->board.SnakeLadderAt(tile);
}

int SimpleSnakesAndLadders::MovePlayer(int playerNumber) {
    int numberOfMoves = players[playerNumber]->MakeMove();
    int destinationTile = GetPlayerPosition(playerNumber) + numberOfMoves;
    int snakeLadderDestination = SnakeLadderDestinationAt(destinationTile);
    if (snakeLadderDestination > 0)
        players[playerNumber]->SetPosition(snakeLadderDestination);
    else players[playerNumber]->SetPosition(destinationTile);

    if (players[playerNumber]->GetPosition() >= board.GetSize())
        this->activeGame = false;
    return numberOfMoves;
}
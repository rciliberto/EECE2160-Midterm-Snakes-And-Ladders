#include "Board.h"

Board::Board(int size, const map<int, SnakeLadder> &snakeLadders) {
    this->size = size;
    this->snakeLadders = snakeLadders;
}

int Board::GetSize() {
    return this->size;
}

bool Board::SnakeLadderAt(int tile) {
    return (snakeLadders.find(tile) != snakeLadders.end());
}

int Board::GetSnakeLadderDestinationAt(int tile) {
    if (!SnakeLadderAt(tile)) return -1;
    return snakeLadders.find(tile)->second.GetDestinationTile();
}

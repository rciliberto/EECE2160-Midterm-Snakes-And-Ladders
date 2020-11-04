#include "SnakeLadder.h"

SnakeLadder::SnakeLadder(int sourceTile, int destinationTile) {
    this->sourceTile = sourceTile;
    this->destinationTile = destinationTile;
}

int SnakeLadder::GetSourceTile() {
    return this->sourceTile;
}
int SnakeLadder::GetDestinationTile() {
    return this->destinationTile;
}
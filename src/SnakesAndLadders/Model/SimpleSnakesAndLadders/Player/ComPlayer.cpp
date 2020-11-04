#include "ComPlayer.h"
#include <cstdlib>
#include <ctime>

ComPlayer::ComPlayer(DE1SoCfpga *de1SoCfpga) : Player(de1SoCfpga) {
    srand(time(NULL));
    this->position = 1;
}

int ComPlayer::MakeMove() {
    // Random number 1 - 4
    return rand() % 6 + 1;
}
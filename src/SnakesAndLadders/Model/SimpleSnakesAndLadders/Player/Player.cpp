#include "Player.h"
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Player::Player(DE1SoCfpga *de1SoCfpga) : button(new PushButton(de1SoCfpga)){
    srand(time(NULL));
    this->position = 1;
}

int Player::GetPosition() {
    return this->position;
}

int Player::MakeMove() {
    // Random number 1 - 4
    cout << "Press one of the buttons to make a move..." << endl;

    //usleep(1000);

    // Wait until a button is pressed
    int buttonStatus = button->PushButtonGet();
    int newStatus = buttonStatus;
    while (buttonStatus == newStatus) {
        newStatus = button->PushButtonGet();
    }

    cout << "Rolling..." << endl;
    return rand() % 6 + 1;
}

void Player::SetPosition(int tile) {
    this->position = tile;
}
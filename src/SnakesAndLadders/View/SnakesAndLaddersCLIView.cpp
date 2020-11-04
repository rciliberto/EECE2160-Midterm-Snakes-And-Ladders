#include "SnakesAndLaddersCLIView.h"
#include <iostream>
#include <sstream>

using namespace std;

string DieRollSound = "C4.5,G4.5,C5.5,C4.5,G4.5,C5.5,C4.5,G4.5,C5.5,C4.5,G4.5,C5.5,C4.5,G4.6,C5.7,C4.8,G4.9,C5.10,C4.11,G4.12,C5.13,C4.14,G4.15,C5.16,C4.17,G4.18,C5.19";
string LadderSound = "E4.5,B4.5,E5.5,F4.5,C5.5,F5.5,FsGf4.5,CsDf5.5,FsGf5.5,G4.5,D5.5,G5.5,GsAf4.5,DsEf5.5,GsAf5.5";
string SnakeSound = "GsAf4.5,DsEf5.5,GsAf5.5,G4.5,D5.5,G5.5,FsGf4.5,CsDf5.5,FsGf5.5,F4.5,C5.5,F5.5,E4.5,B4.5,E5.5";
string WinSound = "C5.28,E5.28,G5.28,C6.44,G5.12,C6.28";
string LoseSound = "F5.20,F4.25,C4.10,C5.20";

SnakesAndLaddersCLIView::SnakesAndLaddersCLIView(DE1SoCfpga *de1SoCfpga) : musicPlayer(new MusicPlayer(de1SoCfpga)) {}
SnakesAndLaddersCLIView::~SnakesAndLaddersCLIView() {
    delete musicPlayer;
}

void SnakesAndLaddersCLIView::ShowIntroduction() {
    cout << "Welcome to the game of Snakes and Ladders!!" << endl;
    cout << "Please use the provided game board for snake and ladder positions." << endl << endl;
}

void SnakesAndLaddersCLIView::ClearState() {
    cout << endl << endl << "New Turn:" << endl;
}

void SnakesAndLaddersCLIView::ShowState(SnakesAndLaddersModel *model) {
    for (int i = 0; i < model->GetNumberOfPlayers(); i++) {
        if (i == 0) {
            cout << "You";
        } else {
            cout << "Player " << i + 1;
        }
        cout << ": " << model->GetPlayerPosition(i) << endl;
    }
    cout << endl;
}

void SnakesAndLaddersCLIView::ShowMove(SnakesAndLaddersModel *model, int playerNumber, int initialPosition, int roll) {
    int movedPos = initialPosition + roll;
    string playerName = "You";
    if (playerNumber != 0) {
        playerName = "Player " + dynamic_cast<ostringstream*>( &(ostringstream() << playerNumber + 1) )->str();
    }
    if (playerNumber == 0) musicPlayer->PlaySong(DieRollSound);
    cout << playerName + " rolled a " << roll << " and moved from " << initialPosition << " to " << movedPos << "." << endl;
    int newPos = model->GetPlayerPosition(playerNumber);
    if (newPos > movedPos) {
        cout << "    But landed on a ladder and moved to " << newPos << "!" << endl;
        if (playerNumber == 0) musicPlayer->PlaySong(LadderSound);
    } else if (newPos < movedPos) {
        cout << "    But landed on a snake and moved to " << newPos  << "!" << endl;
        if (playerNumber == 0) musicPlayer->PlaySong(SnakeSound);
    }
}


void SnakesAndLaddersCLIView::ShowWinner(SnakesAndLaddersModel *model) {
    int winner = model->GetWinner();
    if (winner < 0) cout << "This shouldn't happen but apparently nobody won!" << endl;
    else if (winner == 0) {
        cout << "You Win!!" << endl;
        musicPlayer->PlaySong(WinSound);
    }
    else {
        cout << "Player " << winner + 1 << " Wins!" << endl;
        musicPlayer->PlaySong(LoseSound);
    }
}


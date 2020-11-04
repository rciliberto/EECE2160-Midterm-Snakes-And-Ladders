#include "MusicPlayer/MusicPlayer.h"
#include "SnakesAndLadders/Controller/SnakesAndLaddersCLIController.h"
#include "SnakesAndLadders/Model/SimpleSnakesAndLadders/Board/BoardBuilder.h"
#include "SnakesAndLadders/Model/SimpleSnakesAndLadders/SimpleSnakesAndLadders.h"
#include "SnakesAndLadders/View/SnakesAndLaddersCLIView.h"
#include <iostream>
#include <string>

using namespace std;

void PlaySnakesAndLadders(DE1SoCfpga *de1SoCfpga) {
    int numPlayers;
    string boardSize = "50";

    cout << "Enter Number of Players: ";
    cin >> numPlayers;
    cout << "Enter Board Size (30, default 50, 100): ";
    cin >> boardSize;

    SimpleSnakesAndLadders *model;
    SnakesAndLaddersCLIView *view;
    if (boardSize == "30") {
        model = new SimpleSnakesAndLadders(de1SoCfpga, BoardBuilder::Build10x3Board(), numPlayers);
    } else if (boardSize == "100") {
        model = new SimpleSnakesAndLadders(de1SoCfpga, BoardBuilder::Build10x10Board(), numPlayers);
    } else {
        model = new SimpleSnakesAndLadders(de1SoCfpga, BoardBuilder::Build10x5Board(), numPlayers);
    }

    view = new SnakesAndLaddersCLIView(de1SoCfpga);

    SnakesAndLaddersCLIController controller = SnakesAndLaddersCLIController(model, view);

    controller.Play();

    delete model;
    delete view;
}

void PlayMusicPlayer(DE1SoCfpga *de1SoCfpga) {
    MusicPlayer *musicPlayer = new MusicPlayer(de1SoCfpga);

    musicPlayer->Start();

    delete musicPlayer;
}

void ShowHelp() {
    cout << "help        - Show this menu." << endl;
    cout << "music       - Start the Music Player." << endl;
    cout << "game        - Play Snakes and Ladders." << endl;
    cout << "exit        - Exit the program." << endl;
}

int main() {
    DE1SoCfpga *de1SoCfpga = new DE1SoCfpga();

    cout << "EECE 2160 Midterm Project - Robby Ciliberto:" << endl;
    string command;
    while (command != "exit") {
        cout << "main> ";
        cin >> command;
        if (command == "music") PlayMusicPlayer(de1SoCfpga);
        else if (command == "game") PlaySnakesAndLadders(de1SoCfpga);
        else if (command == "help") ShowHelp();
    }

    delete de1SoCfpga;
    return 0;
}
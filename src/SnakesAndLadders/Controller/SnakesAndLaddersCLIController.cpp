#include "SnakesAndLaddersCLIController.h"
#include <iostream>

using namespace std;

SnakesAndLaddersCLIController::SnakesAndLaddersCLIController(SnakesAndLaddersModel *model,
                                                       SnakesAndLaddersView *view) {
    this->model = model;
    this->view = view;
}
void SnakesAndLaddersCLIController::Play() {
    view->ShowIntroduction();

    while (true) {
        // Move Com Players
        for (int i = 1; i < model->GetNumberOfPlayers(); i++) {
            int pos = model->GetPlayerPosition(i);
            int movement = model->MovePlayer(i);
            view->ShowMove(model, i, pos, movement);
        }
        if(model->IsGameOver()) break;

        cout << endl;
        // Move Human Player
        view->ShowState(model);
        int pos = model->GetPlayerPosition(0);
        int movement = model->MovePlayer(0);
        view->ShowMove(model, 0, pos, movement);
        if(model->IsGameOver()) break;


        view->ClearState();
    }

    cout << endl;
    view->ShowWinner(model);
}
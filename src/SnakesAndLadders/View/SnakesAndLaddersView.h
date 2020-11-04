#ifndef MIDTERM_SNAKESANDLADDERSVIEW_H
#define MIDTERM_SNAKESANDLADDERSVIEW_H

#include "../Model/SnakesAndLaddersModel.h"

class SnakesAndLaddersView {
public:
    virtual void ShowIntroduction() = 0;
    virtual void ClearState() = 0;
    virtual void ShowState(SnakesAndLaddersModel *model) = 0;
    virtual void ShowMove(SnakesAndLaddersModel *model, int playerNumber, int initialPosition, int roll) = 0;
    virtual void ShowWinner(SnakesAndLaddersModel *model) = 0;
};

#endif//MIDTERM_SNAKESANDLADDERSVIEW_H

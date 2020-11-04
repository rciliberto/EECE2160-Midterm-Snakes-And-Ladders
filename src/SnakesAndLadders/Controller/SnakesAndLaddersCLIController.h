#ifndef MIDTERM_SNAKESANDLADDERSCLICONTROLLER_H
#define MIDTERM_SNAKESANDLADDERSCLICONTROLLER_H

#include "../Model/SnakesAndLaddersModel.h"
#include "../View/SnakesAndLaddersView.h"
class SnakesAndLaddersCLIController {
private:
    SnakesAndLaddersModel *model;
    SnakesAndLaddersView *view;
public:
    SnakesAndLaddersCLIController(SnakesAndLaddersModel *model, SnakesAndLaddersView *view);
    void Play();
};

#endif//MIDTERM_SNAKESANDLADDERSCLICONTROLLER_H

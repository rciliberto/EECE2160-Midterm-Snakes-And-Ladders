#ifndef MIDTERM_SNAKESANDLADDERSMODEL_H
#define MIDTERM_SNAKESANDLADDERSMODEL_H

class SnakesAndLaddersModel {
public:
    virtual bool IsGameOver() = 0;
    virtual int GetWinner() = 0;
    virtual int GetNumberOfPlayers() = 0;
    virtual int GetPlayerPosition(int playerNumber) = 0;
    virtual int SnakeLadderDestinationAt(int tile) = 0;
    virtual bool IsSnakeLadderAt(int tile) = 0;

    virtual int MovePlayer(int playerNumber) = 0;
};
#endif//MIDTERM_SNAKESANDLADDERSMODEL_H

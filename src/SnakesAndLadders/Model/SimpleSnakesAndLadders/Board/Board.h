#ifndef MIDTERM_BOARD_H
#define MIDTERM_BOARD_H


#include "SnakeLadder.h"
#include <map>

using namespace std;

class Board {
private:
    int size;
    map<int, SnakeLadder> snakeLadders;
public:
    Board(int size, const map<int, SnakeLadder>& snakeLadders);

    int GetSize();
    bool SnakeLadderAt(int tile);
    int GetSnakeLadderDestinationAt(int tile);
};


#endif//MIDTERM_BOARD_H

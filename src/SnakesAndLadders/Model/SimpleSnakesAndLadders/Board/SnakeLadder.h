#ifndef MIDTERM_SNAKELADDER_H
#define MIDTERM_SNAKELADDER_H


class SnakeLadder {
private:
    int sourceTile;
    int destinationTile;
public:
    SnakeLadder(int sourceTile, int destinationTile);

    int GetSourceTile();
    int GetDestinationTile();
};


#endif//MIDTERM_SNAKELADDER_H

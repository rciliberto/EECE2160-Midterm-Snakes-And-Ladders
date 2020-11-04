#include "BoardBuilder.h"

Board BoardBuilder::Build10x3Board() {
    map<int, SnakeLadder> snakeLadders;

    // Build Ladders
    snakeLadders.insert(make_pair(4, SnakeLadder(4, 16)));
    snakeLadders.insert(make_pair(8, SnakeLadder(8, 14)));
    snakeLadders.insert(make_pair(9, SnakeLadder(9, 11)));
    snakeLadders.insert(make_pair(18, SnakeLadder(18, 22)));

    // Build Snakes
    snakeLadders.insert(make_pair(17, SnakeLadder(17, 2)));
    snakeLadders.insert(make_pair(23, SnakeLadder(23, 2)));
    snakeLadders.insert(make_pair(24, SnakeLadder(24, 7)));
    snakeLadders.insert(make_pair(27, SnakeLadder(27, 16)));
    snakeLadders.insert(make_pair(29, SnakeLadder(29, 14)));

    return Board(30,snakeLadders);
}

Board BoardBuilder::Build10x5Board() {
    map<int, SnakeLadder> snakeLadders;

    // Build Ladders
    snakeLadders.insert(make_pair(4, SnakeLadder(4, 25)));
    snakeLadders.insert(make_pair(8, SnakeLadder(8, 34)));
    snakeLadders.insert(make_pair(12, SnakeLadder(12, 31)));

    // Build Snakes
    snakeLadders.insert(make_pair(36, SnakeLadder(36, 17)));
    snakeLadders.insert(make_pair(41, SnakeLadder(41, 3)));
    snakeLadders.insert(make_pair(44, SnakeLadder(44, 14)));
    snakeLadders.insert(make_pair(47, SnakeLadder(47, 32)));

    return Board(50, snakeLadders);
}

Board BoardBuilder::Build10x10Board() {
    map<int, SnakeLadder> snakeLadders;

    // Build Ladders
    snakeLadders.insert(make_pair(4, SnakeLadder(4, 56)));
    snakeLadders.insert(make_pair(12, SnakeLadder(12, 50)));
    snakeLadders.insert(make_pair(14, SnakeLadder(14, 55)));
    snakeLadders.insert(make_pair(22, SnakeLadder(22, 58)));
    snakeLadders.insert(make_pair(41, SnakeLadder(41, 79)));
    snakeLadders.insert(make_pair(54, SnakeLadder(54, 88)));

    // Build Snakes
    snakeLadders.insert(make_pair(27, SnakeLadder(27, 10)));
    snakeLadders.insert(make_pair(37, SnakeLadder(37, 3)));
    snakeLadders.insert(make_pair(47, SnakeLadder(47, 16)));
    snakeLadders.insert(make_pair(77, SnakeLadder(77, 32)));
    snakeLadders.insert(make_pair(94, SnakeLadder(94, 71)));
    snakeLadders.insert(make_pair(96, SnakeLadder(96, 42)));

    return Board(100,snakeLadders);
}
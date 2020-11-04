#ifndef MIDTERM_BOARDBUILDER_H
#define MIDTERM_BOARDBUILDER_H

#include "Board.h"

class BoardBuilder {
public:
    static Board Build10x3Board();
    static Board Build10x5Board();
    static Board Build10x10Board();
};


#endif//MIDTERM_BOARDBUILDER_H

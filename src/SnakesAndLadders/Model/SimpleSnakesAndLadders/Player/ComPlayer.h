#ifndef MIDTERM_COMPLAYER_H
#define MIDTERM_COMPLAYER_H

#include "Player.h"
class ComPlayer : public Player {
public:
    ComPlayer(DE1SoCfpga *de1SoCfpga);

    // Player methods
    int MakeMove();
};


#endif//MIDTERM_COMPLAYER_H

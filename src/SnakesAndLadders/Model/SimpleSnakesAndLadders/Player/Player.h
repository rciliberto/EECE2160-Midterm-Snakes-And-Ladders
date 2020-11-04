#ifndef MIDTERM_PLAYER_H
#define MIDTERM_PLAYER_H

#include "../../../../MusicPlayer/MusicPlayer.h"
#include <DE1SoCfpga/Device/PushButton.h>

class Player {
private:
    PushButton *button;

protected:
    int position;

public:
    Player(DE1SoCfpga *de1SoCfpga);

    int GetPosition();
    virtual int MakeMove();
    void SetPosition(int tile);
};
#endif//MIDTERM_PLAYER_H

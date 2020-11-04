#ifndef MIDTERM_SNAKESANDLADDERSCLIVIEW_H
#define MIDTERM_SNAKESANDLADDERSCLIVIEW_H


#include "../../MusicPlayer/MusicPlayer.h"
#include "SnakesAndLaddersView.h"

class SnakesAndLaddersCLIView : public SnakesAndLaddersView {
private:
    MusicPlayer *musicPlayer;
public:
    SnakesAndLaddersCLIView(DE1SoCfpga *de1SoCfpga);
    ~SnakesAndLaddersCLIView();

    void ShowIntroduction();
    void ClearState();
    void ShowState(SnakesAndLaddersModel *model);
    void ShowMove(SnakesAndLaddersModel *model, int playerNumber, int initialPosition, int roll);
    void ShowWinner(SnakesAndLaddersModel *model);
};


#endif//MIDTERM_SNAKESANDLADDERSCLIVIEW_H

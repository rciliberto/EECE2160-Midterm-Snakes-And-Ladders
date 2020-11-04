#ifndef MIDTERM_MUSICPLAYER_H
#define MIDTERM_MUSICPLAYER_H

#include <DE1SoCfpga/DE1SoCfpga.h>
#include <DE1SoCfpga/Device/Speaker.h>
#include <iostream>

using namespace std;

class MusicPlayer {
private:
    Speaker *speaker;

    Tone ToTone(const string& tone);

    void DisplayInstructions();
    void DisplayMenu();
    string ParseInput();

public:
    MusicPlayer(DE1SoCfpga *de1SoCfpga);
    ~MusicPlayer();

    void PlaySong(const string& songString);
    void Start();
};


#endif//MIDTERM_MUSICPLAYER_H

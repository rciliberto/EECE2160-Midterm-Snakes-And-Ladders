#include "MusicPlayer.h"
#include <vector>
#include <string>
#include <sstream>

string GFF = "A5.18,D5.18,AsBf4.18,G4.18,G5.18,D5.18,AsBf4.18,G4.18,FsGf5.18,D5.18,AsBf4.18,G4.18,G5.18,D5.18,AsBf4.18,G4.18,"
             "G5.18,C5.18,A4.18,F4.18,F5.18,C5.18,A4.18,F4.18,E5.18,C5.18,A4.18,F4.18,F5.18,C5.18,A4.18,F4.18,"
             "F5.18,AsBf4.18,G4.18,E4.18,E5.18,AsBf4.18,G4.18,E4.18,DsEf5.18,AsBf4.18,G4.18,E4.18,E5.18,AsBf4.18,G4.18,E4.18,"
             "E5.18,A4.18,F4.18,D4.18,D5.18,A4.18,F4.18,D4.18,CsDf5.18,A4.18,F4.18,D4.18,D5.18,A4.18,F4.18,D4.18,"
             "A5.18,D5.18,AsBf4.18,G4.18,G5.18,D5.18,AsBf4.18,G4.18,FsGf5.18,D5.18,AsBf4.18,G4.18,G5.18,D5.18,AsBf4.18,G4.18,"
             "AsBf5.18,DsEf5.18,C5.18,FsGf4.18,A5.18,DsEf5.18,C5.18,FsGf4.18,GsAf5.18,DsEf5.18,C5.18,FsGf4.18,A5.18,DsEf5.18,C5.18,FsGf4.18,"
             "C6.18,D5.18,AsBf4.18,G4.18,AsBf5.18,D5.18,AsBf4.18,G4.18,A5.18,D5.18,AsBf4.18,G4.18,AsBf5.18,D5.18,AsBf4.18,G4.18,"
             "A5.18,AsBf4.18,G4.18,E4.18,G5.18,AsBf4.18,G4.18,E4.18,F5.18,AsBf4.18,G4.18,E4.18,E5.18,AsBf4.18,G4.18,E4.18";

MusicPlayer::MusicPlayer(DE1SoCfpga *de1SoCfpga) {
    this->speaker = new Speaker(de1SoCfpga, JP1, 0);
}
MusicPlayer::~MusicPlayer() {
    delete this->speaker;
}

void MusicPlayer::Start() {
    DisplayInstructions();

    string command;
    do {
        DisplayMenu();
        command = ParseInput();
    } while (command != "exit");
}

Tone MusicPlayer::ToTone(const string& tone) {
    if (tone == "C4") return C4;
    if (tone == "CsDf4") return CsDf4;
    if (tone == "D4") return D4;
    if (tone == "DsEf4") return DsEf4;
    if (tone == "E4") return E4;
    if (tone == "F4") return F4;
    if (tone == "FsGf4") return FsGf4;
    if (tone == "G4") return G4;
    if (tone == "GsAf4") return GsAf4;
    if (tone == "A4") return A4;
    if (tone == "AsBf4") return AsBf4;
    if (tone == "B4") return B4;
    if (tone == "C5") return C5;
    if (tone == "CsDf5") return CsDf5;
    if (tone == "D5") return D5;
    if (tone == "DsEf5") return DsEf5;
    if (tone == "E5") return E5;
    if (tone == "F5") return F5;
    if (tone == "FsGf5") return FsGf5;
    if (tone == "G5") return G5;
    if (tone == "GsAf5") return GsAf5;
    if (tone == "A5") return A5;
    if (tone == "AsBf5") return AsBf5;
    if (tone == "B5") return B5;
    if (tone == "C6") return C6;
    else return C4;
}

void MusicPlayer::DisplayInstructions() {
    cout << "Music Player Commands:" << endl;
    cout << "help               - Display this menu" << endl;
    cout << "song               - Play the song \'Great Fairy Shrine\'" << endl;
    cout << "exit               - Exit the Music Player" << endl;
    cout << "play               - Play a song from a Music String" << endl;
    cout << endl;
    cout << "A Music String is in the form \'note.duration,...,note.duration>\'" << endl;
    cout << "A duration is the number of centiseconds (1/100 seconds) to play the note for" << endl;
    cout << "A note is any of the following numbers representing a note:" << endl;
    cout << "C4" << endl;
    cout << "   CsDf4" << endl;
    cout << "D4" << endl;
    cout << "   DsEf4" << endl;
    cout << "E4" << endl;
    cout << "F4" << endl;
    cout << "   FsGf4" << endl;
    cout << "G4" << endl;
    cout << "   GsAf4" << endl;
    cout << "A4" << endl;
    cout << "   AsBf4" << endl;
    cout << "B4" << endl;
    cout << "C5" << endl;
    cout << "   CsDf5" << endl;
    cout << "D5" << endl;
    cout << "   DsEf5" << endl;
    cout << "E5" << endl;
    cout << "F5" << endl;
    cout << "   FsGf5" << endl;
    cout << "G5" << endl;
    cout << "   GsAf5" << endl;
    cout << "A5" << endl;
    cout << "   AsBf5" << endl;
    cout << "B5" << endl;
    cout << "C6" << endl;
}

void MusicPlayer::DisplayMenu() {
    cout << endl << "music> ";
}

string MusicPlayer::ParseInput() {
    string command;
    cin >> command;

    //string arguments = tokens[1];
    if (command == "help" ) {
        DisplayInstructions();
    }
    else if (command == "song") {
        PlaySong(GFF);
    }
    else if (command == "play") {
        string song;
        cout << "Enter Song String:" << endl << "> ";
        cin >> song;
        PlaySong(song);
    }

    return command;
}

void MusicPlayer::PlaySong(const string& songString) {
    vector<string> tokens;

    stringstream ss(songString);
    string temp;

    while(getline(ss, temp, ',')) {
        tokens.push_back(temp);
    }

    for(int i = 0; i < tokens.size(); i++) {
        vector<string> tokens2;

        stringstream ss2(tokens[i]);
        string temp2;

        while(getline(ss2, temp2, '.')) {
            tokens2.push_back(temp2);
        }

        if (tokens2.size() == 2) {
            int length;
            istringstream(tokens2[1]) >> length;

            speaker->GenerateTone(ToTone(tokens2[0]), length);
        }
    }
}
#ifndef DE1SOCFPGA_SPEAKER_H
#define DE1SOCFPGA_SPEAKER_H

#include <DE1SoCfpga/Device/ExpansionPort.h>
#include <DE1SoCfpga/Device/MPCoreTimer.h>

enum Tone { // Values are count-low cycles
    C4 = 382262,
    CsDf4 = 360776,
    D4 = 340518,
    DsEf4 = 321409,
    E4 = 303370,
    F4 = 286344,
    FsGf4 = 270277,
    G4 = 255102,
    GsAf4 = 240789,
    A4 = 227272,
    AsBf4 = 214518,
    B4 = 202478,
    C5 = 191113,
    CsDf5 = 180384,
    D5 = 170262,
    DsEf5 = 160707,
    E5 = 151685,
    F5 = 143172,
    FsGf5 = 135136,
    G5 = 127552,
    GsAf5 = 120393,
    A5 = 113636,
    AsBf5 = 107258,
    B5 = 101238,
    C6 = 95556
};

class Speaker {
private:
    ExpansionPort *jpx;
    MPCoreTimer *timer;
    int pin;

public:
    Speaker(DE1SoCfpga *de1SoCfpga, JPX jpx, int pin);
    ~Speaker();

    void GenerateTone(Tone tone, int lengthDs);
};

#endif//DE1SOCFPGA_SPEAKER_H

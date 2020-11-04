#include <DE1SoCfpga/Device/Switch.h>

Switch::Switch(DE1SoCfpga *de1SoCfpga) : Device(de1SoCfpga) {}
Switch::~Switch() {}

int Switch::ReadAllSwitches() {
    return de1SoCfpga->RegisterRead(SW_BASE);
}

int Switch::Read1Switch(int switchNum) {
    // get the current state of the LEDs
    int swState = de1SoCfpga->RegisterRead(SW_BASE);
    int mask = 1;
    return (swState >> switchNum) & mask;
}
#include <DE1SoCfpga/Device/PushButton.h>

PushButton::PushButton(DE1SoCfpga *de1SoCfpga) : Device(de1SoCfpga) {}
PushButton::~PushButton() {}

int PushButton::PushButtonGet() {
    return de1SoCfpga->RegisterRead(KEY_BASE);
}
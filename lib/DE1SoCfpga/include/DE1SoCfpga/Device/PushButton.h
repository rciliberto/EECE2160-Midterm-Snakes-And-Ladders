#ifndef DE1SOCFPGA_PUSHBUTTON_H
#define DE1SOCFPGA_PUSHBUTTON_H

#include <DE1SoCfpga/Device/Device.h>

const unsigned int KEY_BASE = 0x00000050;      // Push buttons offset

class PushButton : Device {
public:
    PushButton(DE1SoCfpga *de1SoCfpga);
    ~PushButton();

    /**
     * Get the values from the push buttons.
     * @param pBase Base address returned by 'mmap'
     * @return The value of the push button register.
     */
    int PushButtonGet();
};
#endif//DE1SOCFPGA_PUSHBUTTON_H

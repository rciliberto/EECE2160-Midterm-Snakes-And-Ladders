#ifndef DE1SOCFPGA_SWITCH_H
#define DE1SOCFPGA_SWITCH_H

#include <DE1SoCfpga/Device/Device.h>
#include <DE1SoCfpga/DE1SoCfpga.h>

const unsigned int SW_BASE = 0x00000040;       // Switches offset

class Switch : Device {
private:
    DE1SoCfpga *de1SoCfpga;

public:
    Switch(DE1SoCfpga *de1SoCfpga1);
    ~Switch();

    /** Reads all the switches and returns their value in a single integer.
     * @param pBase Base address for general-purpose I/O
     * @returnA value that represents the value of the switches
     */
    int ReadAllSwitches();

    /** Reads the value of a switch.
     * -Uses base address of I/O
     * @param pBase Base address returned by 'mmap'
     * @param switchNumSwitch number(0 to 9)* @returnSwitch value read
     */
    int Read1Switch(int switchNum);
};
#endif//DE1SOCFPGA_SWITCH_H

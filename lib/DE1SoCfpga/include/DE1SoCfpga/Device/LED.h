#ifndef DE1SOCFPGA_LED_H
#define DE1SOCFPGA_LED_H

#include <DE1SoCfpga/Device/Device.h>

const unsigned int LEDR_BASE = 0x00000000;     // Leds offset

class LED : Device {
public:
    LED(DE1SoCfpga *de1SoCfpga);
    ~LED();

    /**
     * Writes the value to the LED Register of the DE1SoCfpga.
     * @param value The value to set the register to.
     */
    void WriteAllLeds(int value);

    /** Changes the state of an LED (ON or OFF).
     *  @param pBaseBase address returned by 'mmap'
     *  @param ledNumLED number (0 to 9)
     *  @param stateState to change to (ON or OFF)
   */
    void Write1Led(int ledNum, int state);
};
#endif//DE1SOCFPGA_LED_H

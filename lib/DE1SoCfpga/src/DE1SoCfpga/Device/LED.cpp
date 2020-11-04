#include <DE1SoCfpga/BitOperations.h>
#include <DE1SoCfpga/Device/LED.h>

LED::LED(DE1SoCfpga *de1SoCfpga) : Device(de1SoCfpga) {}
LED::~LED() {}

/**
 * Writes the value to the LED Register of the DE1SoCfpga.
 * @param value The value to set the register to.
 */
void LED::WriteAllLeds(int value) {
    de1SoCfpga->RegisterWrite(LEDR_BASE, value);
}

/** Changes the state of an LED (ON or OFF).
 *  @param pBaseBase address returned by 'mmap'
 *  @param ledNumLED number (0 to 9)
 *  @param stateState to change to (ON or OFF)
*/
void LED::Write1Led(int ledNum, int state) {
    // get the current state of the LEDs
    int ledState = de1SoCfpga->RegisterRead(LEDR_BASE);

    CHANGE_BIT(ledState, ledNum, state);

    de1SoCfpga->RegisterWrite(LEDR_BASE, ledState);
}
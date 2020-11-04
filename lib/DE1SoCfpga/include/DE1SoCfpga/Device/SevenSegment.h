#ifndef DE1SOCFPGA_SEVENSEGMENT_H
#define DE1SOCFPGA_SEVENSEGMENT_H

#include <DE1SoCfpga/Device/Device.h>

const unsigned int HEX3_HEX0_BASE = 0x00000020;// HEX Reg1 offset
const unsigned int HEX5_HEX4_BASE = 0x00000030;// HEX Reg2 offset

// 7-Segment values
const int bit_values[16] = {
        0x3F,// 0
        0x06,// 1
        0x5B,// 2
        0x4F,// 3
        0x66,// 4
        0x6D,// 5
        0x7D,// 6
        0x07,// 7
        0x7F,// 8
        0x6F,// 9
        0x77,// a
        0x7C,// b
        0x39,// c
        0x5E,// d
        0x79,// e
        0x71 // f
};

/**
 * A class that allows the user to interface with the 7-segment displays on the
 * DE1SoCfpga.
 */
class SevenSegment : Device {
private:
    unsigned int reg0_hexValue;
    unsigned int reg1_hexValue;

    /**
     * Takes the values in reg0_hexValue and reg1_hexValue and applies it to the
     * memory-mapped register of the DE1SoCfpga.
     */
    void UpdateDisplays();

    /**
     * Updates the values of reg0_hexValue and reg1_hexValue according to the
     * index of a display and raw value the user would like to set (0x00 - 0xFF).
     * Does NOT update the display.
     * @param index The index of the display.
     * @param value The value to update the display to.
     */
    void Hex_SetRaw(int index, int value);

public:
    SevenSegment(DE1SoCfpga *de1SoCfpga);
    ~SevenSegment();

    /**
     * Updates the 7-segment displays, clearing all values.
     */
    void Hex_ClearAll();

    /**
     * Updates a specific 7-segment display, clearing it.
     * @param index The index of the display to clear.
     */
    void Hex_ClearSpecific(int index);

    /**
     * Updates the values of a specific 7-segment display according to the index
     * of a display and hexadecimal number the user would like to set (0x0 - 0xF).
     * Updates the display.
     * @param index The index of the display.
     * @param value The value to update the display to.
     */
    void Hex_WriteSpecific(int index, int value);

    /**
     * Updates all 7-segment displays. Displays the last 24 bits of the integer in
     * hexadecimal across all displays.
     * @param number The number to display in hex on the displays.
     */
    void Hex_WriteNumber(int number);


    /**
     * Updates the values of reg0_hexValue and reg1_hexValue according to the
     * index of a display and raw value the user would like to set (0x00 - 0xFF).
     * Updates the display.
     * @param index The index of the display.
     * @param value The value to update the display to.
     */
    void Hex_WriteSpecificRaw(int index, int value);

    /**
     * Shifts the values of one display to the left going from display 0 to
     * display 5. Updates the displays.
     */
    void Hex_ShiftLeft();
};

#endif//DE1SOCFPGA_SEVENSEGMENT_H

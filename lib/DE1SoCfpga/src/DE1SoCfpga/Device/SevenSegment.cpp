#include <DE1SoCfpga/Device/SevenSegment.h>
#include <iostream>

using namespace std;

// Private:
void SevenSegment::UpdateDisplays() {
    de1SoCfpga->RegisterWrite(HEX3_HEX0_BASE, reg0_hexValue);
    de1SoCfpga->RegisterWrite(HEX5_HEX4_BASE, reg1_hexValue);
}

void SevenSegment::Hex_SetRaw(int index, int value) {
    if (index > 5 || index < 0) {
        cout << "Attempted to write a value to an invalid display index: ";
        cout << value << endl;
        cout << "Valid indices are 0-5" << endl;
        return;
    }

    if (value > 0xFF || value < 0x00) {
        cout << "Attempted to write an invalid value to a single display: ";
        cout << value << endl;
        return;
    }

    // Clear the bits at index
    unsigned int mask;
    if (index < 4) {
        mask = ~(0xFF << (index * 4) * 2);
        reg0_hexValue &= mask;
    } else {
        mask = ~(0xFF << ((index - 4) * 4) * 2);
        reg1_hexValue &= mask;
    }

    // Set value at index
    if (index < 4) {
        mask = value << (index * 4) * 2;
        reg0_hexValue |= mask;
    } else {
        mask = value << ((index - 4) * 4) * 2;
        reg1_hexValue |= mask;
    }
}

// public:
SevenSegment::SevenSegment(DE1SoCfpga *de1SoCfpga) : Device(de1SoCfpga) {
    reg0_hexValue = 0x00000000;
    reg1_hexValue = 0x00000000;
}

SevenSegment::~SevenSegment() {
    Hex_ClearAll();
}

void SevenSegment::Hex_ClearAll() {
    reg0_hexValue = 0x00000000;
    reg1_hexValue = 0x00000000;
    UpdateDisplays();
}

void SevenSegment::Hex_ClearSpecific(int index) {
    Hex_SetRaw(index, 0x00);
    UpdateDisplays();
}

void SevenSegment::Hex_WriteSpecific(int index, int value) {
    if (value > 0xF || value < 0x0) {
        cout << "Attempted to write an invalid number to a single display: ";
        cout << value << endl;
        return;
    }

    Hex_SetRaw(index, bit_values[value]);
    UpdateDisplays();
}

void SevenSegment::Hex_WriteNumber(int number) {
    Hex_ClearAll();

    // Get each hex value in the number (that can be displayed)
    int hexValue[6];
    for (int i = 0; i < 6; i++) {
        int mask = 0xF << i * 4;
        int pulledNumber = (number & mask) >> i * 4;
        hexValue[i] = pulledNumber;
    }

    //    for (int i = 0; i < 6; i++) {
    //      Hex_WriteSpecific(i, hexValue[i]);
    //    }

    // Apply it to the registers
    // Reg0
    for (int i = 0; i < 4; i++) {
        reg0_hexValue |= (bit_values[hexValue[i]] << i * 8);
    }
    // Reg1
    for (int i = 4; i < 6; i++) {
        reg1_hexValue |= (bit_values[hexValue[i]] << (i - 4) * 8);
    }

    UpdateDisplays();
}

void SevenSegment::Hex_WriteSpecificRaw(int index, int value) {
    if (index > 5 || index < 0) {
        cout << "Attempted to write a value to an invalid display index: ";
        cout << value << endl;
        cout << "Valid indices are 0-5" << endl;
        return;
    }

    if (value > 0xFF || value < 0x0) {
        cout << "Attempted to write an invalid number to a single display: ";
        cout << value << endl;
        return;
    }

    Hex_SetRaw(index, value);
    UpdateDisplays();
}

void SevenSegment::Hex_ShiftLeft() {
    reg1_hexValue <<= 8;
    int lastValue = reg0_hexValue >> 3 * 8;
    reg1_hexValue |= lastValue;

    reg0_hexValue <<= 8;
}
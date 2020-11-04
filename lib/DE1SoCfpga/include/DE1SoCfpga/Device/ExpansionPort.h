#ifndef DE1SOCFPGA_EXPANSIONPORT_H
#define DE1SOCFPGA_EXPANSIONPORT_H

#include <DE1SoCfpga/Device/Device.h>

const unsigned int JP1_BASE_OFFSET = 0x00000060;        //JP1 offset
const unsigned int JP2_BASE_OFFSET = 0x00000070;        //JP2 offset

const unsigned int JPX_DIRECTION_OFFSET = 0x00000004;   //Direction offset from JP

enum JPX {
    JP1,
    JP2
};

class ExpansionPort : Device {
private:
    int JPX_BASE;

public:
    ExpansionPort(DE1SoCfpga *de1SoCfpga, JPX jpx);
    ~ExpansionPort();

    int GetDirection_RAW();
    int GetData_RAW();
    void SetDirection_RAW(int value);
    void SetData_RAW(int value);

    void ClearData();
    void ClearDirection();

    bool GetDirection(int pin);
    bool GetData(int pin);
    void SetDirection(int pin, bool direction);
    void SetData(int pin, bool value);

};


#endif//DE1SOCFPGA_EXPANSIONPORT_H

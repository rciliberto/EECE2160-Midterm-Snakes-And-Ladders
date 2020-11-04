#ifndef DE1SOCFPGA_DEVICE_H
#define DE1SOCFPGA_DEVICE_H

#include <DE1SoCfpga/DE1SoCfpga.h>

class Device {
protected:
    DE1SoCfpga *de1SoCfpga;

public:
    Device(DE1SoCfpga *de1SoCfpga);
};
#endif//DE1SOCFPGA_DEVICE_H

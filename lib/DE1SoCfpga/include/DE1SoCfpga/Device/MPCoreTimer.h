#ifndef DE1SOCFPGA_MPCORETIMER_H
#define DE1SOCFPGA_MPCORETIMER_H

#include <DE1SoCfpga/Device/Device.h>

//0xFFFEC600 -0xFF200000 = 0xDEC600
const unsigned int MPCORE_PRIV_TIMER_LOAD_OFFSET = 0xDEC600;     //  Points  to  LOAD Register
const unsigned int MPCORE_PRIV_TIMER_COUNTER_OFFSET = 0xDEC604;  //  Points  to COUNTER Register
const unsigned int MPCORE_PRIV_TIMER_CONTROL_OFFSET = 0xDEC608;  //  Points  to CONTROL Register
const unsigned int MPCORE_PRIV_TIMER_INTERRUPT_OFFSET = 0xDEC60C;//  Points  to INTERRUPT Register

class MPCoreTimer : Device {
private:
    int oldTimeout;
    int oldCounter;
    int oldControl;
    int oldInterrupt;

public:
    int timerDelay;
    int controlFlags;

    MPCoreTimer(DE1SoCfpga *de1SoCfpga);
    ~MPCoreTimer();

    void SetTimeout(int cycles);

    void SetControlFlags(int value);

    int GetCounterValue();

    int GetInterruptValue();

    void ResetTimerInterrupt();
};

#endif//DE1SOCFPGA_MPCORETIMER_H

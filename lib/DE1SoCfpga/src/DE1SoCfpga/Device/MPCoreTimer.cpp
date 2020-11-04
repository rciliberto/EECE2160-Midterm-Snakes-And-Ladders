#include <DE1SoCfpga/Device/MPCoreTimer.h>

MPCoreTimer::MPCoreTimer(DE1SoCfpga *de1SoCfpga) : Device(de1SoCfpga) {
    oldTimeout = de1SoCfpga->RegisterRead(MPCORE_PRIV_TIMER_LOAD_OFFSET);
    oldCounter = de1SoCfpga->RegisterRead(MPCORE_PRIV_TIMER_COUNTER_OFFSET);
    oldControl = de1SoCfpga->RegisterRead(MPCORE_PRIV_TIMER_CONTROL_OFFSET);
    oldInterrupt = de1SoCfpga->RegisterRead(MPCORE_PRIV_TIMER_INTERRUPT_OFFSET);
}
MPCoreTimer::~MPCoreTimer() {
    de1SoCfpga->RegisterWrite(MPCORE_PRIV_TIMER_LOAD_OFFSET, oldTimeout);
    de1SoCfpga->RegisterWrite(MPCORE_PRIV_TIMER_COUNTER_OFFSET, oldCounter);
    de1SoCfpga->RegisterWrite(MPCORE_PRIV_TIMER_CONTROL_OFFSET, oldControl);
    de1SoCfpga->RegisterWrite(MPCORE_PRIV_TIMER_INTERRUPT_OFFSET, oldInterrupt);
}

void MPCoreTimer::SetTimeout(int cycles) {
    this->timerDelay = cycles;
    this->de1SoCfpga->RegisterWrite(MPCORE_PRIV_TIMER_LOAD_OFFSET, cycles);
}

void MPCoreTimer::SetControlFlags(int value) {
    this->controlFlags = value;
    this->de1SoCfpga->RegisterWrite(MPCORE_PRIV_TIMER_CONTROL_OFFSET, value);
}

int MPCoreTimer::GetCounterValue() {
    return this->de1SoCfpga->RegisterRead(MPCORE_PRIV_TIMER_COUNTER_OFFSET);
}

int MPCoreTimer::GetInterruptValue() {
    return this->de1SoCfpga->RegisterRead(MPCORE_PRIV_TIMER_INTERRUPT_OFFSET);
}

void MPCoreTimer::ResetTimerInterrupt() {
    this->de1SoCfpga->RegisterWrite(MPCORE_PRIV_TIMER_INTERRUPT_OFFSET, 1);
}
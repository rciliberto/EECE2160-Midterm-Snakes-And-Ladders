#include <DE1SoCfpga/Device/Speaker.h>
#include <iostream>

Speaker::Speaker(DE1SoCfpga *de1SoCfpga, JPX jpx, int pin) {
    this->jpx = new ExpansionPort(de1SoCfpga, jpx);
    this->pin = pin;
    this->jpx->SetDirection(pin, 1);

    this->timer = new MPCoreTimer(de1SoCfpga);
    timer->SetTimeout(0);
    timer->SetControlFlags(0b00);
}

Speaker::~Speaker() {
    delete this->timer;
    delete this->jpx;
}

void Speaker::GenerateTone(Tone tone, int lengthCs) {
    int countLow = tone;

    double cyclesPerCs = 2000000; // cycles per 1 Centisecond
    double lengthClockCycles = cyclesPerCs * lengthCs; // 20000 cycles = 1 centisecond (0.01s)

    int toneCycles = (int)(lengthClockCycles / countLow);

    timer->SetTimeout(countLow);
    timer->SetControlFlags(0b11);

    bool toggle = 0;
    int cycles = 0;
    while (cycles < toneCycles) {
        if (this->timer->GetInterruptValue() != 0) {
            // reset timer flag bit
            this->timer->ResetTimerInterrupt();

            this->jpx->SetData(0, toggle);
            toggle = !toggle;
            cycles++;
        }
    }

}
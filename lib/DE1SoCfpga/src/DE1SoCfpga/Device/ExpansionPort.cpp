#include <DE1SoCfpga/BitOperations.h>
#include <DE1SoCfpga/Device/ExpansionPort.h>

ExpansionPort::ExpansionPort(DE1SoCfpga *de1SoCfpga, JPX jpx) : Device(de1SoCfpga) {
    switch (jpx) {
        case JP1:
            JPX_BASE = JP1_BASE_OFFSET;
            break;
        case JP2:
            JPX_BASE = JP2_BASE_OFFSET;
            break;
    }

    this->ClearData();
    this->ClearDirection();
}

ExpansionPort::~ExpansionPort() {
    this->ClearData();
    this->ClearDirection();
}

int ExpansionPort::GetDirection_RAW() {
    return de1SoCfpga->RegisterRead(JPX_BASE + JPX_DIRECTION_OFFSET);
}

int ExpansionPort::GetData_RAW() {
    return de1SoCfpga->RegisterRead(JPX_BASE);
}

void ExpansionPort::SetDirection_RAW(int value) {
    de1SoCfpga->RegisterWrite(JPX_BASE + JPX_DIRECTION_OFFSET, value);
}

void ExpansionPort::SetData_RAW(int value) {
    de1SoCfpga->RegisterWrite(JPX_BASE, value);
}


void ExpansionPort::ClearData() {
    this->SetData_RAW(0);
}

void ExpansionPort::ClearDirection() {
    this->SetDirection_RAW(0);
}


bool ExpansionPort::GetDirection(int pin) {
    int directions = GetDirection_RAW();
    return GET_BIT(directions, pin);
}

bool ExpansionPort::GetData(int pin) {
    int data = GetData_RAW();
    return GET_BIT(data, pin);
}

void ExpansionPort::SetDirection(int pin, bool direction) {
    int directions = GetDirection_RAW();
    CHANGE_BIT(directions, pin, direction);
    SetDirection_RAW(directions);
}
void ExpansionPort::SetData(int pin, bool value) {
    int data = GetData_RAW();
    CHANGE_BIT(data, pin, value);
    SetData_RAW(data);
}


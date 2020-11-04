# CMake version
cmake_minimum_required(VERSION 2.8.7)

set(PUBLIC_HEADERS
        include/DE1SoCfpga/DE1SoCfpga.h
        include/DE1SoCfpga/Device/Device.h
        include/DE1SoCfpga/Device/ExpansionPort.h
        include/DE1SoCfpga/Device/LED.h
        include/DE1SoCfpga/Device/MPCoreTimer.h
        include/DE1SoCfpga/Device/PushButton.h
        include/DE1SoCfpga/Device/SevenSegment.h
        include/DE1SoCfpga/Device/Switch.h include/DE1SoCfpga/Device/Speaker.h)

set(PUBLIC_SOURCES
        src/DE1SoCfpga/DE1SoCfpga.cpp
        src/DE1SoCfpga/Device/Device.cpp
        src/DE1SoCfpga/Device/ExpansionPort.cpp
        src/DE1SoCfpga/Device/LED.cpp
        src/DE1SoCfpga/Device/MPCoreTimer.cpp
        src/DE1SoCfpga/Device/PushButton.cpp
        src/DE1SoCfpga/Device/SevenSegment.cpp
        src/DE1SoCfpga/Device/Switch.cpp src/DE1SoCfpga/Device/Speaker.cpp)

set(PRIVATE_CLASSES src/DE1SoCfpga/BitOperations.h)

set(LIBRARY_TYPE STATIC)

add_library(DE1SoCfpga ${LIBRARY_TYPE} ${PUBLIC_HEADERS} ${PUBLIC_SOURCES} ${PRIVATE_CLASSES})

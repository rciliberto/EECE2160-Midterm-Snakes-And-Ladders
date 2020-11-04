#include <DE1SoCfpga/DE1SoCfpga.h>
#include <fcntl.h>
#include <iostream>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

using namespace std;

DE1SoCfpga::DE1SoCfpga() {
    // Open /dev/mem to give access to physical addresses
    fd = open("/dev/mem", (O_RDWR | O_SYNC));
    if (fd == -1) {//  check for errors in opening /dev/mem
        cout << "ERROR: could not open /dev/mem..." << endl;
        exit(1);
    }

    // Get a mapping from physical addresses to virtual addresses
    // void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
    char *virtual_base = (char *) mmap(NULL, LW_BRIDGE_SPAN, (PROT_READ | PROT_WRITE), MAP_SHARED, fd, LW_BRIDGE_BASE);
    if (virtual_base == MAP_FAILED) {// check for errors

        cout << "ERROR: mmap() failed..." << endl;
        close(fd);// close memory before exiting
        exit(1);  // Returns 1 to the operating system;
    }

    pBase = virtual_base;
}

DE1SoCfpga::~DE1SoCfpga() {
    if (munmap(pBase, LW_BRIDGE_SPAN) != 0) {
        cout << "ERROR: munmap() failed..." << endl;
        exit(1);
    }

    close(fd);// close memory
}

void DE1SoCfpga::RegisterWrite(unsigned int reg_offset, int value) {
    *(volatile unsigned int *) (pBase + reg_offset) = value;
}

int DE1SoCfpga::RegisterRead(unsigned int reg_offset) {
    return *(volatile unsigned int *) (pBase + reg_offset);
}
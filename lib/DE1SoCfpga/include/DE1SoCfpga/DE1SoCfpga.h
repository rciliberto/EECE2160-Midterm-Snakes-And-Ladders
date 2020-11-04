#ifndef DE1SOCFPGA_DE1SOCFPGA_H
#define DE1SOCFPGA_DE1SOCFPGA_H

// Physical base address of FPGA Device
const unsigned int LW_BRIDGE_BASE = 0xFF200000;// Base offset

// Length of memory-mapped IO window
const unsigned int LW_BRIDGE_SPAN = 0x00DEC700;// Address map size

/**
 * A class that allows for the interface of the DE1SoCfpga. Lets you write and
 * read from memory-mapped registers.
 */
class DE1SoCfpga {
public:
    char *pBase;
    int fd;

    /**
      * Initialize general-purpose I/O.
      *  - Opens access to physical memory /dev/mem
      *  - Maps memory into virtual address space
      */
    DE1SoCfpga();

    /**
     * Close general-purpose I/O.
     *
     * @param pBase	Virtual address where I/O was mapped.
     * @param fd	File descriptor previously returned by 'open'.
     */
    ~DE1SoCfpga();

    /**
     * Write a 4-byte value at the specified general-purpose I/O location.
     *
     * @param pBase		Base address returned by 'mmap'.
     * @parem offset	Offset where device is mapped.
     * @param value	Value to be written.
     */
    void RegisterWrite(unsigned int reg_offset, int value);

    /**
     * Read a 4-byte value from the specified general-purpose I/O location.
     *
     * @param pBase		Base address returned by 'mmap'.
     * @param offset	Offset where device is mapped.
     * @return		Value read.
   */
    int RegisterRead(unsigned int reg_offset);
};

#endif//DE1SOCFPGA_DE1SOCFPGA_H

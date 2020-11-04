#ifndef DE1SOCFPGA_BITOPERATIONS_H
#define DE1SOCFPGA_BITOPERATIONS_H

#define SET_BIT(number,n) ((number) |= (1<<(n)))
#define CLEAR_BIT(number,n) ((number) &= ~(1<<(n)))
#define FLIP_BIT(number,n) ((number) ^= (1<<(n)))
#define CHANGE_BIT(number,n,value) (number = (number & ~(1 << n)) | (value << n))
#define GET_BIT(number,n) (!!((number) & (1<<(n))))

#endif//DE1SOCFPGA_BITOPERATIONS_H

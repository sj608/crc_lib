#ifndef CRC_8_H
#define CRC_8_H

#include<stdint.h>

#define LUT_SIZE 256

uint8_t* generate_crc_8_arr(uint8_t crc_polynomial);

#endif // CRC_8_H

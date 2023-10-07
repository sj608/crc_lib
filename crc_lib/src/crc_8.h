#ifndef CRC_8_H
#define CRC_8_H

#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

extern uint8_t crc_8_lut[256];

void generate_crc_8_arr(uint8_t crc_polynomial);
uint8_t check_crc(uint8_t *buff, uint8_t size);
uint8_t get_crc(uint8_t *buff, uint8_t size);

#endif // CRC_8_H

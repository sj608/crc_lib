#include "crc_8.h"

uint8_t crc_8_lut[256];

void generate_crc_8_arr(uint8_t crc_polynomial){
    uint8_t crc;
    for(uint16_t i=0; i<256; i++){
        crc = i;
        for(uint8_t j=0; j<8; j++){
            if(crc & 0x80){
                crc=(crc<<1)^(crc_polynomial);
            }else{
                crc = (crc << 1);
            }
        }
        crc_8_lut[i] = crc;
        printf("%d\n", crc_8_lut[i]);
    }
}

uint8_t check_crc(uint8_t *buff, uint8_t size)
{
    uint8_t crc = 0;
    for(uint8_t indx = 0; indx<size; indx++)
    {
        crc = crc ^ *(buff+indx);
        crc = crc_8_lut[crc];
    }
    if(crc !=0){
        return 1;
    }
    return 0;
}

uint8_t get_crc(uint8_t *buff, uint8_t size){
    uint8_t crc = 0;
    for(uint8_t indx = 0; indx<size; indx++)
    {
        crc = crc ^ *(buff+indx);
        crc = crc_8_lut[crc];
    }
    return crc;
}

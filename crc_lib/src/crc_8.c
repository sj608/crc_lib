#include "crc_8.h"

const uint16_t lut_size = 256;

uint8_t* generate_crc_8_arr(uint8_t crc_polynomial){
    uint8_t *crc_8_lut;
    uint8_t crc;
    crc_8_lut = (uint8_t*)malloc(lut_size*sizeof(uint8_t));
    if(crc_8_lut == NULL){
        return NULL;
    }
    for(uint8_t i=0; i<lut_size; i++){
        crc = i;
        for(uint8_t j=0; j<8; j++){
            if(crc & 0x80){
                crc=(crc<<1)^(crc_polynomial);
            }else{
                crc = (crc << 1);
            }
        }
        *(crc_8_lut+i) = crc;
    }
    return crc_8_lut;
}

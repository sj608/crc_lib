#include "crc_8.h"


uint8_t* generate_crc_8_arr(uint8_t crc_polynomial){
    uint8_t *crc_8_lut;
    uint8_t crc;
    crc_8_lut = (uint8_t*)malloc(LUT_SIZE*sizeof(uint8_t));
    for(uint8_t i=0; i<LUT_SIZE; i++){
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
}

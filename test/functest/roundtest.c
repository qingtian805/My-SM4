#include "sm4kdf.h"
#include "sm4round.h"
#include <stdio.h>

int main(void)
{
    union sm4data key = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210};
    union sm4data data = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210};
    int i;

    _sm4kdf_xorfx_(&key);

    for(i = 0; i < 32; i++){
        _sm4_round_(&data, i, sm4kdf(&key, i));
        printf("X%2d = %x\n",i+4 , data.u32[i & 0x3]);
    }

    return 0;
}
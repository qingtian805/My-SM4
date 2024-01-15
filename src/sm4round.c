#include "sm4round.h"
#include "sm4kdf.h"
#include <stdint.h>

void _sm4_round_(union sm4data *data, union sm4uint32 rk)
{
    int i;
    union sm4uint32 xor[5];

    xor[0].u32 = data->u32[1] ^ data->u32[2] ^ data->u32[3] ^ rk.u32;

    
}
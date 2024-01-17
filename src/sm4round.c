#include "sm4round.h"
#include "sm4kdf.h"
#include <stdint.h>

void _sm4_round_(union sm4data *data, int round, union sm4uint32 rk)
{
    int i;
    union sm4uint32 xor;
    union sm4uint32 res;

    xor.u32 = data->u32[(round + 1) & 0x3] ^ data->u32[(round + 2) & 0x3] ^ data->u32[(round + 3) & 0x3] ^ rk.u32;

    for(i = 0; i < 4; i++)
        xor.u8[i] = sbox(xor.u8[i]);

    res.u32 = _sm4_asm_rol_(xor.u32, 24);
    res.u32 = res.u32 ^ _sm4_asm_rol_(xor.u32, 18);
    res.u32 = res.u32 ^ _sm4_asm_rol_(xor.u32, 10);
    res.u32 = res.u32 ^ _sm4_asm_rol_(xor.u32, 2);
    res.u32 = res.u32 ^ xor.u32;

    data->u32[round & 0x3] = data->u32[round & 0x3] ^ res.u32;
}
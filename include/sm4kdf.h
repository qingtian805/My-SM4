#include "sm4base.h"
#include <stdint.h>

void _sm4kdf_round_(union sm4data *keys, int round);

inline void _sm4kdf_xorfx_(union sm4data *keys)
{
    keys->u32[0] = keys->u32[0] ^ 0xA3B1BAC6;
    keys->u32[1] = keys->u32[1] ^ 0x56AA3350;
    keys->u32[2] = keys->u32[2] ^ 0x677D9197;
    keys->u32[3] = keys->u32[3] ^ 0xB27022DC;
}

inline union sm4uint32 sm4kdf(union sm4data *keys, int round)
{
    _sm4kdf_round_(keys, round);
    return keys->sm4u32[round & 0x3];
}
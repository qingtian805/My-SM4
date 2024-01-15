#include "sm4kdf.h"
#include "sm4base.h"

static const uint32_t CK[32] = {0x00070E15, 0x1C232A31, 0x383F464D, 0x545B6269,
                                0x70777E85, 0x8C939AA1, 0xA8AFB6BD, 0xC4CBD2D9,
                                0xE0E7EEF5, 0xFC030A11, 0x181F262D, 0x343B4249,
                                0x50575E65, 0x6C737A81, 0x888F969D, 0xA4ABB2B9,
                                0xC0C7CED5, 0xDCE3EAF1, 0xF8FF060D, 0x141B2229,
                                0x30373E45, 0x4C535A61, 0x686F767D, 0x848B9299,
                                0xA0A7AEB5, 0xBCC3CAD1, 0xD8DFE6ED, 0xF4FB0209,
                                0x10171E25, 0x2C333A41, 0x484F565D, 0x646B7279};

extern inline void _sm4kdf_xorfx_(union sm4data *keys);

extern inline union sm4uint32 sm4kdf(union sm4data *keys, int round);

void _sm4kdf_round_(union sm4data *keys, int round)
{
    int i;
    union sm4uint32 xor;
    union sm4uint32 res;

    xor.u32 = keys->u32[(round + 1) & 0x3] 
                ^ keys->u32[(round + 2) & 0x3] ^ keys->u32[(round + 3) & 0x3];

    xor.u32 = xor.u32 ^ CK[round];

    for(i = 0; i < 4; i++)
        xor.u8[i] = sbox(xor.u8[i]);

    res.u32 = _sm4_asm_rol_(xor.u32, 23);
    res.u32 = res.u32 ^ _sm4_asm_rol_(xor.u32, 13);
    res.u32 = res.u32 ^ xor.u32;

    keys->u32[round & 0x3] = res.u32 ^ keys->u32[round & 0x3];
}
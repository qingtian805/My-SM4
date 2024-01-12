#include "sm4kdf.h"
#include "sm4base.h"

static const uint32_t FX[4] = {0xA3B1BAC6, 0x56AA3350, 0x677D9197, 0xB27022DC};

static const uint32_t CK[32] = {0x00070E15, 0x1C232A31, 0x383F464D, 0x545B6269,
                                0x70777E85, 0x8C939AA1, 0xA8AFB6BD, 0xC4CBD2D9,
                                0xE0E7EEF5, 0xFC030A11, 0x181F262D, 0x343B4249,
                                0x50575E65, 0x6C737A81, 0x888F969D, 0xA4ABB2B9,
                                0xC0C7CED5, 0xDCE3EAF1, 0xF8FF060D, 0x141B2229,
                                0x30373E45, 0x4C535A61, 0x686F767D, 0x848B9299,
                                0xA0A7AEB5, 0xBCC3CAD1, 0xD8DFE6ED, 0xF4FB0209,
                                0x10171E25, 0x2C333A41, 0x484F565D, 0x646B7279};

union sm4data sm4kdf(union sm4data data)
{
    int round;
    int i;
    union sm4uint32 xor[3];

    for(i = 0; i < 4; i++){
        data.u32[i] = data.u32[i] ^ FX[i];
    }

    for(round = 0; round < 32; round++){
        xor[0].u32 = data.u32[(round + 1) & 0x3] 
                    ^ data.u32[(round + 2) & 0x3] ^ data.u32[(round + 3) & 0x3];

        xor[0].u32 = xor[0].u32 ^ CK[round];

        for(i = 0; i < 4; i++)
            xor[0].u8[i] = sbox(xor[0].u8[i]);

        xor[1].u32 = _sm4_asm_rol_(xor[0].u32, 13);
        xor[2].u32 = _sm4_asm_rol_(xor[0].u32, 23);

        xor[0].u32 = xor[0].u32 ^ xor[1].u32 ^ xor[2].u32;

        data.u32[round & 0x3] = xor[0].u32 ^ data.u32[round & 0x3];
    }

    return data;
}
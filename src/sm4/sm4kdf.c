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

static inline void _sm4kdf_xorfk_(uint32_t *keys, union sm4uint32 *k)
{
    k[0].u32 = keys[0] ^ 0xA3B1BAC6;
    k[1].u32 = keys[1] ^ 0x56AA3350;
    k[2].u32 = keys[2] ^ 0x677D9197;
    k[3].u32 = keys[3] ^ 0xB27022DC;
}

//sm4密钥扩展算法的T'变换
static inline union sm4uint32 _sm4kdf_t_(union sm4uint32 keys)
{
    keys.u8[0] = _SM4_SBOX_[keys.u8[0]];
    keys.u8[1] = _SM4_SBOX_[keys.u8[1]];
    keys.u8[2] = _SM4_SBOX_[keys.u8[2]];
    keys.u8[3] = _SM4_SBOX_[keys.u8[3]];

    keys.u32 ^= _sm4_asm_rol_(keys.u32, 13) ^ _sm4_asm_rol_(keys.u32, 23);
    return keys;
}

void sm4kdf(uint32_t *keys, uint32_t *rk)
{
    int i;
    union sm4uint32 xor;
    union sm4uint32 k[4];
    
    _sm4kdf_xorfk_(keys, k);

    for(i = 0; i < 32; i += 4){
        xor.u32 = k[1].u32 ^ k[2].u32 ^ k[3].u32 ^ CK[i    ];
        k[0].u32 ^= _sm4kdf_t_(xor).u32;

        xor.u32 = k[2].u32 ^ k[3].u32 ^ k[0].u32 ^ CK[i + 1];
        k[1].u32 ^= _sm4kdf_t_(xor).u32;

        xor.u32 = k[3].u32 ^ k[0].u32 ^ k[1].u32 ^ CK[i + 2];
        k[2].u32 ^= _sm4kdf_t_(xor).u32;

        xor.u32 = k[0].u32 ^ k[1].u32 ^ k[2].u32 ^ CK[i + 3];
        k[3].u32 ^= _sm4kdf_t_(xor).u32;

        rk[i    ] = k[0].u32;
        rk[i + 1] = k[1].u32;
        rk[i + 2] = k[2].u32;
        rk[i + 3] = k[3].u32;
    }
}